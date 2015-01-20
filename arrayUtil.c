#include <stdio.h>
#include "arrayUtil.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int areEqual(ArrayUtil a, ArrayUtil b) {
	int i;
	if(a.length == b.length && a.typeSize == b.typeSize) {
		for (i = 0; i < a.length; ++i) {
			if(((int *)a.base)[i] != ((int *)b.base)[i]) return 0;
		}
		return 1;
	}
	return 0;
}

ArrayUtil create(int typeSize, int length) {
	ArrayUtil array;
	array.base = calloc(length, typeSize);
	array.typeSize = typeSize;
	array.length = length;
	return array;
}

ArrayUtil resize(ArrayUtil util, int length) {
	int i;
	ArrayUtil array;
	array = create(util.typeSize, length);
	for (i = 0; i < length; ++i){
		if(i < util.length) ((int *)(array.base))[i] = ((int *)(util.base))[i];
		else ((int *)(array.base))[i] = 0;
	} 
	return array;
}

int findIndex(ArrayUtil util, void *element){
	char *utilArray = (char *)(util.base);
	char *item = (char *)element;
	int count = util.length * util.typeSize;
	int subCount = util.typeSize * sizeof(char);
	int i, j;
	for (i = 0, j = 0; i < count; ++i) {
		if(j>0 && utilArray[i] != item[j]) j=0;
		if(utilArray[i] == item[j]){
			j++;
		}
		if(j==subCount) return(i/util.typeSize);
	}
	return -1;
}

void dispose(ArrayUtil util) {
	free(util.base);
}



