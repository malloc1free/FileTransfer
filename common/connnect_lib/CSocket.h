#pragma once
/* author: gaogao
 * date: 2019.01.09
 *description : �������ӷ�װʵ��
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
		int setLinger(int onOff, int val);   // ���ø�ѡ��
		int setRcvBuff(int val);			 // ���ܻ������Ĵ�С����connect&listen����֮ǰ����
		int setSndBuff(int val);			 // ���ͻ������Ĵ�С����connect&listen����֮ǰ����
		int setReuseAddr(int val);			 // ��ַ���ã���bind֮ǰ����
		int setNagle(int val);				 // Nagle�㷨
		int setNoBlock();					 // ����Ϊ������ģʽ
		int setNoBlock(int fd);				 // ����Ϊ������ģʽ

	public:
		int getFd() const;
		const char* getIp() const;
		unsigned short getPort() const;

	private:
		// ��ֹ������ ��ֵ
		CSocket(const CSocket&);
		CSocket& operator =(const CSocket&);

	protected:
		// ��ֹ������ ��ֵ
		strIp_t m_ip;
		unsigned short m_port;
		int m_fd;


	};
//}
#endif