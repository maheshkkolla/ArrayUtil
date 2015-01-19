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

void test_resize_returns_new_Array_util_with_new_length_by_putting_0s_in_extra_spaces(){
	ArrayUtil a = create(4, 2);
	ArrayUtil c = create(4, 4);
	ArrayUtil b;
	int *aBase = (int *)(a.base);
	int *cBase = (int *)(c.base);
	aBase[0] = 1;
	aBase[1] = 1;
	cBase[0] = 1;
	cBase[1] = 1;
	cBase[2] = 0;
	cBase[3] = 0;
	b = resize(a, 4);
	assertEqual(areEqual(b,c),1);	
}

void test_resize_returns_new_Array_util_with_new_length_by_deleting_extra_values(){
	ArrayUtil a = create(4, 4);
	ArrayUtil c = create(4, 2);
	ArrayUtil b;
	int *aBase = (int *)(a.base);
	int *cBase = (int *)(c.base);
	aBase[0] = 0;
	aBase[1] = 1;
	aBase[2] = 2;
	aBase[3] = 3;
	cBase[0] = 0;
	cBase[1] = 1;
	b = resize(a, 2);
	assertEqual(areEqual(b,c),1);	
}