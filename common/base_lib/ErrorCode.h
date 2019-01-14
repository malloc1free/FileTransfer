#pragma once
#ifndef ERROR_CODE_H
#define ERROR_CODE_H

namespace NErrorCode
{
// 公共模块 错误码范围[0 ---100]
	enum ECommon
	{
		Success = 0,	            // 调用成功
		InvalidParam = 1,	    // 参数无效
		NoMemory = 2,		    // new 失败，没内存了
		QueueFull = 3,	            // 消息队列满了
		systenCallErr =4,           // 系统调用失败
    };


// 网络连接模块 错误码范围[121---150]
	enum EConnect
	{
		CreateSocketFailed = 121,   // 创建socket失败
		CloseSocketFailed = 122,    // 关闭socket失败
		InValidIp = 123,	    // 无效ip地址
		BindIpPortFailed = 124,     // 无效ip地址
		ListenConnectFailed = 125,  // 启动监听连接失败
		ConnectIpPortFailed = 126,  // 启动监听连接失败
		SetLingerFailed = 127,	    // 选项设置失败
		SetRevBuffFailed = 128,     // 选项设置失败
		SetSndBuffFailed = 129,     // 选项设置失败
		SetReuseAddrFailed = 130,   // 选项设置失败
		SetNagleFailed = 131,       // 选项设置失败
		SetNoBlockFailed =132,	    // 选项设置失败
		AcceptConnectFailed = 133,  // 建立连接失败
	};
}
#endif // !ERROR_CODE_H
