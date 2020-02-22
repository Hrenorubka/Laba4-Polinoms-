#include "Polinom.h"
#include <gtest.h>

TEST(math_expresions_b1, can_check_true_string)
{
	string s = "(3+3)*(1)";
	vector <string> obl;
	ASSERT_NO_THROW(convert_str_to_Poland(s, obl));
}

TEST(math_expresions_b1, can_check_true_fraction_v2)
{
	string s = "(1.2+3.8)*1.5";
	EXPECT_EQ(7.5 ,get_res_from_math_expresions(s));
}
