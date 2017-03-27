
#include <iostream>
#include <queue>
#include <deque>
#include <vector>
#include <set>
#include <limits>
class Position
{
private:
	int massiv[9];
	int zero_pos;
	int ans;
	int getInt() {
		int p = 0;
		int z = 1;
		for (int i = 0; i < 9; i++) {
			p += massiv[i] * z;
			z = z * 10;
		}
		return p;
	}
public:
	Position() {}
	void getPos(int pos) {
		for (int i = 0; i < 9; i++) {
			massiv[i] = pos % 10;
			pos = pos / 10;
		}
		for (int i = 0; i<9; i++) {
			if (massiv[i] == 0)
				zero_pos = i;
		}
	}

	int getLeft() {
		if (zero_pos % 3 == 0) {
			return -1;
		}
		else {
			std::swap(massiv[zero_pos], massiv[zero_pos - 1]);
			ans = getInt();
			std::swap(massiv[zero_pos], massiv[zero_pos - 1]);
		}
		return ans;
	}
	int getRight() {
		if (zero_pos % 3 == 2) {
			return -1;
		}
		else {
			std::swap(massiv[zero_pos], massiv[zero_pos + 1]);
			ans =  getInt();
			std::swap(massiv[zero_pos], massiv[zero_pos + 1]);
		}
		return ans;
	}
	int getUp() {
		if (zero_pos < 3) {
			return -1;
		}
		else {
			std::swap(massiv[zero_pos], massiv[zero_pos - 3]);
			ans = getInt();
			std::swap(massiv[zero_pos], massiv[zero_pos - 3]);
		}
		return ans;
	}
	int getDown() {
		if (zero_pos > 5) {
			return -1;
		}
		else {
			std::swap(massiv[zero_pos], massiv[zero_pos + 3]);
			ans = getInt();
			std::swap(massiv[zero_pos], massiv[zero_pos + 3]);
		}
		return ans;
	}

	~Position() {}
};
int main()
{
	int n;
	int ans;

	bool hello = false;
	int p = 0;
	int z = 1;
	int m;
	std::cin >> n;
	for (int i = 0; i<9; i++) {
		std::cin >> m;
		p += m*z;
		z = z * 10;
	}
	Position MyPosClass;
	std::set <int> Set1;
	std::set <int> Set2;
	std::deque <int> Que1;
	std::deque <int> Que2;
	std::deque <std::vector<char>> MyWays1;
	std::vector <char> Way1;
	std::vector <char> Way2;
	Set1.clear();
	Que1.clear();
	Set1.insert(p);
	Way1.clear();
	Way2.clear();
	Que1.push_back(p);
	MyWays1.push_back(Way1);
	while (!hello && (!Que1.empty())) {
		m = Que1.front();

		MyPosClass.getPos(m);
		n = MyPosClass.getDown();
		if (n != -1) {
			if (Set1.find(n) == Set1.end()) {
				Set1.insert(n);
				Que1.push_back(n);
				Way1 = MyWays1.front();
				Way1.push_back('U');
				MyWays1.push_back(Way1);
				Way1.clear();
			}
		}
		if (n == 87654321) {
			hello = true;
			Way2 = MyWays1.back();
			break;
		}
		n = MyPosClass.getUp();
		if (n != -1) {
			if (Set1.find(n) == Set1.end()) {
				Set1.insert(n);
				Que1.push_back(n);
				Way1 = MyWays1.front();
				Way1.push_back('D');
				MyWays1.push_back(Way1);
				Way1.clear();
			}
		}
		if (n == 87654321) {
			hello = true;
			Way2 = MyWays1.back();
			break;
		}
		n = MyPosClass.getRight();
		if (n != -1) {
			if (Set1.find(n) == Set1.end()) {
				Set1.insert(n);
				Que1.push_back(n);
				Way1 = MyWays1.front();
				Way1.push_back('L');
				MyWays1.push_back(Way1);
				Way1.clear();
			}
		}
		if (n == 87654321) {
			hello = true;
			Way2 = MyWays1.back();
			break;
		}
		n = MyPosClass.getLeft();
		if (n != -1) {
			if (Set1.find(n) == Set1.end()) {
				Set1.insert(n);
				Que1.push_back(n);
				Way1 = MyWays1.front();
				Way1.push_back('R');
				MyWays1.push_back(Way1);
				Way1.clear();
			}
		}
		if (n == 87654321) {
			hello = true;
			Way2 = MyWays1.back();
			break;
		}
        Que1.pop_front();
		MyWays1.pop_front();
	}


	for (int j = 0; j < Way2.size(); j++) {
		std::cout << Way2[j] << "\n";
	}

	Way1.clear();
	Way2.clear();
	Set1.clear();
	Que1.clear();

	return 0;
}
