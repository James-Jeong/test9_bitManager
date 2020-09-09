#include <stdio.h>
#include "main.h"

///////////////////////////////////////////////////////////////////////////////////////
/// Predefinitions of Local Static functions
///////////////////////////////////////////////////////////////////////////////////////

static int checkBitRange(int bit);
static int checkValueRange(int value);

///////////////////////////////////////////////////////////////////////////////////////
/// Main function
///////////////////////////////////////////////////////////////////////////////////////

/**
 * @fn int main()
 * @brief 바이트 정수 관리 API 테스트 프로그램
 * 8 비트 값의 특정 비트에 0 과 1 만 저장할 수 있다.
 * @return SUCCESS 반환
 */
/*int main()
{
	printf("[바이트 정수 관리 API 테스트 프로그램]\n\n");

	unsigned char flag = 0x0A;
	printf("최초 flag 에 0x%02X(hex) 저장\n", flag);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n-------\n");
	printf("[getBit test]\n");
	int result = 0;
	printf("0 번째 비트 값 읽기\n");
	result = getBit(&flag, 0);
	if(result != FAIL) printf("getBit : %d\n", result);
	else printf("읽기 실패. (getBit(0))\n");

	printf("\n5 번째 비트 값 읽기\n");
	result = getBit(&flag, 5);
	if(result != FAIL) printf("getBit : %d\n", result);
	else printf("읽기 실패. (getBit(5))\n");

	printf("\n-5 번째 비트 값 읽기\n");
	result = getBit(&flag, -5);
	if(result != FAIL) printf("getBit : %d\n", result);
	else printf("읽기 실패. (getBit(-5))\n");

	printf("\n10 번째 비트 값 읽기\n");
	result = getBit(&flag, 10);
	if(result != FAIL) printf("getBit : %d\n", result);
	else printf("읽기 실패. (getBit(10))\n");

	printf("\n3 번째 비트 값 읽기\n");
	result = getBit(&flag, 3);
	if(result != FAIL) printf("getBit : %d\n", result);
	else printf("읽기 실패. (getBit(3))\n");

	printf("\n-------\n");
	printf("[setBit test]\n");
	printf("5 번째 비트에 1 을 쓰기\n");
	printUnsigned16bitsNumberToBinary(flag);
	setBit(&flag, 5, 1);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n5 번째 비트에 0 을 쓰기\n");
	printUnsigned16bitsNumberToBinary(flag);
	setBit(&flag, 5, 0);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n-5 번째 비트에 1 을 쓰기\n");
	printUnsigned16bitsNumberToBinary(flag);
	setBit(&flag, -5, 1);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n10 번째 비트에 1 을 쓰기\n");
	printUnsigned16bitsNumberToBinary(flag);
	setBit(&flag, 10, 1);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n1 번째 비트에 10 을 쓰기\n");
	printUnsigned16bitsNumberToBinary(flag);
	setBit(&flag, 1, 10);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n6 번째 비트에 1 을 쓰기\n");
	printUnsigned16bitsNumberToBinary(flag);
	setBit(&flag, 6, 1);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n6 번째 비트에 0 을 쓰기\n");
	printUnsigned16bitsNumberToBinary(flag);
	setBit(&flag, 6, 0);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n-------\n");
	printf("[toggleBit test]\n");
	printf("1 번째 비트 토글하기\n");
	printUnsigned16bitsNumberToBinary(flag);
	toggleBit(&flag, 1);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n3 번째 비트 토글하기\n");
	printUnsigned16bitsNumberToBinary(flag);
	toggleBit(&flag, 3);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n10 번째 비트 토글하기\n");
	printUnsigned16bitsNumberToBinary(flag);
	toggleBit(&flag, 10);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n-1 번째 비트 토글하기\n");
	printUnsigned16bitsNumberToBinary(flag);
	toggleBit(&flag, -1);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n1 번째 비트 토글하기\n");
	printUnsigned16bitsNumberToBinary(flag);
	toggleBit(&flag, 1);
	printUnsigned16bitsNumberToBinary(flag);

	printf("\n-------\n");
	printf("[splitWordToBytes test]\n");
	unsigned char high = 0x0000;
	unsigned char low = 0x0000;
	unsigned short value = 0xFFFF;
	splitWordToBytes(value, &high, &low);
	printf("value : 0x%02X(hex) -> high : 0x%02X(hex), low : 0x%02X(hex)\n", value, high, low);
	printUnsigned16bitsNumberToBinary(value);
	printUnsigned16bitsNumberToBinary(high);
	printUnsigned16bitsNumberToBinary(low);

	high = 0x0000;
	low = 0x0000;
	value = 0x5BB5;
	splitWordToBytes(value, &high, &low);
	printf("\nvalue : 0x%02X(hex) -> high : 0x%02X(hex), low : 0x%02X(hex)\n", value, high, low);
	printUnsigned16bitsNumberToBinary(value);
	printUnsigned16bitsNumberToBinary(high);
	printUnsigned16bitsNumberToBinary(low);

	printf("\n-------\n");
	printf("[mergeBytesToWord test]\n");
	high = 0x0000;
	low = 0x0000;
	value = 0xFFFF;
	splitWordToBytes(value, &high, &low);
	mergeBytesToWord(&high, &low, &value);
	printf("high : 0x%02X(hex), low : 0x%02X(hex) -> value : 0x%02X(hex)\n", high, low, value);
	printUnsigned16bitsNumberToBinary(high);
	printUnsigned16bitsNumberToBinary(low);
	printUnsigned16bitsNumberToBinary(value);

	high = 0x0000;
	low = 0x0000;
	value = 0xDBBD;
	splitWordToBytes(value, &high, &low);
	mergeBytesToWord(&high, &low, &value);
	printf("\nhigh : 0x%02X(hex), low : 0x%02X(hex) -> value : 0x%02X(hex)\n", high, low, value);
	printUnsigned16bitsNumberToBinary(high);
	printUnsigned16bitsNumberToBinary(low);
	printUnsigned16bitsNumberToBinary(value);

	printf("\n[프로그램 종료]\n");
	return SUCCESS;
}
*/

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
		printf("flag 참조 실패. NULL. (flag:%p)\n", flag);
		return;
	}

	if(checkBitRange(bit) == FAIL)
	{
		return;
	}

	if(checkValueRange(value) == FAIL)
	{
		return;
	}

	if(value == 0) *flag ^= (unsigned char)(1 << bit);
	else *flag |= (unsigned char)(1 << bit);
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
		printf("flag 참조 실패. NULL. (flag:%p)\n", flag);
		return FAIL;
	}

	if(checkBitRange(bit) == FAIL)
	{
		return FAIL;
	}

	return (*flag & (1 << bit)) ? 1 : 0;
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
		printf("flag 참조 실패. NULL. (flag:%p)\n", flag);
		return;
	}

	if(checkBitRange(bit) == FAIL)
	{
		return;
	}

	*flag ^= (unsigned char)(1 << bit);
}

/**
 * @fn void splitWordToBytes(unsigned short value, unsigned char *high, unsigned char *low)
 * @brief 16 비트 값을 상위 8 비트, 하위 8 비트 값으로 분리하여 반환하는 함수
 * @param value 분리될 16 비트 값(입력)
 * @param high 상위 8 비트 값(출력)
 * @param low 하위 8 비트 값(출력)
 * @return 반환값 없음
 */
void splitWordToBytes(unsigned short value, unsigned char *high, unsigned char *low)
{
	if(high == NULL || low == NULL)
	{
		printf("flag 참조 실패. NULL. (high:%p, low:%p)\n", high, low);
		return;
	}

	*high = (unsigned char)(value >> 8) & 0xFF;
	*low = (unsigned char)value & 0xFF;
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
	*value = (unsigned short)(*high << 8);
	*value = (unsigned short)(*value | (unsigned short)(*low));
}

/**
 * @fn void printUnsigned16bitsNumberToBinary(unsigned short value)
 * @brief 부호 없는 16 비트 정수를 이진수로 출력하는 함수
 * @param number 입력받을 정수(입력)
 * @return 반환값 없음
 */
void printUnsigned16bitsNumberToBinary(unsigned short value)
{
    unsigned int mask = 0x8000;
    int loopIndex = 1;

    printf("Binary : ");
    for( ; loopIndex <= 16; loopIndex++)
    {
        printf("%c", (value & mask) == 0 ? '0' : '1');
        if(loopIndex % 4 == 0) printf(" ");
        mask >>= 1;
    }
    printf("\n");
}

///////////////////////////////////////////////////////////////////////////////////////
/// Local Static functions
///////////////////////////////////////////////////////////////////////////////////////

/**
 * @fn static int checkBitRange(int bit)
 * @brief 비트값이 1 바이트 범위(0~NUM_OF_BIT) 내에 속하는지 검사하는 함수
 * (NUM_OF_BIT 은 매크로 선언부를 참고)
 * @param bit 검사할 비트값(입력)
 * @return 성공 시 SUCCESS, 실패 시 FAIL 반환
 */
static int checkBitRange(int bit)
{
	// bit : 000 ~ 111 -> (1111 1111 1111 1111 1111 1111 1111 1000)(0xfffffff8(hex)) & 0000 ... 111 -> 7(Dec) -> 범위 통과
	if(((unsigned int)bit & 0xfffffff8) != 0)
	//if(bit < 0 || value > NUM_OF_BIT)
	{
		printf("잘못된 Bit 입력. Bit 범위를 벗어남. (bit:%d, range:0~%d)\n", bit, NUM_OF_BIT - 1);
		return FAIL;
	}

	return SUCCESS;
}

/**
 * @fn static int checkValueRange(int value)
 * @brief 저장할 값이 범위(MIN_VALUE~MAX_VALUE) 내에 속하는지 검사하는 함수
 * (MIN_VALUE 과 MAX_VALUE 는 VALUE_RANGE 열거형을 참고)
 * @param value 검사할 값(입력)
 * @return 성공 시 SUCCESS, 실패 시 FAIL 반환
 */
static int checkValueRange(int value)
{
	// value : 0 ~ 1 -> (1111 1111 1111 1111 1111 1111 1111 1110)(0xfffffffe(hex)) & 0000 ... 1 -> 1(Dec) -> 범위 통과
	if(((unsigned int)value & 0xfffffffe) != 0)
	//if(value < MIN_VALUE || value > MAX_VALUE)
	{
		printf("잘못된 값 입력. 값의 범위를 벗어남. (value:%d, range:%d~%d)\n", value, MIN_VALUE, MAX_VALUE);
		return FAIL;
	}

	return SUCCESS;
}

