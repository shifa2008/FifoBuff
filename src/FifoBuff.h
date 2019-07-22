/*
 * FifoBuff.h
 *
 *  Created on: 2019��7��9��
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
    long (*FifoGetArrayByte)(struct FifoBuff_n *This,unsigned short length,unsigned char *out); //���ָ�����ȵ��������û����ô�෵��ȫ��ֱ��ָ��Ϊ0xffffΪ��ȡ����
    long (*FifoAddArrayByte)(struct FifoBuff_n *This,unsigned char *dat,unsigned short length); //���ָ�����ȵ����ݵ�������������пռ䲻����������ӵĸ���
    long (*FifoGetFreeSpace)(struct FifoBuff_n *This);                                          //�õ�����ʣ��ռ�
    long (*FifoList)(struct FifoBuff_n *This,unsigned short length,unsigned char *out);
}FifoBuff_t;
FifoBuff_t* FifoInit(FifoBuff_t *This,unsigned char *buff,unsigned short length);

#endif /* FIFOBUFF_H_ */
