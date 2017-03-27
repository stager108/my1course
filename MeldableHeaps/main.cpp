#include "BinomialHeap.h"
#include "LeftistHeap.h"
#include "SkewHeap.h"
#include "HeapTester.h"
#include "mytestheader.h"
#include <gtest.h>
#include <queue>


TEST(LeftistHeapTest, Test1) {
	MyStrangeTest <LeftistHeap> TestLeft;
	TestLeft.AddHeap(0);
	int min;
	for (int i = 1; i < 1000000; i++) {
		TestLeft.Insert(0, i);
	}
	for (int i = 0; i < 1000000; i++) {
		min = TestLeft.ExtractMin(0);
		EXPECT_EQ(min, i);
	}
	TestLeft.MyStrangeTestClear();

}
TEST(LeftistHeapTest, Test2) {
	MyStrangeTest <LeftistHeap> TestLeft;
	int min;
	TestLeft.AddHeap(9999);
	for (int i = 9998; i >= 0; i--) {
		TestLeft.Insert(0, i);
	}
	for (int i = 0; i < 1000; i++) {
		min = TestLeft.ExtractMin(0);
		EXPECT_EQ(min, i);
	}

	TestLeft.MyStrangeTestClear();

}
TEST(LeftistHeapTest, Test3) {
	MyStrangeTest <LeftistHeap> TestLeft;
	int min1, min2;
	TestLeft.AddHeap(0);
	TestLeft.AddHeap(-1);
	min1 = TestLeft.ExtractMin(0);
	min2 = TestLeft.ExtractMin(1);
	EXPECT_EQ(min1, 0);
	EXPECT_EQ(min2, -1);
	TestLeft.AddHeap(0);
	TestLeft.AddHeap(-1);
	min1 = TestLeft.ExtractMin(2);
	min2 = TestLeft.ExtractMin(3);
	EXPECT_EQ(min1, 0);
	EXPECT_EQ(min2, -1);
}
TEST(LeftistHeapTest, Test4) {
	MyStrangeTest <LeftistHeap> TestLeft;
	int min;
	TestLeft.AddHeap(0);
	TestLeft.AddHeap(0);
	TestLeft.AddHeap(0);
	TestLeft.AddHeap(0);
	for (int i = 1; i < 1000000; i++) {
		for (int j = 0; j < 4; j++) {
			TestLeft.Insert(j, i);
		}
	}
	for (int i = 0; i < 1000000; i++) {
		for (int j = 0; j < 4; j++) {
			min = TestLeft.ExtractMin(j);
			EXPECT_EQ(min, i);
		}
	}
	TestLeft.MyStrangeTestClear();

}
TEST(LeftistHeapTest, Test5) {
	MyStrangeTest <LeftistHeap> TestLeft;
	std::priority_queue <int> heap;
	int min1, min2, a;
	TestLeft.AddHeap(0);
	heap.push(0);
	for (int i = 1; i < 1000000; i++) {
		a = rand();
		TestLeft.Insert(0, a);
		heap.push(-a);
	}
	for (int i = 0; i < 1000000; i++) {
			min1 = TestLeft.ExtractMin(0);
			min2 = -(heap.top());
			EXPECT_EQ(min1, min2);
			heap.pop();
	}
	TestLeft.MyStrangeTestClear();
}

TEST(SkewHeapTest, Test1) {
	MyStrangeTest <SkewHeap> TestSkew;
	int min;
	TestSkew.AddHeap(0);
	for (int i = 1; i < 1000000; i++) {
		TestSkew.Insert(0, i);
	}
	for (int i = 0; i < 1000000; i++) {
		min = TestSkew.ExtractMin(0);
		EXPECT_EQ(min, i);
	}
		
	TestSkew.MyStrangeTestClear();

}
TEST(SkewHeapTest, Test2) {
	MyStrangeTest <SkewHeap> TestSkew;
	int min;
	TestSkew.AddHeap(9999);
	for (int i = 9998; i >= 0; i--) {
		TestSkew.Insert(0, i);
	}
	for (int i = 0; i < 10000; i++) {
		min = TestSkew.ExtractMin(0);
		EXPECT_EQ(min, i);
	}
	TestSkew.MyStrangeTestClear();

}
TEST(SkewHeapTest, Test3) {
	MyStrangeTest <SkewHeap> TestSkew;
	int min1, min2;
	TestSkew.AddHeap(0);
	TestSkew.AddHeap(-1);
	min1 = TestSkew.ExtractMin(0);
	min2 = TestSkew.ExtractMin(1);
	EXPECT_EQ(min1, 0);
	EXPECT_EQ(min2, -1);
	TestSkew.AddHeap(0);
	TestSkew.AddHeap(-1);
	min1 = TestSkew.ExtractMin(2);
	min2 = TestSkew.ExtractMin(3);
	EXPECT_EQ(min1, 0);
	EXPECT_EQ(min2, -1);
}
TEST(SkewHeapTest, Test4) {
	MyStrangeTest <SkewHeap> TestSkew;
	int min;
	TestSkew.AddHeap(0);
	TestSkew.AddHeap(0);
	TestSkew.AddHeap(0);
	TestSkew.AddHeap(0);
	for (int i = 1; i < 1000000; i++) {
		for (int j = 0; j < 4; j++) {
			TestSkew.Insert(j, i);
		}
	}
	for (int i = 0; i < 1000000; i++) {
		for (int j = 0; j < 4; j++) {
			min = TestSkew.ExtractMin(j);
			EXPECT_EQ(min, i);
		}
	}
	TestSkew.MyStrangeTestClear();
}
TEST(SkewHeapTest, Test5) {
	MyStrangeTest <SkewHeap> TestSkew;
	std::priority_queue <int> heap;
	int min1, min2, a;
	TestSkew.AddHeap(0);
	heap.push(0);
	for (int i = 1; i < 1000000; i++) {
		a = rand();
		TestSkew.Insert(0, a);
		heap.push(-a);
	}
	for (int i = 0; i < 1000000; i++) {
		min1 = TestSkew.ExtractMin(0);
		min2 = -(heap.top());
		EXPECT_EQ(min1, min2);
		heap.pop();
	}
	TestSkew.MyStrangeTestClear();
}
TEST(BinomialHeapTest, Test1) {
	MyStrangeTest <BinomialHeap> TestBin;
	int min;
	TestBin.AddHeap(0);
	for (int i = 1; i < 1000000; i++) {
		TestBin.Insert(0, i);
	}
	for (int i = 0; i < 1000000; i++) {
		min = TestBin.ExtractMin(0);
		EXPECT_EQ(min, i);
	}
	TestBin.MyStrangeTestClear();

}
TEST(BinomialHeapTest, Test2) {
	MyStrangeTest <BinomialHeap> TestBin;
	int min;
	TestBin.AddHeap(9999);
	for (int i = 9998; i >= 0; i--) {
		TestBin.Insert(0, i);
	}
	for (int i = 0; i < 10000; i++) {
		min = TestBin.ExtractMin(0);
		EXPECT_EQ(min, i);
	}
	TestBin.MyStrangeTestClear();
	
}
TEST(BinomialHeapTest, Test3) {
	MyStrangeTest <BinomialHeap> TestBin;
	int min1, min2;
	TestBin.AddHeap(0);
	TestBin.AddHeap(-1);
	min1 = TestBin.ExtractMin(0);
	min2 = TestBin.ExtractMin(1);
	EXPECT_EQ(min1, 0);
	EXPECT_EQ(min2, -1);
	TestBin.AddHeap(0);
	TestBin.AddHeap(-1);
	min1 = TestBin.ExtractMin(2);
	min2 = TestBin.ExtractMin(3);
	EXPECT_EQ(min1, 0);
	EXPECT_EQ(min2, -1);
}

TEST(BinomialHeapTest, Test4) {
	MyStrangeTest <BinomialHeap> TestBin;
	int min;
	TestBin.AddHeap(0);
	TestBin.AddHeap(0);
	TestBin.AddHeap(0);
	TestBin.AddHeap(0);
	for (int i = 1; i < 1000000; i++) {
		for (int j = 0; j < 4; j++) {
			TestBin.Insert(j, i);
		}
	}
	for (int i = 0; i < 1000000; i++) {
		for (int j = 0; j < 4; j++) {
			min = TestBin.ExtractMin(j);
			EXPECT_EQ(min, i);
		}
	}
	TestBin.MyStrangeTestClear();
}

TEST(BinomialHeapTest, Test5) {
	MyStrangeTest <BinomialHeap> TestBin;
	std::priority_queue <int> heap;
	int min1, min2, a;
	TestBin.AddHeap(0);
	heap.push(0);
	for (int i = 1; i < 1000000; i++) {
		a = rand();
		TestBin.Insert(0, a);
		heap.push(-a);
	}
	for (int i = 0; i < 1000000; i++) {
		min1 = TestBin.ExtractMin(0);
		min2 = -(heap.top());
		EXPECT_EQ(min1, min2);
		heap.pop();
	}
	TestBin.MyStrangeTestClear();
}
TEST(Heaps, Equivalence) {
	MyStrangeTest <LeftistHeap> TestLeft;
	MyStrangeTest <SkewHeap> TestSkew;
	MyStrangeTest <BinomialHeap> TestBin;
	double time;
	int min1, min2, min3;
	time = clock();
	srand(clock());
	int r, a, b;
	for (int i = 0; i < 3000000; i++) {
		r = rand() % 6;
		a = rand();
		b = rand();
		switch (r) {
		case Add:
			TestLeft.AddHeap(a);
			TestSkew.AddHeap(a);
			TestBin.AddHeap(a);
			break;
		case Insert:
			TestLeft.Insert(a, b);
			TestSkew.Insert(a, b);
			TestBin.Insert(a, b);
			break;
		case Meld:
			TestLeft.Meld(a, b);
			TestSkew.Meld(a, b);
			TestBin.Meld(a, b);
			break;
		default:
			min1 = TestLeft.ExtractMin(a);
			min2 = TestSkew.ExtractMin(a);
			min3 = TestBin.ExtractMin(a);
			EXPECT_EQ(min1, min2);
			EXPECT_EQ(min1, min3);
			EXPECT_EQ(min2, min3);
			break;
		}
	}
	for (int i = 0; i < 1000000; i++) {
		r = rand() % 11111;
		a = rand();
		b = rand();
		switch (r) {
		case Add:
			TestLeft.AddHeap(a);
			TestSkew.AddHeap(a);
			TestBin.AddHeap(a);
			break;
		case Insert: 
			TestLeft.Insert(a, b);
			TestSkew.Insert(a, b);
		    TestBin.Insert(a, b);
			break;
		case Meld:
			TestLeft.Meld(a, b);
			TestSkew.Meld(a, b);
			TestBin.Meld(a, b);
		default:
			min1 = TestLeft.ExtractMin(a);
			min2 = TestSkew.ExtractMin(a);
			min3 = TestBin.ExtractMin(a);
			EXPECT_EQ(min1, min2);
			EXPECT_EQ(min1, min3);
			EXPECT_EQ(min2, min3);
			break;
		}
	}

	TestLeft.MyStrangeTestClear();
	TestSkew.MyStrangeTestClear();
	TestBin.MyStrangeTestClear();
}
TEST(Heaps, WorkingTimeTest1) {

	double time, time1;
	time1 = clock();
	srand(clock());
	int r, a, b, min;
	for (int i = 0; i < 10000000; i++) {
		r = rand() % 6;
		a = MyRand();
		b = MyRand();
	}
	for (int i = 0; i < 100000; i++) {
		r = rand() % 1119;
		a = MyRand();
		b = MyRand();
	}
	for (int i = 0; i < 100000; i++) {
		a = MyRand();
	}
	time1 = (clock() - time1);
	time = clock();
	std::cout << "Please wait " << std::endl;
	MyStrangeTest <BinomialHeap> TestBin;
	for (int i = 0; i < 10000000; i++) {
		r = rand() % 6;
		a = MyRand();
		b = MyRand();
		switch (r) {
		case Add: TestBin.AddHeap(a);	break;
		case Insert: TestBin.Insert(a, b); break;
		case Meld: TestBin.Meld(a, b);  break;
		default: min = TestBin.ExtractMin(a); break;
		}
	}
	for (int i = 0; i < 100000; i++) {
		r = rand() % 1119;
		a = MyRand();
		b = MyRand();
		switch (r) {
		case Add:	TestBin.AddHeap(a);	break;
		case Insert:	TestBin.Insert(a, b); break;
		case Meld: TestBin.Meld(a, b);	 break;
		default: min = TestBin.ExtractMin(a);	break;
		}
	}
	for (int i = 0; i < 100000; i++) {
		a = MyRand();
	    min = TestBin.ExtractMin(a);
	}
	std::cout << "Binomial Heap : working time is " << (clock() - time - time1) << std::endl;
	TestBin.MyStrangeTestClear();
	time = clock();
	srand(clock());
	MyStrangeTest <LeftistHeap> TestLeft;
	for (int i = 0; i < 10000000; i++) {
		r = rand() % 6;
		a = MyRand();
		b = MyRand();
		switch (r) {
		case Add: TestLeft.AddHeap(a); break;
		case Insert:	TestLeft.Insert(a, b); break;
		case Meld:	TestLeft.Meld(a, b);	break;
		default: min = TestLeft.ExtractMin(a); break;
		}
	}
	for (int i = 0; i < 100000; i++) {
		r = rand() % 1119;
		a = MyRand();
		b = MyRand();
		switch (r) {
		case Add: TestLeft.AddHeap(a); break;
		case Insert:	TestLeft.Insert(a, b); break;
		case Meld :TestLeft.Meld(a, b);	break;
		default:min = TestLeft.ExtractMin(a);	 break;
		}
	}
	for (int i = 0; i < 100000; i++) {
		a = MyRand();
		min = TestLeft.ExtractMin(a);
	}
	std::cout << "Leftist Heap : working time is " << (clock() - time - time1) << std::endl;
	TestLeft.MyStrangeTestClear();
	time = clock();
	srand(clock());
	MyStrangeTest <SkewHeap> TestSkew;
	for (int i = 0; i < 10000000; i++) {
		r = rand() % 6;
		a = MyRand();
		b = MyRand();
		switch (r) {
		case Add:	TestSkew.AddHeap(a); break;
		case Insert:   TestSkew.Insert(a, b); break;
		case Meld: TestSkew.Meld(a, b);	break;
		default:	min = TestSkew.ExtractMin(a); break;
		}
	}
	for (int i = 0; i < 100000; i++) {
		r = rand() % 1119;
		a = MyRand();
		b = MyRand();
		switch (r) {
		case Add:	TestSkew.AddHeap(a); break;
		case Insert:	TestSkew.Insert(a, b); break;
		case Meld: TestSkew.Meld(a, b); break;
		default: min = TestSkew.ExtractMin(a); break;
		}
	}
	for (int i = 0; i < 100000; i++) {
		a = MyRand();
		min = TestSkew.ExtractMin(a);
	}
	std::cout << "SkewHeap : working time is " << (clock() - time - time1) << std::endl;
	TestSkew.MyStrangeTestClear();
	}
  
	TEST(Heaps, WorkingTimeTest2) {
		srand(clock());
		std::vector<int> Tests = GenerateTest();
		std::vector <int> Res1 = MyVectorAnswer<LeftistHeap>(Tests);
		std::vector <int> Res2 = MyVectorAnswer<SkewHeap>(Tests);
		std::vector <int> Res3 = MyVectorAnswer<BinomialHeap>(Tests);
		std::vector <int> RightRes = GetRightAnswer(Tests);
		double time = clock();
		Res1 = MyVectorAnswer<LeftistHeap>(Tests);
		std::cout << "Leftist Heap : working time is " << (clock() - time) << std::endl;
	    time = clock();
		Res2 = MyVectorAnswer<SkewHeap>(Tests);
		std::cout << "Skew Heap : working time is " << (clock() - time) << std::endl;
	    time = clock();
		Res3 = MyVectorAnswer<BinomialHeap>(Tests);
		std::cout << "Binomial Heap : working time is " << (clock() - time) << std::endl;
		EXPECT_EQ(Res1, RightRes);
		EXPECT_EQ(Res1, Res2);
		EXPECT_EQ(Res2, Res3);
	    EXPECT_EQ(Res3, Res1);
	}
	
TEST(xyz, ololo) {
	std::cout << "";
	std::cin.get();
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}/*
int main() {
	LeftistHeap TestLeft;
	SkewHeap TestSkew;
	for (int i = 0; i < 10; i++) {
		TestLeft.Insert(i);
		TestSkew.Insert(i);
	}
	for (int i = 0; i < 10; i++) {
		TestLeft.ExtractMin();
		TestSkew.ExtractMin();
	}
	int d;
	std::cout << "Lol";
	std::cin >> d;
	for (int i = 0; i < 1000000; i++) {
		TestLeft.Insert(i);
	}
	for (int i = 0; i < 1000000; i++) {
		TestLeft.ExtractMin();
	}
	std::cout << "Lol";
	std::cin >> d;


}
}*/