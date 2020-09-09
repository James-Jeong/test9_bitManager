#include <stdio.h>
#include <gtest/gtest.h>

#include "main.h"

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
}

TEST(bitManagerTest, getBitAbnormal) {
	printf("\n[getBit Abnormal test]\n");

	unsigned char flag = 0x0A;
	int result = 0;

	printf("\n10 번째 비트 값 읽기\n");
	result = getBit(&flag, 10);
	printf("getBit : %d\n", result);
	EXPECT_EQ(-1, result);


	printf("\n-5 번째 비트 값 읽기\n");
	result = getBit(&flag, -5);
	printf("getBit : %d\n", result);
	EXPECT_EQ(-1, result);
}

TEST(bitManagerTest, toggleBitNormal) {
	printf("\n[toggleBit Normal test]\n");

	unsigned char flag = 0x0A;

	printf("1 번째 비트 토글하기\n");
	printUnsigned16bitsNumberToBinary(flag);
	toggleBit(&flag, 1);
	printUnsigned16bitsNumberToBinary(flag);
	EXPECT_EQ(0, getBit(&flag, 1));
}

TEST(bitManagerTest, toggleBitAbnormal) {
	printf("\n[toggleBit Abnormal test]\n");

	unsigned char flag = 0x0A;

	printf("-1 번째 비트 토글하기\n");
	printUnsigned16bitsNumberToBinary(flag);
	toggleBit(&flag, -1);
	printUnsigned16bitsNumberToBinary(flag);
}


//////////////////////////////////////////////
/// TEST Main
//////////////////////////////////////////////

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
