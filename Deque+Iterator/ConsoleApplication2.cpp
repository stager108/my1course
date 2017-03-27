
#include "Header1.h"
#include <gtest.h>
//1
TEST(DequeTest, Constructors) {

	Deque <int> MyDeq;
	EXPECT_EQ(MyDeq.size(), 0);
	EXPECT_TRUE(MyDeq.empty());
	for (int i = 0; i < 30; i++) {
		MyDeq.push_back(i);
	}

	Deque <int> Deq2(MyDeq);
	for (int i = 0; i < 30; i++) {
		EXPECT_EQ(MyDeq[i], Deq2[i]);
	}

	EXPECT_EQ(MyDeq.size(), Deq2.size());
	
}
//2
TEST(DequeTest, Push_Back_MyDeque) {

	Deque <int> MyDeq;
	EXPECT_EQ(MyDeq.size(), 0);
	EXPECT_TRUE(MyDeq.empty());

	MyDeq.push_back(1);
	EXPECT_EQ(MyDeq[0], 1);
	EXPECT_EQ(MyDeq.size(), 1);
	EXPECT_FALSE(MyDeq.empty());

	MyDeq.push_back(2);
	EXPECT_EQ(MyDeq[1], 2);
	EXPECT_EQ(MyDeq.size(), 2);
	EXPECT_FALSE(MyDeq.empty());

	MyDeq.push_back(3);
	EXPECT_EQ(MyDeq[2], 3);
	EXPECT_EQ(MyDeq.size(), 3);
	EXPECT_FALSE(MyDeq.empty());

}
//3
TEST(DequeTest, Push_Front_MyDeque) {

	Deque <int> MyDeq;
	EXPECT_EQ(MyDeq.size(), 0);
	EXPECT_TRUE(MyDeq.empty());

	MyDeq.push_front(1);
	EXPECT_EQ(MyDeq[0], 1);
	EXPECT_EQ(MyDeq.size(), 1);
	EXPECT_FALSE(MyDeq.empty());

	MyDeq.push_front(2);
	EXPECT_EQ(MyDeq[0], 2);
	EXPECT_EQ(MyDeq.size(), 2);
	EXPECT_FALSE(MyDeq.empty());

	MyDeq.push_front(3);
	EXPECT_EQ(MyDeq[0], 3);
	EXPECT_EQ(MyDeq.size(), 3);
	EXPECT_FALSE(MyDeq.empty());

}
//4
TEST(DequeTest, Pop_Back_MyDeque) {

	Deque <int> MyDeq;
	EXPECT_EQ(MyDeq.size(), 0);
	EXPECT_TRUE(MyDeq.empty());

	MyDeq.push_back(1);
	MyDeq.push_back(2);
	MyDeq.push_back(3);

	EXPECT_EQ(MyDeq[0], 1);
	EXPECT_EQ(MyDeq[1], 2);
	EXPECT_EQ(MyDeq[2], 3);
	EXPECT_EQ(MyDeq.size(), 3);
	
	MyDeq.pop_back();

	EXPECT_EQ(MyDeq[0], 1);
	EXPECT_EQ(MyDeq[1], 2);
	EXPECT_EQ(MyDeq.size(), 2);


	MyDeq.pop_back();
	EXPECT_EQ(MyDeq[0], 1);
	EXPECT_EQ(MyDeq.size(), 1);

	MyDeq.pop_back();
	
	EXPECT_EQ(MyDeq.size(), 0);
	EXPECT_TRUE(MyDeq.empty());


	MyDeq.pop_back();

	EXPECT_EQ(MyDeq.size(), 0);
	EXPECT_TRUE(MyDeq.empty());
}
//5
TEST(DequeTest, Pop_Front_MyDeque) {
	Deque <int> MyDeq;
	EXPECT_EQ(MyDeq.size(), 0);
	EXPECT_TRUE(MyDeq.empty());

	MyDeq.push_back(1);
	MyDeq.push_back(2);
	MyDeq.push_back(3);

	EXPECT_EQ(MyDeq[0], 1);
	EXPECT_EQ(MyDeq[1], 2);
	EXPECT_EQ(MyDeq[2], 3);
	EXPECT_EQ(MyDeq.size(), 3);

	MyDeq.pop_front();

	EXPECT_EQ(MyDeq[0], 2);
	EXPECT_EQ(MyDeq[1], 3);
	EXPECT_EQ(MyDeq.size(), 2);


	MyDeq.pop_front();
	EXPECT_EQ(MyDeq[0], 3);
	EXPECT_EQ(MyDeq.size(), 1);

	MyDeq.pop_front();

	EXPECT_EQ(MyDeq.size(), 0);
	EXPECT_TRUE(MyDeq.empty());


	MyDeq.pop_front();

	EXPECT_EQ(MyDeq.size(), 0);
	EXPECT_TRUE(MyDeq.empty());
}
//6

TEST(DequeTest, EqualenseOfTwoDeques) {
	Deque <int> Deque1;
	Deque <int> Deque2;
	int e;
	for (int i = 0; i < 30; i++) {
		Deque1.push_back(i);
	}
	Deque2 = Deque1;
	for (int i = 0; i < 30; i++) {
		EXPECT_EQ(Deque1[i], Deque2[i]);
	}
}
//7
TEST(DequeTest, MyIterator1) {

	Deque <int> MyDeq;

	for (int i = 0; i < 30; i++) {
		MyDeq.push_back(i);
	}

	MyIterator <int> I, H;
	I = MyDeq.begin();
	EXPECT_EQ(*I, MyDeq[0]);
	I++;
	EXPECT_EQ(*I, MyDeq[1]);
	I--;
	EXPECT_EQ(*I, MyDeq[0]);
	I += 15;
	EXPECT_EQ(*I, MyDeq[15]);
	I -= 12;
	EXPECT_EQ(*I, MyDeq[3]);
	I = I + 4;
	EXPECT_EQ(*I, MyDeq[7]);
	I = I - 5;
	EXPECT_EQ(*I, MyDeq[2]);

	H = MyDeq.end();
	H--;
	EXPECT_EQ(*H, MyDeq[MyDeq.size() - 1]);
	H--;
	EXPECT_EQ(*H, MyDeq[MyDeq.size() - 2]);
	H++;
	EXPECT_EQ(*H, MyDeq[MyDeq.size() - 1]);
	
	H -= 15;
	EXPECT_EQ(*H, MyDeq[MyDeq.size() - 16]);
	H += 12;
	EXPECT_EQ(*H, MyDeq[MyDeq.size() - 4]);

	I = MyDeq.begin();
	H = MyDeq.end();

	EXPECT_TRUE( I < H);
	EXPECT_TRUE( I <= H);
	EXPECT_TRUE( H > I);
	EXPECT_TRUE( H >= I);

}
//8

TEST(DequeTest, MyIterator2) {

	Deque <int> MyDeq;

	for (int i = 0; i < 3000; i++) {
		MyDeq.push_back(3000 - i);
	}
	std::reverse(MyDeq.begin(), MyDeq.end());

	for (int i = 0; i < 3000; i++) {
		EXPECT_EQ(MyDeq[i], i + 1);
	}
}
//9
TEST(DequeTest, MyIterator3) {
	Deque <int> MyDeq;
	

	for (int i = 0; i < 3; i++) {
		MyDeq.push_back(i);
	}

	int i = 0;
	MyIterator <int> g = MyDeq.begin();

	while (g < MyDeq.end()) {
		EXPECT_EQ(MyDeq[i], i);
		i++;
		g++;
	}

	i = MyDeq.size() - 1;
	g = MyDeq.end() - 1;
	while (g > MyDeq.begin()) {
		EXPECT_EQ(MyDeq[i], i);
		i--;
		g--;
	}
}


//10
TEST(DequeTest, WorkingTime1) {
	Deque <int> MyDeq;
	double time;
	std::cout << "Please wait" << std::endl;
	time = clock();
	int r, E;
	for (int i = 0; i < 30; i++) {
		for (int ii = 0; ii < 10000000; ii++) {
			r = rand() % 4;
			switch (r) {
			case 0: MyDeq.push_back(rand()); break;
			case 1: MyDeq.push_back(rand()); break;
			case 2: MyDeq.pop_front(); break;
			case 3:  MyDeq.pop_back(); break;
			default:  E = MyDeq[rand()]; break;
			}
		}
			std::cout << "working time for " << i + 1 << " portions is " <<(clock() - time) / (i + 1) << " by portion " << std::endl;
	}

}
//11
TEST(DequeTest, WorkingTime2) {
	Deque <int> MyDeq;
	double time;
	std::cout << "Please wait" << std::endl;
	time = clock();
	int r, E;
	for (int i = 0; i < 30; i++) {
		for (int ii = 0; ii < 10000000; ii++) {
			r = rand() % 2;
			if (r == 0) { MyDeq.push_back(rand()); }
			else { MyDeq.pop_back(); };
			}
		
		std::cout << "working time for " << i + 1 << " portions is " << (clock() - time) / (i + 1) << " by portion " << std::endl;
	}
}
//12
TEST(DequeTest, WorkingTime3) {
	Deque <int> MyDeq;
	double time;
	std::cout << "Please wait" << std::endl;
	time = clock();
	int r, E;
	for (int i = 0; i < 30; i++) {
		for (int ii = 0; ii < 10000000; ii++) {
			r = rand() % 2;
			if (r == 0) { MyDeq.push_front(rand()); }
			else { MyDeq.pop_front(); };
		}
	
	std::cout << "working time for " << i + 1 << " portions is " << (clock() - time) / (i + 1) << " by portion " << std::endl;
    }
}
//13
TEST(DequeTest, WorkingTime4) {
	Deque <int> MyDeq;
	double time;
	std::cout << "Please wait" << std::endl;
	time = clock();
	int r, E;
	for (int i = 0; i < 30; i++) {
		for (int ii = 0; ii < 10000000; ii++) {
			r = rand() % 7;
			switch (r) {
			case 0:case 4: MyDeq.push_back(rand()); break;
			case 1:case 5:MyDeq.push_back(rand()); break;
			case 2: MyDeq.pop_front(); break;
			case 3:  MyDeq.pop_back(); break;
			default:  E = MyDeq[rand()]; break;
			}
		}
		std::cout << "working time for " << i + 1 << " portions is " << (clock() - time) / (i + 1) << " by portion " << std::endl;
	}
	time = clock();
	for (int i = 0; i < 30; i++) {
		for (int ii = 0; ii < 10000000; ii++) {
			r = rand() % 7;
			switch (r) {
			case 0: MyDeq.push_back(rand()); break;
			case 1: MyDeq.push_back(rand()); break;
			case 2: case 4:MyDeq.pop_front(); break;
			case 3: case 5: MyDeq.pop_back(); break;
			default:  E = MyDeq[rand()]; break;
			}
		}
		std::cout << "working time for " << i + 1 << " portions is " << (clock() - time) / (i + 1) << " by portion " << std::endl;
	}
}//14
TEST(DequeTest, WorkingTime5) {
	Deque <int> MyDeq;
	double time;
	std::cout << "Please wait" << std::endl;
	time = clock();
	int r, E;
	for (int i = 0; i < 30; i++) {
		for (int ii = 0; ii < 10000000; ii++) {
			r = rand() % 3;
			if (r == 0) { MyDeq.pop_back();  }
			else { MyDeq.push_back(rand()); };
		}

		std::cout << "working time for " << i + 1 << " portions is " << (clock() - time) / (i + 1) << " by portion " << std::endl;
	}
	time = clock();
	for (int i = 0; i < 30; i++) {
		for (int ii = 0; ii < 10000000; ii++) {
			r = rand() % 3;
			if (r == 0) { MyDeq.push_back(rand()); }
			else { MyDeq.pop_back(); };
		}

		std::cout << "working time for " << i + 1 << " portions is " << (clock() - time) / (i + 1) << " by portion " << std::endl;
	}
}
//15
TEST(DequeTest, WorkingTime6) {
	Deque <int> MyDeq;
	double time;
	std::cout << "Please wait" << std::endl;
	time = clock();
	int r, E;
	for (int i = 0; i < 30; i++) {
		for (int ii = 0; ii < 10000000; ii++) {
			r = rand() % 3;
			if (r == 0) { MyDeq.pop_front();}
			else { MyDeq.push_front(rand()); };
		}

		std::cout << "working time for " << i + 1 << " portions is " << (clock() - time) / (i + 1) << " by portion " << std::endl;
	}

	time = clock();
	for (int i = 0; i < 30; i++) {
		for (int ii = 0; ii < 10000000; ii++) {
			r = rand() % 3;
			if (r == 0) { MyDeq.push_front(rand()); }
			else { MyDeq.pop_front(); };
		}

		std::cout << "working time for " << i + 1 << " portions is " << (clock() - time) / (i + 1) << " by portion " << std::endl;
	}
	std::cout << "The end. Please enter a random number." << std::endl;
	int pp;
	std::cin >> pp;
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	

}





