#include "pch.h"
#include "../Lab-Polynomials/TPolinom.h"

TEST(Polinom, Created_polinom_is_empty) {
	TPolinom polinom;

    EXPECT_TRUE(polinom.IsEmpty());
}

TEST(Polinom, Created_polinom_with_one_monom_is_not_empty) {
	TPolinom polinom;
	TMonom monom(1, 1, 1, 1);
	polinom.AddMonom(monom);

	EXPECT_TRUE(!polinom.IsEmpty());
}

TEST(Polinom, Coefficients_add_up_if_degrees_are_equal) {
	TPolinom polinom;
	polinom.AddMonom(TMonom(1, 1, 1, 1));
	polinom.AddMonom(TMonom(2, 1, 1, 1));
	polinom.AddMonom(TMonom(3, 1, 1, 1));
	polinom.Reset();
	EXPECT_TRUE(polinom.GetLength() == 1 && polinom.GetCurrentItem().coef == 6);
}

TEST(Polinom, Coefficients_dont_add_up_if_degrees_are_different) {
	TPolinom polinom;
	polinom.AddMonom(TMonom(1, 1, 1, 1));
	polinom.AddMonom(TMonom(2, 2, 1, 1));
	polinom.AddMonom(TMonom(3, 3, 1, 1));
	polinom.Reset();
	EXPECT_TRUE(polinom.GetLength() == 3);
}

TEST(Polinom, Monom_delete_if_coefficient_equal_zero) {
	TPolinom polinom;
	polinom.AddMonom(TMonom(1, 1, 1, 1));
	polinom.AddMonom(TMonom(-1, 1, 1, 1));
	EXPECT_TRUE(polinom.IsEmpty());
}

TEST(Polinom, Can_not_get_monom_from_empty_polinom) {
	TPolinom polinom;

	EXPECT_ANY_THROW(polinom.GetCurrentItem());
}

TEST(Polinom, Copied_polinom_is_equal_copiable) {
	bool result = true;
	TPolinom copiable;
	copiable.AddMonom(TMonom(-1, 1, 1, 1));
	copiable.AddMonom(TMonom(2, 1, 1, 2));
	copiable.AddMonom(TMonom(3, 1, 2, 1));
	TPolinom copied(copiable);
	EXPECT_TRUE(copied == copiable);
}

TEST(Polinom, Assigned_polinom_is_equal_assignable) {
	bool result = true;
	TPolinom assinable;
	assinable.AddMonom(TMonom(-1, 1, 1, 1));
	assinable.AddMonom(TMonom(2, 1, 1, 2));
	assinable.AddMonom(TMonom(3, 1, 2, 1));
	TPolinom assigned;
	assigned = assinable;
	EXPECT_TRUE(assigned == assinable);
}

TEST(Polinom, Correct_adding_operator) {
	TPolinom polinom1;
	polinom1.AddMonom(TMonom(-1, 1, 1, 1));
	polinom1.AddMonom(TMonom(2, 1, 1, 2));
	polinom1.AddMonom(TMonom(3, 1, 2, 1));
	TPolinom polinom2;
	polinom2.AddMonom(TMonom(1, 1, 1, 1));
	polinom2.AddMonom(TMonom(2, 1, 1, 2));
	polinom2.AddMonom(TMonom(3, 1, 2, 1));
	TPolinom result = polinom1 + polinom2;
	result.Reset();
	float coef1 = result.GetCurrentItem().coef;
	result.GoNext();
	float coef2 = result.GetCurrentItem().coef;

	EXPECT_TRUE(result.GetLength() == 2 && coef1 == 6 && coef2 == 4);
}

TEST(Polinom, Correct_constant_multiply) {
	TPolinom p;
	p.AddMonom(TMonom(-1, 1, 1, 1));
	p.AddMonom(TMonom(2, 1, 1, 2));
	TPolinom ans;
	ans.AddMonom(TMonom(-2, 1, 1, 1));
	ans.AddMonom(TMonom(4, 1, 1, 2));
	EXPECT_TRUE(p*2 == ans);
}

TEST(Polinom, Correct_monom_multiply) {
	TPolinom p;
	p.AddMonom(TMonom(1, 1, 1, 1));
	p.AddMonom(TMonom(-1, 2, 2, 2));
	TPolinom ans;
	ans.AddMonom(TMonom(2, 2, 3, 4));
	ans.AddMonom(TMonom(-2, 3, 4, 5));
	EXPECT_TRUE(p.MultMonom(TMonom(2,1,2,3)) == ans);
}

TEST(Polinom, Correct_polinom_enter) {
	TPolinom p = "1x^1y^2z^3 + -2x^3y^2z^1";
	TPolinom ans;
	ans.AddMonom(TMonom(1, 1, 2, 3));
	ans.AddMonom(TMonom(-2, 3, 2, 1));

	EXPECT_TRUE(p == ans);
}

TEST(Polinom, Correct_multiply_polinom1) {
	bool result = true;
	TPolinom p1 = "1x^1y^2z^3 + -2x^3y^2z^1";
	TPolinom p2 = "1x^1z^1 + 2y^1";
	TPolinom ans;
	ans.AddMonom(TMonom(1, 2, 2, 4));
	ans.AddMonom(TMonom(-2, 4, 2, 2));
	ans.AddMonom(TMonom(2, 1, 3, 3));
	ans.AddMonom(TMonom(-4, 3, 3, 1));

	EXPECT_TRUE(p1*p2 == ans);
}

TEST(Polinom, Correct_multiply_polinom2) {
	bool result = true;
	TPolinom p1 = "3x^2y^3z^2 + 4y^1z^2";
	TPolinom p2 = "5z^1 + -1x^3y^2";
	TPolinom ans;
	ans.AddMonom(TMonom(15, 2, 3, 3));
	ans.AddMonom(TMonom(-3, 5, 5, 2));
	ans.AddMonom(TMonom(20, 0, 1, 3));
	ans.AddMonom(TMonom(-4, 3, 3, 2));

	EXPECT_TRUE(p1 * p2 == ans);
}

TEST(Polinom, Correct_multiply_polinom3) {
	bool result = true;
	TPolinom p1 = "2x^1-3y^1+4z^1";
	TPolinom p2 = "2x^1y^1 - 1y^1z^1 + 1x^1z^2";
	TPolinom ans;
	ans.AddMonom(TMonom(4, 2, 1, 0));
	ans.AddMonom(TMonom(2, 2, 0, 2));
	ans.AddMonom(TMonom(-6, 1, 2, 0));
	ans.AddMonom(TMonom(-3, 1, 1, 2));
	ans.AddMonom(TMonom(6, 1, 1, 1));
	ans.AddMonom(TMonom(4, 1, 0, 3));
	ans.AddMonom(TMonom(3, 0, 2, 1));
	ans.AddMonom(TMonom(-4, 0, 1, 2));

	EXPECT_TRUE(p1 * p2 == ans);
}