#pragma once
/* author: gaogao
 * date: 2019.01.09
 *description : 网络连接封装实现
*/

#ifndef CSOCKET_H
#define CSOCKET_H

#include <stdio.h>
#include <netinet/in.h>
#include "base/Type.h"

//using namespace NConnect
//{
	class CSocket
	{
	public:
		CSocket();
		CSocket(const char* ip, const unsigned int port);
		virtual ~CSocket();
	public:
		static const char* toIpStr(const struct in_addr& ip);
		static unsigned int toIpInt(const char* ip);
		static int toIpAddr(const char* isStr, struct in_addr& ipInaddr);
		static int getOpt(int sockfd, int level, int optname, void* optval, sockLen_t* optlen);

	public:
		int init(const char* ip, const unsigned short port);
		void unInit();

	public:
		int open(int type);   // type: tcp or udp
		int open(int family, int type, int protocol);
		int close();

	public:
		int bind();
		int listen(int num);

	public:
		int connect(int &errorCode);

	public:
		int setLinger(int onOff, int val);   // 慎用该选项
		int setRcvBuff(int val);			 // 接受缓冲区的大小，在connect&listen操作之前设置
		int setSndBuff(int val);			 // 发送缓冲区的大小，在connect&listen操作之前设置
		int setReuseAddr(int val);			 // 地址重用，在bind之前调用
		int setNagle(int val);				 // Nagle算法
		int setNoBlock();					 // 设置为非阻塞模式
		int setNoBlock(int fd);				 // 设置为非阻塞模式

	public:
		int getFd() const;
		const char* getIp() const;
		unsigned short getPort() const;

	private:
		// 禁止拷贝、 赋值
		CSocket(const CSocket&);
		CSocket& operator =(const CSocket&);

	protected:
		// 禁止拷贝、 赋值
		strIp_t m_ip;
		unsigned short m_port;
		int m_fd;


	};
//}
#endif