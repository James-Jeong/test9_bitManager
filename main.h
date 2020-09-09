#ifndef __MAIN_H__
#define __MAIN_H__

///////////////////////////////////////////////////////////////////////////////////////
/// Macros
///////////////////////////////////////////////////////////////////////////////////////

// 바이트 비트 수 
#define NUM_OF_BIT 8

// 함수 실행 결과에 대한 열거형
enum FUNCTION_RESULT
{
	SUCCESS	=	1,	// 성공
	FAIL	=	-1	// 실패
};

// 설정할 값의 최소, 최대값에 대한 열거형
enum VALUE_RANGE
{
	MIN_VALUE =	0,	// 최소값
	MAX_VALUE =	1	// 최대값
};

///////////////////////////////////////////////////////////////////////////////////////
/// Local functions
///////////////////////////////////////////////////////////////////////////////////////

void setBit(unsigned char *flag, int bit, int value);
int getBit(unsigned const char *flag, int bit);
void toggleBit(unsigned char *flag, int bit);
void splitWordToBytes(unsigned short value, unsigned char *high, unsigned char *low);
void mergeBytesToWord(unsigned const char *high, unsigned const char *low, unsigned short *value);
void printUnsigned16bitsNumberToBinary(unsigned short value);

#endif // #ifndef __MAIN_H__

