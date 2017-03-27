
#include "iworker.h"
#include "myheap.h"
#include <vector>

template<typename T>
class MyReverse1 {
public:
    MyReverse1() { }

    ~MyReverse1() { }

    void getAnswer(int size) {

        IWorker<T> Work(size);
        IDataSourceRead<T> S;
        IDataSourceWrite<T> Ans;
        IDataSourceRead<T> *S1 = &S;
        IDataSourceWrite<T> *Ans1 = &Ans;
        FileStorage<T> F[1000];

        S.iDataOpen();
        Ans.iDataOpen();

        int files = 0;//how much files do we have

        while (S.isEmpty()) {

            Work.getDataFromSourceToVector(S1);
            Work.Reverse();
            F[files].nameFile(files);
            Work.putDataToFile(F + files);
            files++;
        }
        for (int i = files - 1; i >= 0; i--) {
            Work.getDataFromFile(F + i);
            Work.putDataToSourceFromVector(Ans1);
        }

    }

};


template<typename T>
class MySort {
public:
	MySort() { }

	~MySort() { }
	void getAnswer(int size) {

		IWorker<T> Work(size);
		IDataSourceRead<T> S;
		IDataSourceWrite<T> Ans;
		IDataSourceRead<T> *S1 = &S;
		IDataSourceWrite<T> *Ans1 = &Ans;
		FileStorage<T> F[1000];
		T val;
		Heap <T> heap;
		int files = 0;//how much files do we have
		int e;

		S.iDataOpen();
		Ans.iDataOpen();

		while (S.isEmpty()) {

			Work.getDataFromSourceToVector(S1);
			Work.SmallSort();
			F[files].nameFile(files);
			Work.putDataToFile(F + files);
			files++;
		}

		for (int i = 0; i < files; i++) {
			F[i].openForRead();
		}

		for (int i = 0; i < files; i++) {
			F[i].getElement(val);
			heap.push(val, i);
		}
		
		while (heap.n > 0) {
			val = heap.min(e);
			heap.extractMin();
			Ans.put(val);
			if (F[e].sizeF > 0) {
				F[e].getElement(val);
				heap.push(val, e);
			}
		
		}
		for (int i = 0; i < files; i++) {
			F[i].closeFile();
		}
	}


};
