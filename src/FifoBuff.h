/*
 * FifoBuff.h
 *
 *  Created on: 2019年7月9日
 *      Author: 12123
 */

#ifndef FIFOBUFF_H_
#define FIFOBUFF_H_
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    unsigned char  *Buff;
    unsigned short FifoWrite;
    unsigned short FifoRead;
    unsigned short BuffLength;
}FifoVar_t;
typedef struct FifoBuff_n{
    FifoVar_t Var[1];
    long (*FifoGetArrayByte)(struct FifoBuff_n *This,unsigned short length,unsigned char *out); //获得指定长度的数据如果没有这么多返回全部直接指定为0xffff为读取所有
    long (*FifoAddArrayByte)(struct FifoBuff_n *This,unsigned char *dat,unsigned short length); //添加指定长度的数据到队列中如果队列空间不够返回已添加的个数
    long (*FifoGetFreeSpace)(struct FifoBuff_n *This);                                          //得到还有剩余空间
    long (*FifoList)(struct FifoBuff_n *This,unsigned short length,unsigned char *out);
}FifoBuff_t;
FifoBuff_t* FifoInit(FifoBuff_t *This,unsigned char *buff,unsigned short length);

#endif /* FIFOBUFF_H_ */
