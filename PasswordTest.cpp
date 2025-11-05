/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_leading_letters)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("aab"));
	ASSERT_EQ(2, my_password.count_leading_characters("aabb"));
	ASSERT_EQ(1, my_password.count_leading_characters("Aab"));
	ASSERT_EQ(1, my_password.count_leading_characters("aAb"));
	ASSERT_EQ(4, my_password.count_leading_characters("aaaa"));
	ASSERT_EQ(2, my_password.count_leading_characters("aaba"));
	ASSERT_EQ(2, my_password.count_leading_characters("aaAa"));
	ASSERT_EQ(1, my_password.count_leading_characters("aba"));
}