#include "filestorage.h"
#include "idatasource.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <cassert>
#include <ios>
#include <vector>
#include <new>
//base type for working with data
template<typename T>
class IWorker {
private:
    int count;   //maximum file size
    int iterator;//size of file, vector, etc.
public:
    std::vector <T> data;

    IWorker(int number) {
        count = number; //maximum file size
    };

    void getDataFromFile(FileStorage<T> *D) {
        //put data from FileStorage to Vector
        T element;
        data.clear();
        (*D).openForRead();
        iterator = (*D).sizeF;
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
        for (int i = 0; (i < count) && ((*S).isEmpty()); i++) {
            (*S).get(value);
            (*F).putElement(value);
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

    void Reverse() {
        T el;
        int j = data.size();
        for (int i = 1; i - 1 < j - i; i++) {
            el = data[i - 1];
            data[i - 1] = data[j - i];
            data[j - i] = el;
        }
    }

   /* int compare (const void * a, const void * b)
    {
       return ( *(int*)a - *(int*)b );
    }*/
    
	void SmallSort() {
		std::vector <T> buffer;
		buffer.resize(data.size()+2, data[0] );
		//std::qsort(data, data.size(), sizeof(T), compare);
		MergeSort(0, data.size(), buffer);
		buffer.clear();
	}
	
	void MergeSort(int start, int finish, std::vector <T> buffer) {
		if (start + 1 < finish) {
			int l = start + (finish - start) / 2;//middle
			MergeSort(start, l, buffer);
			MergeSort(l, finish, buffer);
			int i = start, j = l, k = 0;// counts
			while ((i < l) && (j < finish)) {
				if (data[i] > data[j]) {
					buffer[k] = data[j];
					j++;
					k++;
				}
				else {
					buffer[k] = data[i];
					i++;
					k++;
				}
			}
			if (i < l) {
				for (int ii = i; ii < l; ii++) {
					buffer[k] = data[ii];
					k++;
				}
					
			}
			else//memcpy( buffer + k, data + j, sizeof(T) * (finish - j));
			{
				for (int ii = j; ii < finish; ii++) {
					buffer[k] = data[ii];
					k++;
				}
			}
			k = 0;
			for (int ii = start; ii < finish; ii++) {
				data[ii] = buffer[k]  ;
				k++;
			}
			//memcpy( data + start, buffer, sizeof(T) * (finish - start));

		}


	}
	
    // virtual void RebuilData() = 0;
    // virtual void GetAnswer() = 0;
    ~IWorker() {
    }
};
/*template <typename T>
class MyReverse: public IWorker <T> {
public: 

	std::vector <T> data; 
	
    void Reverse() {
    		j = data.size();
    		for(int i = 0; i < j - i; i++)
    		data.swap(i , j - i - 1);
	   }
                  

};*/
