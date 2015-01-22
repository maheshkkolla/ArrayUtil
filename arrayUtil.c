#include <stdio.h>
#include "arrayUtil.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

int areEqual(ArrayUtil a, ArrayUtil b) {
	int i;
	if(a.length != b.length || a.typeSize != b.typeSize) return 0;
	for (i = 0; i < a.length * a.typeSize; ++i) {
		if(((char *)a.base)[i] != ((char *)b.base)[i]) return 0;
	}
	return 1;	
}

// int areEqual(ArrayUtil a, ArrayUtil b) {
// 	int i, j;
// 	if(a.length != b.length || a.typeSize != b.typeSize) return 0;
// 	for (i = 0; i < a.length; ++i) {
// 		for (j = 0; i < sizeof(a.base[i]); ++i) {
// 			// if(((char *)(a.base[i]))[0] != ((char *)(b.base[i]))[0]) return 0;			
// 		}
// 	}
// 	return 1;
// }

ArrayUtil create(int typeSize, int length) {
	return (ArrayUtil){calloc(length, typeSize),typeSize,length};
}

ArrayUtil resize(ArrayUtil util, int length) {
	int i, count = (length<=util.length) ? (length*util.typeSize) : (util.length*util.typeSize);
	ArrayUtil newUtil = create(util.typeSize, length);
	for (i = 0; i < count; ++i) {
		((char *)(newUtil.base))[i] = ((char *)(util.base))[i];
	} 
	return newUtil;
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

void *findFirst(ArrayUtil util, MatchFunc *match, void *hint) {
	char *array = (char *)util.base;
	int i, count = util.length * util.typeSize;
	for (i = 0; i < count; i=i+util.typeSize) {
		if(match(hint,array+i)) return(array+i);
	}
	return NULL;
}

void *findLast(ArrayUtil util, MatchFunc *match, void *hint) {
	char *array = (char *)util.base;
	char *result = NULL;
	int i, count = util.length * util.typeSize;
	for (i = 0; i < count; i=i+util.typeSize) {
		if(match(hint,array+i)) result = array+i;
	}
	return result;
}

int count(ArrayUtil util, MatchFunc* match, void* hint) {
	char *array = (char *)util.base;
	int resultCount = 0;
	int i, count = util.length * util.typeSize;
	for (i = 0; i < count; i=i+util.typeSize) {
		if(match(hint,array+i)) resultCount++;
	}
	return resultCount;
}



