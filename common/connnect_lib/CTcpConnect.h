#pragma once
/* auther : gaogao
*  date : 2019.01.14
* desscription: TCP连接相关实现
*/

#ifndef CTCPCONNECT_H
#define CTCPCONNECT_T

#include "CSocket.h"

struct addr_in;

class CTcpConnect : public CSocket
{
public:
	CTcpConnect(const char* ip, const int port);
	~CTcpConnect();

public:
	int create(int linstenNum);
	void destroy();
	bool isNormal();

public:
	int accetp(int& fd, in_addr& peerIp, unsigned short& peerPort, int& errorCode);

private:
	bool m_isNormal;
};

#endif