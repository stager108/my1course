
#include <memory>
int main() {
	int b = 5;
	std::unique_ptr<int> a(new int(5));
	//std::unique_ptr<int> c = nullptr;
	return 0;
}