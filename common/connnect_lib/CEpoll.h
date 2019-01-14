#pragma once
/* auther : gaogao
* date : 2019.01.14
* description : epollģ��API��װʵ��
*/

#ifndef EPOLL_H
#define EPOLL_H

struct epoll_event;

class CEpoll
{
public:
	CEpoll();
	~CEpoll();

public:
	int create(int listenCount);
	void destory();
	int listen(struct epoll_event* waitEvents, const int maxEvents, const int waitTimeout);
	int addListener(int fd, struct epoll_event& optEv);
	int modifyListenEvent(int fd, struct epoll_event& optEv);
	int removeListener(int fd);

private:
	//��ֹ��������ֵ
	CEpoll(const CEpoll&);
	CEpoll& operator =(const CEpoll&);
private:
	int m_epfd;	
};
#endif // !EPOLL_H
