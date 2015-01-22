#include "arrayUtil.h"
#include <stdlib.h>
#include <stdio.h>
#include "expr_assert.h"

void test_areEqual_returns_1_if_both_integer_arrays_are_equal(){
	int array1[] = {1,2,3,4,5}, array2[] = {1,2,3,4,5};
	ArrayUtil util1 = {array1,sizeof(int),5};
	ArrayUtil util2 = {array2,sizeof(int),5};
	assertEqual(areEqual(util1, util2), 1);
}
void test_areEqual_returns_1_if_both_character_arrays_are_equal(){
	char array1[] = {'m','a','h','e'}, array2[] = {'m','a','h','e'};
	ArrayUtil util1 = {array1,sizeof(char),4};
	ArrayUtil util2 = {array2,sizeof(char),4};
	assertEqual(areEqual(util1, util2), 1);
}
void test_areEqual_returns_1_if_both_float_arrays_are_equal(){
	float array1[] = {0.0,1.1,2.2,3.3,4.4}, array2[] = {0.0,1.1,2.2,3.3,4.4};
	ArrayUtil util1 = {array1,sizeof(float),5};
	ArrayUtil util2 = {array2,sizeof(float),5};
	assertEqual(areEqual(util1, util2), 1);
}
void test_areEqual_returns_1_if_both_double_arrays_are_equal(){
	double array1[] = {0.0,1.1,2.2,3.3,4.4}, array2[] = {0.0,1.1,2.2,3.3,4.4};
	ArrayUtil util1 = {array1,sizeof(double),5};
	ArrayUtil util2 = {array2,sizeof(double),5};
	assertEqual(areEqual(util1, util2), 1);
}
void test_areEqual_returns_1_if_both_String_arrays_are_equal(){
	String array1[] = {"MaheshKumarKolla"}, array2[] = {"MaheshKumarKolla"};
	ArrayUtil util1 = {array1,sizeof(char *),1};
	ArrayUtil util2 = {array2,sizeof(char *),1};
	assertEqual(areEqual(util1, util2), 1);
}

void test_areEqual_returns_0_if_lengths_of_two_arrays_are_not_equal(){
	int array1[] = {1,2,3,4,5}, array2[] = {1,2,3,4};
	ArrayUtil util1 = {array1,sizeof(int),5};
	ArrayUtil util2 = {array2,sizeof(int),4};
	assertEqual(areEqual(util1, util2), 0);
}
void test_areEqual_returns_0_if_typeSize_of_two_arrays_are_not_equal(){
	int array1[] = {1,2,3,4};
	char array2[] = {'m','a','h','e'};
	ArrayUtil util1 = {array1,sizeof(int),4};
	ArrayUtil util2 = {array2,sizeof(char),4};
	assertEqual(areEqual(util1, util2), 0);
}
void test_areEqual_returns_0_if_values_of_two_arrays_are_not_equal(){
	int array1[] = {1,2,3,4}, array2[] = {1,2,4,3};
	ArrayUtil util1 = {array1,sizeof(int),4};
	ArrayUtil util2 = {array2,sizeof(int),4};
	assertEqual(areEqual(util1, util2), 0);
}
void test_areEqual_returns_1_even_arrays_are_not_initialized(){
	ArrayUtil util1 = create(sizeof(int),2);
	ArrayUtil util2 = create(sizeof(int),2); 
	assertEqual(areEqual(util1, util2), 1);
}

void test_resize_returns_new_Array_util_with_integer_array_of_new_length_by_putting_0s_in_new_created_spaces(){
	int array1[] = {1,2}, array2[] = {1,2,0,0,0};
	ArrayUtil util1 = {array1,sizeof(int),2};
	ArrayUtil util2 = {array2,sizeof(int),5};
	assertEqual(areEqual(resize(util1, 5), util2), 1);	
}
void test_resize_returns_new_Array_util_with_char_array_of_new_length_by_putting_0s_in_new_created_spaces(){
	char array1[] = {'m','k'}, array2[] = {'m','k',0,0,0};
	ArrayUtil util1 = {array1,sizeof(char),2};
	ArrayUtil util2 = {array2,sizeof(char),5};
	assertEqual(areEqual(resize(util1, 5), util2), 1);	
}
void test_resize_returns_new_Array_util_with_float_array_of_new_length_by_putting_0s_in_new_created_spaces(){
	float array1[] = {2.1,4.5}, array2[] = {2.1,4.5,0,0,0};
	ArrayUtil util1 = {array1,sizeof(float),2};
	ArrayUtil util2 = {array2,sizeof(float),5};
	assertEqual(areEqual(resize(util1, 5), util2), 1);	
}
void test_resize_returns_new_Array_util_with_double_array_of_new_length_by_putting_0s_in_new_created_spaces(){
	double array1[] = {2.1,4.5}, array2[] = {2.1,4.5,0,0,0};
	ArrayUtil util1 = {array1,sizeof(double),2};
	ArrayUtil util2 = {array2,sizeof(double),5};
	assertEqual(areEqual(resize(util1, 5), util2), 1);	
}
void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_putting_0s_in_new_created_spaces(){
	String array1[] = {"Mahesh","Kumar"}, array2[] = {"Mahesh","Kumar",0,0,0};
	ArrayUtil util1 = {array1,sizeof(char *),2};
	ArrayUtil util2 = {array2,sizeof(char *),5};
	assertEqual(areEqual(resize(util1, 5), util2), 1);	
}
void test_resize_returns_new_Array_util_with_integer_array_of_new_length_by_removing_extra_values(){
	int array1[] = {1,2,3,4,5}, array2[] = {1,2};
	ArrayUtil util1 = {array1,sizeof(int),5};
	ArrayUtil util2 = {array2,sizeof(int),2};
	assertEqual(areEqual(resize(util1, 2), util2), 1);	
}
void test_resize_returns_new_Array_util_with_flaot_array_of_new_length_by_removing_extra_values(){
	float array1[] = {1.1,2.2,3.3,4.4,5.5}, array2[] = {1.1,2.2};
	ArrayUtil util1 = {array1,sizeof(float),5};
	ArrayUtil util2 = {array2,sizeof(float),2};
	assertEqual(areEqual(resize(util1, 2), util2), 1);	
}
void test_resize_returns_new_Array_util_with_char_array_of_new_length_by_removing_extra_values(){
	char array1[] = {'m','a','h','e','s','h'}, array2[] = {'m','a','h','e'};
	ArrayUtil util1 = {array1,sizeof(char),6};
	ArrayUtil util2 = {array2,sizeof(char),4};
	assertEqual(areEqual(resize(util1, 4), util2), 1);	
}
void test_resize_returns_new_Array_util_with_String_array_of_new_length_by_removing_extra_values(){
	String array1[] = {"Mahesh","Kumar","Kolla"}, array2[] = {"Mahesh","Kumar"};
	ArrayUtil util1 = {array1,sizeof(char *),3};
	ArrayUtil util2 = {array2,sizeof(char *),2};
	assertEqual(areEqual(resize(util1, 2), util2), 1);	
}

void test_findIndex_returns_index_of_the_integer_element_where_it_presents(){
	int array1[] = {1,2,3,4,5};
	int element = 2;
	ArrayUtil util1 = {array1,sizeof(int),5};
	assertEqual(findIndex(util1,&element), 1);
}
void test_findIndex_returns_index_of_the_char_element_where_it_presents(){
	char array1[] = {'m','a','h','e','s','h'};
	char element = 's';
	ArrayUtil util1 = {array1,sizeof(char),6};
	assertEqual(findIndex(util1,&element), 4);
}
void test_findIndex_returns_index_of_the_float_element_where_it_presents(){
	float array1[] = {1.1,2.2,3.3,4.4};
	float element = 4.4;
	ArrayUtil util1 = {array1,sizeof(float),4};
	assertEqual(findIndex(util1,&element), 3);
}
void test_findIndex_returns_index_of_the_String_element_where_it_presents(){
	String array1[] = {"Mahesh","Kumar","Kolla"};
	String element = "Kumar";
	ArrayUtil util1 = {array1,sizeof(String),3};
	assertEqual(findIndex(util1,&element), 1);
}
void test_findIndex_returns_minus_1_if_the_element_is_not_present_in_the_array(){
	String array1[] = {"Mahesh","Kumar","Kolla"};
	String element = "KMK";
	ArrayUtil util1 = {array1,sizeof(String),3};
	assertEqual(findIndex(util1,&element), -1);
}

int isEven(void *hint, void *item) {
	return(*(int *)item%2==0);
}
void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_even(){
	int array1[] = {1,2,3,4,5};
	ArrayUtil util1 = {array1,sizeof(int),5};
	assertEqual(*(int *)(findFirst(util1,&isEven, 0)), 2);
}

int isCapital(void *hint, void *item) {
	return((*(char *)item >=65) && (*(char *)item <= 91));
}

void test_findFirst_returns_the_address_of_the_first_element_in_the_array_that_is_capital(){
	char array1[] = {'k','M','k'};
	ArrayUtil util1 = {array1,sizeof(char),3};
	assertEqual(*(char *)(findFirst(util1,&isCapital,0)), 'M');
}

int isGreaterThan5(void *hint, void *item) {
	return(*(float *)item > 5);
}
void test_findFirst_returns_the_adsdress_of_first_element_in_the_array_greater_than_5() {
	float array1[] = {1.1,6.6,5.5,8.8,2.2};
	ArrayUtil util1 ={array1, sizeof(float),5};
	assertEqual(*(float *)(findFirst(util1,&isGreaterThan5,0)), 6.6);
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

void test_count_the_elements_of_the_array_which_is_even(){
	ArrayUtil a = create(sizeof(int),7);
	int result;
	int *aBase = (int *)(a.base);
	aBase[0] = 1;
	aBase[1] = 2;
	aBase[2] = 3;
	aBase[3] = 4;
	aBase[4] = 5;
	aBase[5] = 6;
	aBase[6] = 7;
	result = count(a,&isEven,0);
	assertEqual(result, 3);
}