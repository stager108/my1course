#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <iostream>
#include <vector>
#include <ios>
#include <new>
#include "filestorage.h"
#include "idatasource.h"

template<typename T>
class  IWorker {
public:
	virtual void getDataFromFile(FileStorage<T> *D) = 0;
	virtual void putDataToFile(FileStorage<T> *D) = 0;
	virtual void getDataFromSource(FileStorage<T> *F, IDataSourceRead<T> *S) = 0;
	virtual void putDataToSourceFromVector(IDataSourceWrite<T> *S) = 0;
	virtual void getDataFromSourceToVector(IDataSourceRead<T> *S) = 0;

};
//base type for working with data
template <typename T>
class MyWorker: public IWorker <T> {
private:
    int count;   //maximum file size
    int iterator;//size of file, vector, etc.
	
protected:
	std::vector <T> data;
public:
    MyWorker(int number) {
        count = number; //maximum file size
    };

    void getDataFromFile(FileStorage<T> *D) {
        //put data from FileStorage to Vector
        T element;
        data.clear();
        (*D).openForRead();
        iterator = (*D).sizeFile();
        for (int i = 0; i < iterator; i++) {
            (*D).getElement(element);
            data.push_back(element);
        }
        (*D).closeFile();
    }

    void putDataToFile(FileStorage<T> *D) {
        //put data from Vector to FileStorage
        (*D).openForWrite();
        iterator = data.size();
        for (int i = 1; i <= iterator; i++) {
            (*D).putElement(data[i - 1]);
        }
        (*D).closeFile();
        data.clear();
    }

    void getDataFromSource(FileStorage<T> *F, IDataSourceRead<T> *S) {
        //put data from Sourse File to FileStorage
        (*F).openForWrite();
        T value;
		(*S).get(value);
        for (int i = 1; (i < count) && ((*S).hasNext()); i++) {
			(*F).putElement(value);
			(*S).get(value);
        }

        (*F).closeFile();

    }

    void putDataToSourceFromVector(IDataSourceWrite<T> *S) {
        //put data from Vector to Answer File
        iterator = data.size();
        for (int i = 1; i <= iterator; i++) {
            (*S).put(data[i - 1]);
        }
        data.clear();
    }


    void getDataFromSourceToVector(IDataSourceRead<T> *S) {
        //put data from Sourse File to Vector
        T value;
        data.clear();
        for (int i = 0; (i < count) && ((*S).hasNext()); i++) {
            (*S).get(value);
            data.push_back(value);
        }
        if (!(*S).hasNext()) {
            data.pop_back();
        }
    }
    ~MyWorker() {
    }
};


