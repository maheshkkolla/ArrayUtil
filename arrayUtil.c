#include <stdio.h>
#include "arrayUtil.h"
#include <stdlib.h>

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

}


