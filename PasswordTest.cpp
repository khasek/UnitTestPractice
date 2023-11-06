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

TEST(PasswordTest, smoke_test)
{
  ASSERT_TRUE( 1 == 1 );
}

// tests for count_leading_characters() ----------------------------------------

TEST(PasswordTest, single_letter_password)
{
  Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, empty_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0,actual);
}

TEST(PasswordTest, case_sensitivity)
{
	Password my_password;
	int actual = my_password.count_leading_characters("aaAaAaA");
	ASSERT_EQ(2,actual);
}

TEST(PasswordTest, repeating_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("hhhelloworld");
	ASSERT_EQ(3,actual);
}

TEST(PasswordTest, no_repeating_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("helloworld");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, mixed_characters)
{
	Password my_password;
	int actual = my_password.count_leading_characters("eu234;kj)(*AD)");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, leading_uppercase)
{
	Password my_password;
	int actual = my_password.count_leading_characters("HHHELLOWORLD");
	ASSERT_EQ(3,actual);
}

TEST(PasswordTest, leading_number)
{
	Password my_password;
	int actual = my_password.count_leading_characters("11123456");
	ASSERT_EQ(3,actual);
}

TEST(PasswordTest, leading_special_character)
{
	Password my_password;
	int actual = my_password.count_leading_characters("!!!@#$%^");
	ASSERT_EQ(3,actual);
}

TEST(PasswordTest, includes_spaces)
{
	Password my_password;
	int actual = my_password.count_leading_characters("a aabcd");
	ASSERT_EQ(1,actual);
}

TEST(PasswordTest, includes_newline)
{
	Password my_password;
	int actual = my_password.count_leading_characters("a\naabcd");
	ASSERT_EQ(1,actual);
}

// tests for has_mixed_case() --------------------------------------------------

TEST(PasswordTest, recognize_mixed_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("HelloWorld");
	ASSERT_EQ(true,actual);
}

/* Test ideas:
- mixed lower and upper case
- all lower case
- all upper case
- lower case + special characters
- upper case + special characters
- no letters, just special characters
- empty string
- includes whitespace
*/
