/*
 ============================================================================
 Name        : FifoBuff.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "FifoBuff.h"
static long FifoAddByte(struct FifoBuff_n *This,unsigned char dat)
{
	if((This->Var->FifoWrite+1)!=This->Var->FifoRead)
	{
		This->Var->Buff[This->Var->FifoWrite]=dat;
		This->Var->FifoWrite=(This->Var->FifoWrite+1)%This->Var->BuffLength;
		return 1;
	}
	return 0;
}
static long FifoGetByte(struct FifoBuff_n *This,unsigned char *dat)
{
	dat[0]=This->Var->Buff[This->Var->FifoRead];
	if(This->Var->FifoWrite!=This->Var->FifoRead)
	{
		This->Var->FifoRead=(This->Var->FifoRead+1)%This->Var->BuffLength;
		return 1;
	}
	return 0;
}
static long FifoList(struct FifoBuff_n *This,unsigned short length,unsigned char *out)
{
	unsigned short i=length;
	for(unsigned short ReadSp=This->Var->FifoRead;i>0;i--)
	{
		out[length-i]=This->Var->Buff[ReadSp];

		if(This->Var->FifoWrite==ReadSp)
		{
			return length-i;
		}
		ReadSp=(ReadSp+1)%This->Var->BuffLength;
	}
	return length-i;
}
static long FifoAddArrayByte(struct FifoBuff_n *This,unsigned char *dat,unsigned short length)
{
	for(unsigned short i=0;i<length;i++)
	{
		if(FifoAddByte(This,dat[i])==0)
			return i;
	}
	return length;
}
static long FifoGetArrayByte(struct FifoBuff_n *This,unsigned short length,unsigned char *out)
{
	for(unsigned short i=0;i<length;i++)
	{
		if(FifoGetByte(This,out+i)==0)
			return i;
	}
	return length;
}
static long FifoGetFreeSpace(struct FifoBuff_n *This)
{
	long ret=This->Var->BuffLength-(((This->Var->BuffLength+This->Var->FifoWrite)-This->Var->FifoRead)%This->Var->BuffLength)-1;//(((This->Var->BuffLength+))%This->Var->BuffLength;
	return ret;
}

FifoBuff_t* FifoInit(FifoBuff_t *This,unsigned char *buff,unsigned short length)
{
	This->Var->Buff=buff;
	This->Var->BuffLength=length;
	This->FifoGetArrayByte=FifoGetArrayByte;
	This->FifoAddArrayByte=FifoAddArrayByte;
	This->FifoGetFreeSpace=FifoGetFreeSpace;
	This->FifoList=FifoList;
	return This;

}
#if 0
FifoBuff_t FifoBuff[1];
unsigned char m_FifoBuff[101];
unsigned char m_FifoOut[101];
int main(void) {
	FifoInit(FifoBuff,m_FifoBuff,sizeof(m_FifoBuff));
	printf("\r\nFifoGetFreeSpace:%ld",FifoGetFreeSpace(FifoBuff));
	FifoBuff->FifoAddArrayByte(FifoBuff,"hello6",6);
	printf("\r\nFifoGetFreeSpace:%ld",FifoGetFreeSpace(FifoBuff));
	long ret=FifoBuff->FifoList(FifoBuff,7,m_FifoOut);
	printf("\r\nFifoList:%ld\r\n",ret);
	for(int i=0;i<ret;i++)
	{
		printf("%c",m_FifoOut[i]);

	}
	ret=FifoBuff->FifoGetArrayByte(FifoBuff,5,m_FifoOut);
	printf("\r\nFifoGetArrayByte:%ld\r\n",ret);
	for(int i=0;i<ret;i++)
	{
		printf("%c",m_FifoOut[i]);

	}
	unsigned char buff[101];
	ret=FifoBuff->FifoAddArrayByte(FifoBuff,buff,101);


	printf("\r\nFifoAddlen:%ld\r\n",ret);
	printf("\r\nFifoGetFreeSpace:%ld",FifoGetFreeSpace(FifoBuff));
	ret=FifoBuff->FifoGetArrayByte(FifoBuff,100,m_FifoOut);
	printf("\r\nFifoGetArrayByte:%ld\r\n",ret);
	for(int i=0;i<ret;i++)
	{
		printf("%02x",m_FifoOut[i]);

	}
	printf("\r\nFifoWrite:%d",FifoBuff->Var->FifoWrite);
	printf("\r\nFifoRead:%d",FifoBuff->Var->FifoRead);
	printf("\r\nFifoGetFreeSpace:%ld",FifoGetFreeSpace(FifoBuff));
	FifoBuff->FifoAddArrayByte(FifoBuff,"hello",5);
	printf("FifoGetFreeSpace:%ld",FifoGetFreeSpace(FifoBuff));
	ret=FifoBuff->FifoGetArrayByte(FifoBuff,5,m_FifoOut);
	for(int i=0;i<ret;i++)
	{
		printf("%c",m_FifoOut[i]);

	}
	return EXIT_SUCCESS;
}
#endif
