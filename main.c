#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////////////
/// Macros
///////////////////////////////////////////////////////////////////////////////////////

// 바이트 비트 수 
#define BYTE_BIT_NUM 8
// 함수 실행 성공
#define SUCCESS 1
// 함수 실행 실패
#define FAIL 0

///////////////////////////////////////////////////////////////////////////////////////
/// Predefinitions of Local Static function
///////////////////////////////////////////////////////////////////////////////////////

static int checkBitRange(int bit);

///////////////////////////////////////////////////////////////////////////////////////
/// Predefinitions of Local functions
///////////////////////////////////////////////////////////////////////////////////////

void setBit(unsigned char *flag, int bit, int value);
int getBit(unsigned const char *flag, int bit);
void toggleBit(unsigned char *flag, int bit);
void splitWordToBytes(unsigned const short value, unsigned char *high, unsigned char *low);
void mergeBytesToWord(unsigned const char *high, unsigned const char *low, unsigned short *value);
void printUnsigned8bitsNumberToBinary(unsigned short value);

///////////////////////////////////////////////////////////////////////////////////////
/// Main function
///////////////////////////////////////////////////////////////////////////////////////

/**
 * @fn int main()
 * @brief 바이트 정수 관리 API 테스트 프로그램
 * 8 비트 값의 특정 비트에 0 과 1 만 저장할 수 있다.
 * @return SUCCESS 반환
 */
int main()
{
	printf("[바이트 정수 관리 API 테스트 프로그램]\n\n");
	unsigned char flag = 0x0A;
	printf("최초 flag 에 %x(hex) 저장\n", flag);
	printUnsigned8bitsNumberToBinary(flag);

	printf("\n[getBit test]\n");
	int result = 0;
	printf("0 번째 비트 값 읽기\n");
	result = getBit(&flag, 0);
	if(result != FAIL) printf("getBit : %d\n", result);
	else printf("읽기 실패. (getBit(0))");

	printf("5 번째 비트 값 읽기\n");
	result = getBit(&flag, 5);
	if(result != FAIL) printf("getBit : %d\n", result);
	else printf("읽기 실패. (getBit(5))");

	printf("-5 번째 비트 값 읽기\n");
	result = getBit(&flag, -5);
	if(result != FAIL) printf("getBit : %d\n", result);
	else printf("읽기 실패. (getBit(-5))");

	printf("10 번째 비트 값 읽기\n");
	result = getBit(&flag, 10);
	if(result != FAIL) printf("getBit : %d\n", result);
	else printf("읽기 실패. (getBit(10))");

	printf("\n[setBit test]\n");
	printf("5 번째 비트에 1 을 쓰기\n");
	setBit(&flag, 5, 1);
	printUnsigned8bitsNumberToBinary(flag);
	printf("-5 번째 비트에 1 을 쓰기\n");
	setBit(&flag, -5, 1);
	printf("10 번째 비트에 1 을 쓰기\n");
	setBit(&flag, 10, 1);
	printf("1 번째 비트에 10 을 쓰기\n");
	setBit(&flag, 1, 10);
	printf("6 번째 비트에 1 을 쓰기\n");
	setBit(&flag, 6, 1);
	printUnsigned8bitsNumberToBinary(flag);

	printf("\n[toggleBit test]\n");
	printf("1 번째 비트 토글하기\n");
	toggleBit(&flag, 1);
	printUnsigned8bitsNumberToBinary(flag);
	printf("3 번째 비트 토글하기\n");
	toggleBit(&flag, 3);
	printUnsigned8bitsNumberToBinary(flag);
	printf("10 번째 비트 토글하기\n");
	toggleBit(&flag, 10);
	printf("1 번째 비트 토글하기\n");
	toggleBit(&flag, 1);
	printUnsigned8bitsNumberToBinary(flag);

	printf("\n[splitWordToBytes test]\n");
	unsigned char high = 0x00;
	unsigned char low = 0x00;
	unsigned short value = 0xFF;
	splitWordToBytes(value, &high, &low);
	printf("high : %x, low : %x\n", high, low);
	printUnsigned8bitsNumberToBinary(high);
	printUnsigned8bitsNumberToBinary(low);

	printf("\n[mergeBytesToWord test]\n");
	mergeBytesToWord(&high, &low, &value);
	printf("high : %x, low : %x, value : %x\n", high, low, value);
	printUnsigned8bitsNumberToBinary(high);
	printUnsigned8bitsNumberToBinary(low);
	printUnsigned8bitsNumberToBinary(value);

	printf("\n[프로그램 종료]\n");
	return SUCCESS;
}

///////////////////////////////////////////////////////////////////////////////////////
/// Local functions
///////////////////////////////////////////////////////////////////////////////////////

/**
 * @fn void setBit(unsigned char *flag, int bit, int value)
 * @brief 8 비트 값의 특정 비트 값을 원하는 값으로 설정하는 함수
 * @param flag 8 비트 값(출력)
 * @param bit 지정할 비트(입력)
 * @param value 설정할 값(입력)
 * @return 반환값 없음
 */
void setBit(unsigned char *flag, int bit, int value)
{
	if(flag == NULL)
	{
		printf("flag 참조 실패. NULL.\n");
		return;
	}

	if(checkBitRange(bit) == FAIL)
	{
		return;
	}

	if(value != 0 && value != 1)
	{
		printf("잘못된 값 입력. 설정하려는 값이 범위를 벗어남. (range:0~1)\n");
		return;
	}

	unsigned int mask = 0x00;
	if(value == 1) mask = 0x01;
	mask <<= bit;

	*flag |= (unsigned char)mask;
}

/**
 * @fn int getBit(unsigned const char *flag, int bit)
 * @brief 8 비트 값의 특정 비트 값을 반환하는 함수
 * @param flag 8 비트 값(입력, 읽기 전용)
 * @param bit 지정할 비트(입력)
 * @return 성공 시 특정 비트 값, 실패 시 FAIL 반환
 */
int getBit(unsigned const char *flag, int bit)
{
	if(flag == NULL)
	{
		printf("flag 참조 실패. NULL.\n");
		return FAIL;
	}

	if(checkBitRange(bit) == FAIL)
	{
		return FAIL;
	}

	unsigned int mask = 0x01;
	mask <<= bit;

	unsigned int value = *flag & mask;
	return (int)(value >> bit);
}

/**
 * @fn void toggleBit(unsigned char *flag, int bit)
 * @brief 8 비트 값의 특정 비트 값을 확인해서 0 이면 1, 1 이면 0 으로 바꾸는 함수
 * @param flag 8 비트 값(출력)
 * @param bit 지정할 비트(입력)
 * @return 반환값 없음
 */
void toggleBit(unsigned char *flag, int bit)
{
	if(flag == NULL)
	{
		printf("flag 참조 실패. NULL.\n");
		return;
	}

	if(checkBitRange(bit) == FAIL)
	{
		return;
	}

	unsigned int mask = 0x01;
	mask <<= bit;
	*flag ^= (unsigned char)mask;
}

/**
 * @fn void splitWordToBytes(unsigned const short value, unsigned char *high, unsigned char *low)
 * @brief 16 비트 값을 상위 8 비트, 하위 8 비트 값으로 분리하여 반환하는 함수
 * @param value 분리될 16 비트 값(입력, 읽기 전용)
 * @param high 상위 8 비트 값(출력)
 * @param low 하위 8 비트 값(출력)
 * @return 반환값 없음
 */
void splitWordToBytes(unsigned const short value, unsigned char *high, unsigned char *low)
{
	if(high == NULL || low == NULL)
	{
		printf("flag 참조 실패. NULL. (high:%p, low:%p)\n", high, low);
		return;
	}

	unsigned char highMask = 0xF0;
	unsigned char lowMask = 0x0F;

	*high = (unsigned char)value & highMask;
	*low = (unsigned char)value & lowMask;
}

/**
 * @fn void mergeBytesToWord(unsigned const char *high, unsigned const char *low, unsigned short *value)
 * @brief 8 비트 값 두 개를 입력 받아 16 비트 값으로 변환하여 반환하는 함수
 * @param high 상위 8 비트 값(입력, 읽기 전용)
 * @param low 하위 8 비트 값(입력, 읽기 전용)
 * @param value 변환된 16 비트 값(출력)
 * @return 반환값 없음
 */
void mergeBytesToWord(unsigned const char *high, unsigned const char *low, unsigned short *value)
{
	if(high == NULL || low == NULL || value == NULL)
	{
		printf("flag 참조 실패. NULL. (high:%p, low:%p, value:%p)\n", high, low, value);
		return;
	}

	*value = 0x0000;
	*value = (unsigned char)(*value) | *high;
	*value = (unsigned char)(*value) | *low;
}

/**
 * @fn void printUnsigned8bitsNumberToBinary(unsigned const char value)
 * @brief 부호 없는 8 비트 정수를 이진수로 출력하는 함수
 * @param number 입력받을 정수(입력)
 * @return 반환값 없음
 */
void printUnsigned8bitsNumberToBinary(unsigned short value)
{
    unsigned int mask = 0x80;
    int loopIndex = 1;

    printf("Binary : ");
    for( ; loopIndex <= BYTE_BIT_NUM; loopIndex++)
    {
        printf("%c", (value & mask) == 0 ? '0' : '1');
        if(loopIndex % 4 == 0) printf(" ");
        mask >>= 1;
    }
    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////////////
/// Local Static function
///////////////////////////////////////////////////////////////////////////////////////

/**
 * @fn static int checkBitRange(int bit)
 * @brief 비트값이 1 바이트 범위(0~7)에 속하는지 검사하는 함수
 * @param bit 검사할 비트값
 * @return 성공 시 SUCCESS, 실패 시 FAIL 반환
 */
static int checkBitRange(int bit)
{
	if(bit < 0 || bit > 7)
	{
		printf("잘못된 Bit 입력. Bit 범위를 벗어남. (range:0~%d)\n", BYTE_BIT_NUM - 1);
		return FAIL;
	}

	return SUCCESS;
}

