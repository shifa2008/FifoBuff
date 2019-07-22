#include "FifoBuff.h"
#if 1
FifoBuff_t FifoBuff[1];
unsigned char m_FifoBuff[101];
unsigned char m_FifoOut[101];
int main(void) {
	FifoInit(FifoBuff,m_FifoBuff,sizeof(m_FifoBuff));
	printf("\r\nFifoGetFreeSpace:%ld",FifoBuff->FifoGetFreeSpace(FifoBuff));
	FifoBuff->FifoAddArrayByte(FifoBuff,"hello6",6);
	printf("\r\nFifoGetFreeSpace:%ld",FifoBuff->FifoGetFreeSpace(FifoBuff));
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
	printf("\r\nFifoGetFreeSpace:%ld",FifoBuff->FifoGetFreeSpace(FifoBuff));
	ret=FifoBuff->FifoGetArrayByte(FifoBuff,100,m_FifoOut);
	printf("\r\nFifoGetArrayByte:%ld\r\n",ret);
	for(int i=0;i<ret;i++)
	{
		printf("%02x",m_FifoOut[i]);

	}
	printf("\r\nFifoWrite:%d",FifoBuff->Var->FifoWrite);
	printf("\r\nFifoRead:%d",FifoBuff->Var->FifoRead);
	printf("\r\nFifoGetFreeSpace:%ld",FifoBuff->FifoGetFreeSpace(FifoBuff));
	FifoBuff->FifoAddArrayByte(FifoBuff,"hello",5);
	printf("FifoGetFreeSpace:%ld",FifoBuff->FifoGetFreeSpace(FifoBuff));
	ret=FifoBuff->FifoGetArrayByte(FifoBuff,5,m_FifoOut);
	for(int i=0;i<ret;i++)
	{
		printf("%c",m_FifoOut[i]);

	}
	return EXIT_SUCCESS;
}
#endif
