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

TEST(PasswordTest, check_mixed_case_mixed)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("HelloWorld");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, check_mixed_case_all_lower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("abcxyz");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, check_mixed_case_all_upper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ABCXYZ");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, check_mixed_case_empty_string)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, check_mixed_case_all_special)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("1234567890!@#$%^&*()");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, check_mixed_case_mixed_with_special)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("1234567890A!@#$%^&*()a");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, check_mixed_case_upper_with_special)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("1234567890AZ!@#$%^&*()");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, check_mixed_case_lower_with_special)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("1234567890az!@#$%^&*()");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, check_mixed_case_whitespace)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("\nA \na");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, check_mixed_case_Aa)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Aa");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, check_mixed_case_Zz)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("Zz");
	ASSERT_EQ(true,actual);
}

// tests for constructor, set(), authenticate() --------------------------------

TEST(PasswordTest, constructor_sets_expected_default)
{
	Password my_password;
	bool actual = my_password.authenticate("ChicoCA-95929");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, authenticate_identifies_mismatch)
{
	Password my_password;
	bool actual = my_password.authenticate("Passwords");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, set_and_auth_password_good)
{
	Password my_password;
	my_password.set("Passwords");
	bool actual = my_password.authenticate("Passwords");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, set_password_same_case)
{
	Password my_password;
	my_password.set("passwords");
	bool actual = my_password.authenticate("passwords");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, set_password_3_leading_chars)
{
	Password my_password;
	my_password.set("PPPasswords");
	bool actual = my_password.authenticate("PPPasswords");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, set_password_too_many_leading_chars)
{
	Password my_password;
	my_password.set("PPPPasswords");
	bool actual = my_password.authenticate("PPPPasswords");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, set_password_8_chars)
{
	Password my_password;
	my_password.set("Password");
	bool actual = my_password.authenticate("Password");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, set_password_short)
{
	Password my_password;
	my_password.set("Pass");
	bool actual = my_password.authenticate("Pass");
	ASSERT_EQ(false,actual);
}

TEST(PasswordTest, set_password_multiple_times)
{
	Password my_password;
	my_password.set("Passwords1");
	my_password.set("Passwords2");
	my_password.set("Passwords3");
	bool actual = my_password.authenticate("Passwords3");
	ASSERT_EQ(true,actual);
}

TEST(PasswordTest, set_password_blank)
{
	Password my_password;
	my_password.set("");
	bool actual = my_password.authenticate("");
	ASSERT_EQ(false,actual);
}

// UNABLE TO TEST FOR REPEAT PASSWORD SUBMISSIONS