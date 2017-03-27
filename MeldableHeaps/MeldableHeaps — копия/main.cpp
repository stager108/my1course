#include "BinomialHeap.h"
#include "LeftistHeap.h"
#include "SkewHeap.h"
#include "HeapTester.h"

int main()
{
	LeftistHeap Lh;
	SkewHeap Sh;
	BinomialHeap Bh;
	MyStrangeTest <LeftistHeap> TestLeft();
	MyStrangeTest <SkewHeap> TestSkew();
	MyStrangeTest <BinomialHeap> TestBin();

	int k;
	for (int i; i < 100; i++) {
		k = rand() % 4;


	}
	return 0;
}