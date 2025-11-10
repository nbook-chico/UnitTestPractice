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
}

TEST(PasswordTest, multi_leading_letters_2)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("aabb"));
}

TEST(PasswordTest, multi_leading_letters_3)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Aab"));
}

TEST(PasswordTest, multi_leading_letters_4)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("aAb"));
}

TEST(PasswordTest, multi_leading_letters_5)
{
	Password my_password;
	ASSERT_EQ(4, my_password.count_leading_characters("aaaa"));
}

TEST(PasswordTest, multi_leading_letters_6)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("aaba"));
}

TEST(PasswordTest, multi_leading_letters_7)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("aaAa"));
}

TEST(PasswordTest, multi_leading_letters_8)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("aba"));
}

TEST(PasswordTest, empty_leading_letters)
{
	Password my_password;
	ASSERT_EQ(0, my_password.count_leading_characters(""));
}

TEST(PasswordTest, mixed_case)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Ab"));
}

TEST(PasswordTest, mixed_case_2)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("AbA"));
}

TEST(PasswordTest, mixed_case_3)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("bbbbbbA"));
}

TEST(PasswordTest, mixed_case_4)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("aBAb"));
}

TEST(PasswordTest, mixed_case_5)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("bbbbbb"));
}

TEST(PasswordTest, mixed_case_6)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("bba"));
}