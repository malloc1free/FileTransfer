/* author : gaogao
 * date : 2019.01.14
 * description : epoll模型API封装实现
 */

#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/epoll.h>

#include "CEpoll.h"
#include "base/MacroDefine.h"
#include "base/ErrorCode.h"


//using namespace NCommon;
using namespace NErrorCode;



CEpoll::CEpoll() : m_epfd(-1)
{
}

CEpoll::~CEpoll()
{
	destory();
}

int CEpoll::create(int listenCount)
{
	//创建epoll
	if (listenCount < 1) {
		return InvalidParam;
	}

	int epfd = ::epoll_create(listenCount);
	if (epfe == -1) {
		printf("create epoll error = %d, info = %s", errno, strerror(errno));
		return CreateEPollFailed;
	}

	m_epfd = epfd;
	return Success;
}

void CEpoll::destory()
{
	if (m_epfd != -1)
	{
		if(::close(m_epfd) != 0)
		{
			printf("close epoll error = %d, info = %s", errno, strerror(errno));
		}
		m_epfd = -1;
	}
}

int CEpoll::listen(epoll_event * waitEvents, const int maxEvents, const int waitTimeout)
{
	//等待epoll事件的发生，一次无法输出全部事件，下次继续输出，因此事件不会丢失
	int num = epoll_wait(m_epfd, waitEvents, maxEvents, waitTimeout);
	if (num == -1) {
		printf("epoll wait listen error = %d, info = %s", errno, strerror(errno));
	}
	return num;
}

int CEpoll::addListener(int fd, epoll_event & optEv)
{
	if (::epoll_ctl(m_epfd, EPOLL_CTL_ADD, fd, &optEv) == -1)
	{
		printf("add listener to epoll error = %d, info = %s", errno, strerror(errno));
		return AddEPollListenerFailed;
	}
	return Success;
}

int CEpoll::modifyListenEvent(int fd, struct epoll_event& optEv)
{
	if (::epoll_ctl(m_epfd, EPOLL_CTL_MOD, fd, &optEv) == -1)
	{
		printf("modify listen event in epoll error = %d, info = %s", errno, strerror(errno));
		return ModifyEPollListenerFailed;
	}
	return Success;
}

int CEpoll::removeListener(int fd)
{
	struct epoll_event optEv;
	optEv.data.ptr = NULL;
	optEv.events = 0;
	if (::epoll_ctl(m_epfd, EPOLL_CTL_DEL, fd, &optEv) == -1)  // 删除监听
	{
		printf("remove listener from epoll error = %d, info = %s", errno, strerror(errno));
		return RemoveEPollListenerFailed;
	}
	return Success;
