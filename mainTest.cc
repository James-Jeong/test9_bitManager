#include <stdio.h>
#include <gtest/gtest.h>

#include "main.h"

//////////////////////////////////////////////
/// TEST Local Functions
//////////////////////////////////////////////

// checkBitRange Normal
TEST(bitManagerTest, checkBitNormal) {
	printf("\n[checkBitRange Normal test]\n");

	int bit = 0, result = 0;

	// 검사 항목 :  first, middle, final value

	printf("0 이 1 바이트 범위에 속하는지 검사\n");
	result = checkBitRange(bit);
	printf("result : %d\n", result);
	EXPECT_EQ(SUCCESS, result);

	printf("\n3 이 1 바이트 범위에 속하는지 검사\n");
	bit = 3;
	result = checkBitRange(bit);
	printf("result : %d\n", result);
	EXPECT_EQ(SUCCESS, result);

	printf("\n7 이 1 바이트 범위에 속하는지 검사\n");
	bit = 7;
	result = checkBitRange(bit);
	printf("result : %d\n", result);
	EXPECT_EQ(SUCCESS, result);
	printf("\n");
}

// checkBitRange Abnormal
TEST(bitManagerTest, checkBitAbnormal) {
	printf("\n[checkBitRange Abnormal test]\n");

	int bit = -1, result = 0;

	// 검사 항목 :  (first - 1), (final + 1) value

	printf("-1 이 1 바이트 범위에 속하는지 검사\n");
	result = checkBitRange(bit);
	printf("result : %d\n", result);
	EXPECT_EQ(FAIL, result);

	printf("\n8 이 1 바이트 범위에 속하는지 검사\n");
	bit = 8;
	result = checkBitRange(bit);
	printf("result : %d\n", result);
	EXPECT_EQ(FAIL, result);
	printf("\n");
}

// checkValueRange Normal
TEST(bitManagerTest, checkValueNormal) {
	printf("\n[checkValueRange Normal test]\n");

	int value = 0, result = 0;

	// 검사 항목 :  first, final value

	printf("0 이 정해진 값의 범위에 속하는지 검사\n");
	result = checkValueRange(value);
	printf("result : %d\n", result);
	EXPECT_EQ(SUCCESS, result);

	printf("\n1 이 정해진 값의 범위에 속하는지 검사\n");
	value = 1;
	result = checkValueRange(value);
	printf("result : %d\n", result);
	EXPECT_EQ(SUCCESS, result);
	printf("\n");
}

// checkValueRange Abnormal
TEST(bitManagerTest, checkValueAbnormal) {
	printf("\n[checkValueRange Abnormal test]\n");

	int value = -1, result = 0;

	// 검사 항목 :  (first - 1), (final + 1) value

	printf("-1 이 정해진 값의 범위에 속하는지 검사\n");
	result = checkValueRange(value);
	printf("result : %d\n", result);
	EXPECT_EQ(FAIL, result);

	printf("\n2 가 정해진 값의 범위에 속하는지 검사\n");
	value = 2;
	result = checkValueRange(value);
	printf("result : %d\n", result);
	EXPECT_EQ(FAIL, result);
	printf("\n");
}

// getBit Normal
TEST(bitManagerTest, getBitNormal) {
	printf("\n[getBit Normal test]\n");

	unsigned char flag = 0x0A;
	int result = 0;

	printf("0 번째 비트 값 읽기\n");
	result = getBit(&flag, 0);
	printf("getBit : %d\n", result);
	EXPECT_EQ(0, result);

	printf("\n5 번째 비트 값 읽기\n");
	result = getBit(&flag, 5);
	printf("getBit : %d\n", result);
	EXPECT_EQ(0, result);

	printf("\n3 번째 비트 값 읽기\n");
	result = getBit(&flag, 3);
	printf("getBit : %d\n", result);
	EXPECT_EQ(1, result);
	printf("\n");
}

// getBit Abnormal
TEST(bitManagerTest, getBitAbnormal) {
	printf("\n[getBit Abnormal test]\n");

	unsigned char flag = 0x0A;
	int result = 0;

	printf("\n10 번째 비트 값 읽기\n");
	result = getBit(&flag, 10);
	printf("getBit : %d\n", result);
	EXPECT_EQ(FAIL, result);


	printf("\n-5 번째 비트 값 읽기\n");
	result = getBit(&flag, -5);
	printf("getBit : %d\n", result);
	EXPECT_EQ(FAIL, result);
	printf("\n");
}

// toggleBit Normal
TEST(bitManagerTest, toggleBitNormal) {
	printf("\n[toggleBit Normal test]\n");

	unsigned char flag = 0x0A;

	printf("1 번째 비트 토글하기\n");
	printUnsigned16bitsNumberToBinary(flag);
	toggleBit(&flag, 1);
	printUnsigned16bitsNumberToBinary(flag);
	EXPECT_EQ(0, getBit(&flag, 1));
	printf("\n");
}

// toggleBit Abnormal
TEST(bitManagerTest, toggleBitAbnormal) {
	printf("\n[toggleBit Abnormal test]\n");

	unsigned char flag = 0x0A;

	printf("-1 번째 비트 토글하기\n");
	printUnsigned16bitsNumberToBinary(flag);
	toggleBit(&flag, -1);
	printUnsigned16bitsNumberToBinary(flag);
	printf("\n");
}


//////////////////////////////////////////////
/// TEST Main Function
//////////////////////////////////////////////

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
