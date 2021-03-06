


#ifndef __PSLOGFILTER_H__
#define __PSLOGFILTER_H__


/******************************************************************************
  1 其他头文件包含
******************************************************************************/
#include "vos.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)


/******************************************************************************
  2 宏定义
******************************************************************************/
#if (OSA_CPU_CCPU == VOS_OSA_CPU)

#define PS_OM_LAYER_MSG_MATCH_ITEM_MAX_CNT  (4)

#endif
/******************************************************************************
  3 枚举定义
******************************************************************************/


/******************************************************************************
  4 全局变量声明
******************************************************************************/


/******************************************************************************
  5 消息头定义
******************************************************************************/


/******************************************************************************
  6 消息定义
******************************************************************************/


/******************************************************************************
  7 STRUCT定义
******************************************************************************/
#if (OSA_CPU_CCPU == VOS_OSA_CPU)

/*****************************************************************************
 结构名    : PS_OM_LAYER_MSG_MATCH_PFUNC
 协议表格  :
 ASN.1描述 :
 结构说明  : MsgMatch回调函数指针
             此回调函数规则:
             1.如果注册回调内部没有对消息进行处理，则需要将入参指针返回，否则
               本模块不知道是否需要将此消息传递给下一个注册回调进行处理
             2.如果注册回调内部对消息进行了处理，则返回值能够实现两个功能:
               ①返回VOS_NULL，则将此消息进行完全过滤，不会再勾取出来
               ②返回与入参指针不同的另一个指针，则勾取的消息将会使用返回的指
                 针内容替换原消息的内容。另本模块不负责对替换的内存进行释放，
                 替换原消息使用的内存请各模块自行管理。
*****************************************************************************/
typedef VOS_VOID * (*PS_OM_LAYER_MSG_MATCH_PFUNC)(MsgBlock *pstMsg);

/*****************************************************************************
 结构名    : PS_OM_LAYER_MSG_MATCH_CTRL_STRU
 协议表格  :
 ASN.1描述 :
 结构说明  : MsgMatch功能的控制结构
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulRegCnt;
    PS_OM_LAYER_MSG_MATCH_PFUNC         apfuncMatchEntry[PS_OM_LAYER_MSG_MATCH_ITEM_MAX_CNT];
}PS_OM_LAYER_MSG_MATCH_CTRL_STRU;

#endif
/******************************************************************************
  8 UNION定义
******************************************************************************/


/******************************************************************************
  9 OTHERS定义
******************************************************************************/
#if (OSA_CPU_CCPU == VOS_OSA_CPU)

/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgMatchInit_Ccpu
 功能描述  : 初始化MsgMatch
 输入参数  : VOS_VOID
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年9月3日
    作    者   : z00311339
    修改内容   : 新生成函数

*****************************************************************************/
VOS_VOID PS_OM_LayerMsgMatchInit(VOS_VOID);

/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgMatchFuncReg_Ccpu
 功能描述  : 注册MsgMatch回调接口
 输入参数  : PS_OM_LAYER_MSG_MATCH_PFUNC          pFunc
             输入参数回调接口规则:
             1.如果注册回调内部没有对消息进行处理，则需要将入参指针返回，否则
               本模块不知道是否需要将此消息传递给下一个注册回调进行处理
             2.如果注册回调内部对消息进行了处理，则返回值能够实现两个功能:
               ①返回VOS_NULL，则将此消息进行完全过滤，不会再勾取出来
               ②返回与入参指针不同的另一个指针，则勾取的消息将会使用返回的指
                 针内容替换原消息的内容。另本模块不负责对替换的内存进行释放，
                 替换原消息使用的内存请各模块自行管理。
 输出参数  : 无
 返 回 值  : VOS_VOID
 调用函数  :
 被调函数  :

 修改历史      :
  1.日    期   : 2016年9月5日
    作    者   : z00311339
    修改内容   : 新生成函数

*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgMatchFuncReg
(
    PS_OM_LAYER_MSG_MATCH_PFUNC         pFunc
);

/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgFilter_Ccpu
 功能描述  : 用于向DIAG组件进行注册的公共的LOG过滤函数
             其他组件可将自己的过滤函数添加至本函数内，
             统一向DIAG组件进行注册
 输入参数  : const VOID *pMsg:消息指针
 输出参数  : 无
 返 回 值  : VOS_UINT32:
                返回VOS_TRUE:  表示该消息需要进行过滤
                返回VOS_FALSE: 表示该消息无需进行过滤
 调用函数  :
 被调函数  :
 修改历史      :
  1.日    期   : 2015年09月28日
    作    者   : h00313353
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgFilter_Ccpu(
    const VOS_VOID                      *pMsg
);
#endif

#if (OSA_CPU_ACPU == VOS_OSA_CPU)
/*****************************************************************************
 函 数 名  : PS_OM_LayerMsgFilter_Acpu
 功能描述  : 用于向DIAG组件进行注册的公共的LOG过滤函数
             其他组件可将自己的过滤函数添加至本函数内，
             统一向DIAG组件进行注册
             (本函数在A核任务中注册，用于过滤A核内部层间消息)
 输入参数  : const VOID *pMsg:消息指针
 输出参数  : 无
 返 回 值  : VOS_UINT32:
                返回VOS_TRUE:  表示该消息需要进行过滤
                返回VOS_FALSE: 表示该消息无需进行过滤
 调用函数  :
 被调函数  :
 修改历史      :
  1.日    期   : 2015年09月28日
    作    者   : h00313353
    修改内容   : 新生成函数
*****************************************************************************/
VOS_UINT32 PS_OM_LayerMsgFilter_Acpu(
    const VOS_VOID                      *pMsg
);
#endif

#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* PsLogFilter.h */


