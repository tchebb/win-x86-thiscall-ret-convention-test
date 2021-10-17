// ThiscallReturnTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

using namespace std;

struct FourByteIntStruct {
	int d;
};

struct FourByteArrStruct {
	char d[4];
};

union FourByteIntUnion {
	int d;
	unsigned int u;
};

union FourByteArrUnion {
	int d;
	char a[4];
};

union FourByteStructUnion {
	int d;
	FourByteIntStruct s;
};

class FourByteClass {
public:
	int getInt() {
		return 4;
	}

	int *getPtr() {
		return NULL;
	}

	FourByteIntStruct getIntStruct() {
		return FourByteIntStruct{ 4 };
	}

	FourByteArrStruct getArrStruct() {
		return FourByteArrStruct{ {4, 4, 4, 4} };
	}

	FourByteIntUnion getIntUnion() {
		return FourByteIntUnion{ 4 };
	}

	FourByteArrUnion getArrUnion() {
		return FourByteArrUnion{ 4 };
	}

	FourByteStructUnion getStructUnion() {
		return FourByteStructUnion{ 4 };
	}

	FourByteClass getClass() {
		return *this;
	}

private:
	int s = 4;
};

#define TRY_FUNC(f) { \
	unsigned int res = 0; \
	f; \
	__asm { mov res, eax } \
	cout <<"0x" << hex << setw(8) << setfill('0') << res << " " << #f << endl; \
}

int main()
{
	unsigned int ret = 0;
	FourByteClass c;

	TRY_FUNC(c.getInt());
	TRY_FUNC(c.getPtr());
	TRY_FUNC(c.getIntStruct());
	TRY_FUNC(c.getArrStruct());
	TRY_FUNC(c.getIntUnion());
	TRY_FUNC(c.getArrUnion());
	TRY_FUNC(c.getStructUnion());
	TRY_FUNC(c.getClass());
}
