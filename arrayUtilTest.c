#include "arrayUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include "expr_assert.h"

void test_areEqual_returns_1_if_both_are_equal(){
	int equal;
	ArrayUtil a = create(4, 2);
	ArrayUtil b = create(4, 2);
	int *aBase = (int *)(a.base);
	int *bBase = (int *)(b.base);
	aBase[0] = 1;
	aBase[1] = 2;
	bBase[0] = 1;
	bBase[1] = 2;
	equal = areEqual(a, b);
	assertEqual(equal, 1);
} 

void test_areEqual_returns_0_if_both_are_not_equal(){
	int equal;
	ArrayUtil a = create(4, 2);
	ArrayUtil b = create(4, 2);
	int *aBase = (int *)(a.base);
	int *bBase = (int *)(b.base);
	aBase[0] = 1;
	aBase[1] = 1;
	bBase[0] = 1;
	bBase[1] = 2;						
	equal = areEqual(a, b);
	assertEqual(equal, 0);
} 

void test_areEqual_returns_1_if_both_arrays_are_not_intialized(){
	int equal;
	ArrayUtil a = create(4, 2);
	ArrayUtil b = create(4, 2);
	equal = areEqual(a, b);
	assertEqual(equal, 1);
} 