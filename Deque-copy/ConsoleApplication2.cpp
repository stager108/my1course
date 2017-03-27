
#include "Header1.h"
#include <gtest.h>
//1
TEST(Heaps, AllTest) {
		LeftistHeap Lh;
		SkewHeap Sh;
		BinomialHeap Bh;
		MyStrangeTest <LeftistHeap> TestLeft;
		MyStrangeTest <SkewHeap> TestSkew;
		MyStrangeTest <BinomialHeap> TestBin;

		int k;
		for (int i; i < 100; i++) {
			k = rand() % 4;
			switch (k) {
			case 0: TestLeft.AddHeap((int)rand()); break;
			/*case 1: MyDeq.push_back(rand()); break;
			case 2: MyDeq.pop_front(); break;
			case 4:  MyDeq.pop_back(); break;
			default:  E = MyDeq[rand()]; break;*/
			}
		}
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	

}





