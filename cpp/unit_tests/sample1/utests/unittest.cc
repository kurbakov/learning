#include "gtest/gtest.h"
#include <source/my_math.h>

TEST(My_Math, DefaultConstructor) {

	// call the class
	My_Math m;
}

TEST(My_Math, Addition){
	// call the class
	My_Math m;

	// run the function
	EXPECT_EQ(0, m.addition(0, 0));
	EXPECT_EQ(10, m.addition(10, 0));
}

TEST(My_Math, Subtraction){
	// call the class
	My_Math m;

	// run the function
	EXPECT_EQ(0, m.subtraction(0, 0));
	EXPECT_EQ(10, m.subtraction(10, 0));
}

TEST(My_Math, Multiply){
	// call the class
	My_Math m;

	// run the function
	EXPECT_EQ(0, m.multiply(0, 0));
	EXPECT_EQ(10, m.multiply(5, 2));
}

TEST(My_Math, Divide){
	// call the class
	My_Math m;

	// run the function
	EXPECT_EQ(2, m.divide(10, 5));
	EXPECT_EQ(10, m.divide(100, 10));
}

TEST(My_Math, Equal){
	// call the class
	My_Math m;

	// run the function
	EXPECT_TRUE(m.equal(0, 0));
	EXPECT_TRUE(m.equal(10, 10));
}
