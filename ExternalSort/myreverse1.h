#include "iworker.h"
#include <algorithm>
#include <functional>
#include <queue>

template <typename T>
class MySamePart : public MyWorker <T> {
private:
	int count;   //maximum file size
	int iterator;
public:

	MySamePart(int size): MyWorker(size) {}

	~MySamePart() {}

	virtual void SpecialOperation1(std::vector<T> &data) = 0;

	virtual void SpecialOperation2(MyWrite <T> *Ans1, int files, std::vector<FileStorage<T>*> &F) = 0;

	void getAnswer(std::string& input, std::string& output, std::string& directory) {
		MyRead<T> S(input);
		MyWrite<T> Ans(output);
		std::vector<FileStorage<T>*> F;
		T val;
		int files = 0;//how much files do we have
		int e;

		while (S.hasNext()) {
			getDataFromSourceToVector(S1);
			SpecialOperation1(data);
			F.push_back(new FileStorage<T>());
			F.back()->nameFile(files, directory);
			putDataToFile(F.back());
			files++;
		}
		SpecialOperation2(&Ans, files, F);
	}

};

template <typename T>
class MyReverse: public MySamePart <T> {
private:
	int count;   //maximum file size
	int iterator;
public:

	MyReverse(int size) : MySamePart(size) {}

	~MyReverse() { }
	
	void SpecialOperation1(std::vector<T> &data) {
		std::reverse(data.begin(), data.end());
	}

	void SpecialOperation2( MyWrite <T> *Ans1, int files, std::vector<FileStorage<T>*> &F) {
		for (int i = files - 1; i >= 0; i--) {
			getDataFromFile(F.back());
			F.back()->closeFile();
			delete F.back();
			F.pop_back();
			putDataToSourceFromVector(Ans1);
		}
	}
};


template <typename T>
class MySort : public MySamePart <T> {
private:
	int count;   //maximum file size
	int iterator;
	struct Element {
		T value = 0;
		int number = 0;

		bool operator < (const Element &it) const {
			return (value > it.value);
		}
	};
public:

	MySort(int size): MySamePart(size) {
		count = size;
	}

	~MySort() { }

	void SpecialOperation1(std::vector<T> &data) {
		std::sort(data.begin(), data.end());
	}

	void SpecialOperation2(MyWrite<T> *Ans1, int files, std::vector<FileStorage<T>*> &F) {

		std::priority_queue <Element> heap;
		Element New;
		T val;
		for (int i = 0; i < files; i++) {
			F[i]->openForRead();
		}

		for (int i = 0; i < files; i++) {
			F[i]->getElement(val);
			if (F[i]->sizeFile() > 0) {
				New.value = val;
				New.number = i;
				heap.push(New);
			}
		}

		while (heap.size() > 0) {
			New = heap.top();
			heap.pop();
			Ans1->put(New.value);

			if (F[New.number]->sizeFile() > 0) {
				F[New.number]->getElement(val);
				New.value = val;
				heap.push(New);
			}

		}
		for (int i = 0; i < files; i++) {
			F[i]->closeFile();
			delete F[i];
		}
	}
};
