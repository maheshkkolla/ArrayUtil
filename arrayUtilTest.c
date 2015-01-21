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
	free(aBase);
	free(bBase);
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
	free(aBase);
	free(bBase);
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
	ArrayUtil b = create(4, 4);
	ArrayUtil c;
	int *aBase = (int *)(a.base);
	int *bBase = (int *)(b.base);
	aBase[0] = 1;
	aBase[1] = 1;
	bBase[0] = 1;
	bBase[1] = 1;
	bBase[2] = 0;
	bBase[3] = 0;
	c = resize(a, 4);
	assertEqual(areEqual(c,b),1);
	free(aBase);
	free(bBase);	
}

void test_resize_returns_new_Array_util_with_new_length_by_deleting_extra_values(){
	ArrayUtil a = create(4, 4);
	ArrayUtil b = create(4, 2);
	ArrayUtil c;
	int *aBase = (int *)(a.base);
	int *bBase = (int *)(b.base);
	aBase[0] = 0;
	aBase[1] = 1;
	aBase[2] = 2;
	aBase[3] = 3;
	bBase[0] = 0;
	bBase[1] = 1;
	c = resize(a, 2);
	assertEqual(areEqual(c,b),1);
	free(aBase);
	free(bBase);	
}

void test_findIndex_returns_index_of_the_element_where_it_presents(){
	int index;
	char element = 'h';
	ArrayUtil a = create(sizeof(char), 4);
	char *aBase = (char *)(a.base);
	aBase[0] = 'm';
	aBase[1] = 'a';
	aBase[2] = 'h';
	aBase[3] = 'e';
	index = findIndex(a, &element);
	assertEqual(index, 2);
}

void test_findIndex_returns_index_of_the_int_element_where_it_presents(){
	int index;
	int element = 5;
	ArrayUtil a = create(sizeof(int), 5);
	int *aBase = (int *)(a.base);
	aBase[0] = 1;
	aBase[1] = 1;
	aBase[2] = 2;
	aBase[3] = 4;
	aBase[4] = 5;
	index = findIndex(a, &element);
	assertEqual(index, 4);
}

int isEven(void *hint, void *item) {
	int *number = (int *)item;
	return(*number%2==0);
}

void test_findFirst_element_of_the_array_whixh_is_even(){
	ArrayUtil a = create(sizeof(int), 5);
	int *result;
	int *aBase = (int *)(a.base);
	aBase[0] = 1;
	aBase[1] = 3;
	aBase[2] = 5;
	aBase[3] = 4;
	aBase[4] = 7;
	result = (int *)findFirst(a, &isEven, 0);
	assertEqual(*result, 4);
}

void test_findLast_element_of_the_array_which_is_even(){
	ArrayUtil a = create(sizeof(int),7);
	int *result;
	int *aBase = (int *)(a.base);
	aBase[0] = 1;
	aBase[1] = 2;
	aBase[2] = 3;
	aBase[3] = 4;
	aBase[4] = 5;
	aBase[5] = 6;
	aBase[6] = 7;
	result = (int *)findLast(a,&isEven,0);
	assertEqual(*result, 6);
}