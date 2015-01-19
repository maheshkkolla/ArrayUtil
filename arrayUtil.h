typedef struct arrayUtil {
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

int areEqual(ArrayUtil a, ArrayUtil b);
ArrayUtil create(int typeSize, int length);
ArrayUtil resize(ArrayUtil util, int length);