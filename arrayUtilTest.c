#include "arrayUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include "expr_assert.h"

void test_areEqual_returns_1_if_both_are_equal(){
	int equal;
	ArrayUtil a;
	ArrayUtil b;
	a.length = 2;
	b.length = 2;
	a.typeSize =4;
	b.typeSize =4;
	a.base = (int *)a.base;
	b.base = (int *)b.base;
	((int *)a.base)[0] = 1;
	((int *)a.base)[1] = 2;
	((int *)b.base)[0] = 1;
	((int *)b.base)[1] = 2;
	equal = areEqual(a, b);
	assertEqual(equal, 1);
} 

void test_areEqual_returns_0_if_both_are_not_equal(){
	int equal;
	ArrayUtil a;
	ArrayUtil b;
	a.length = 2;
	b.length = 2;
	a.typeSize =4;
	b.typeSize =4;
	a.base = (int *)a.base;
	b.base = (int *)b.base;
	((int *)a.base)[0] = 1;
	((int *)a.base)[1] = 1;
	((int *)b.base)[0] = 1;
	((int *)b.base)[1] = 2;
	equal = areEqual(a, b);
	assertEqual(equal, 0);
} 