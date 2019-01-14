#pragma once
#ifndef ERROR_CODE_H
#define ERROR_CODE_H

namespace NErrorCode
{
// ����ģ�� �����뷶Χ[0 ---100]
	enum ECommon
	{
		Success = 0,				// ���óɹ�

		InvalidParam = 1,			// ������Ч
		NoMemory = 2,				// new ʧ�ܣ�û�ڴ���

		QueueFull = 3,				// ��Ϣ��������
		systenCallErr =4,           // ϵͳ����ʧ��
    };


// ��������ģ�� �����뷶Χ[121---150]
	enum EConnect
	{
		CreateSocketFailed = 121,   // ����socketʧ��
		CloseSocketFailed = 122,    // �ر�socketʧ��
		InValidIp = 123,			// ��Чip��ַ
		BindIpPortFailed = 124,     // ��Чip��ַ
		ListenConnectFailed = 125,  // ������������ʧ��
		ConnectIpPortFailed = 126,  // ������������ʧ��
		SetLingerFailed = 127,		// ѡ������ʧ��
		SetRevBuffFailed = 128,     // ѡ������ʧ��
		SetSndBuffFailed = 129,     // ѡ������ʧ��
		SetReuseAddrFailed = 130,   // ѡ������ʧ��
		SetNagleFailed = 131,       // ѡ������ʧ��
		SetNoBlockFailed =132,		// ѡ������ʧ��
		AcceptConnectFailed = 133,  // ��������ʧ��
	};
}
#endif // !ERROR_CODE_H
