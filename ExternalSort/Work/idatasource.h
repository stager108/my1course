#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <cassert>
#include <ios>
template<typename T>
class  IDataSourceRead {
	bool hasNext() = 0;
	T get() = 0;
};

template<typename T>
class  IDataSourceWrite {
	void put(const T &element) = 0;
};

template<typename T>
class MyRead: public IDataSourceRead<T> {
private:
    std::fstream fil;
public:

	MyRead() { }

    void MyReadOpen() {
        char a[20];
        std::cout << "Enter input file's name:'" << std::endl;
        //std::gets(a);
		std::cin >> a;
        fil.open(a, std::ios_base::in);
    }

    void get(T &value) {
        fil >> value;
    };

    void MyReadClose() {
        fil.close();
    }

    bool hasNext() {
        return (bool)fil;
    }

    ~MyRead() {
        fil.close();
    }

};

template<typename T>
class MyWrite: public IDataSourceWrite <T>{
private:
    std::fstream ans;
public:
	MyWrite() { }

    void MyWriteOpen() {
        char a[20];
        std::cout << "Enter output file's name:" << std::endl;
        //std::gets(a);
		std::cin >> a;
        ans.open(a, std::ios_base::out);
    }

    void put(T value) {
        ans << value << " ";
    };

    void iDataClose() {
        ans.close();
    }

    ~MyWrite() {
        ans.close();
    }

};

template<>
void MyWrite<char>::put(char value) {
    ans << value;
}
