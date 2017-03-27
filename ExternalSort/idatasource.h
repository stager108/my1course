#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <cassert>
#include <ios>
#include <string>

template<typename T>
class  IDataSourceRead {
public:
	virtual bool hasNext() = 0;
	virtual void get(T &value) = 0;
};

template<typename T>
class  IDataSourceWrite {
public:
	virtual void put(const T &element) {}
};

template<typename T>
class MyRead: public IDataSourceRead <T> {
private:
    std::fstream fil;

	void MyReadOpen() {
		char a[20];
		std::cout << "Enter input file's name:'" << std::endl;
		//std::gets(a);
		std::cin >> a;
		fil.open(a, std::ios_base::in);
	}

public:

	explicit MyRead(const std::string& filename) {
		//MyReadOpen();
		fil.open(filename, std::ios_base::in);
	}

    

    void get(T &value) {
        fil >> value;
    };

    bool hasNext() {
        return (bool)fil;
    }

    ~MyRead() {
        fil.close();
    }

};

template<typename T>
class MyWrite: public IDataSourceWrite <T> {
private:
    std::fstream ans;
public:
	explicit MyWrite(const std::string& filename) {
		//MyWriteOpen();
		ans.open(filename, std::ios_base::out);
	}

    void MyWriteOpen() {
        char a[20];
        std::cout << "Enter output file's name:" << std::endl;
        //std::gets(a);
		std::cin >> a;
        ans.open(a, std::ios_base::out);
    }

    void put(const T &value) {
        ans << value << " ";
    };

    ~MyWrite() {
        ans.close();
    }

};

template<>
void MyWrite<char>::put(const char &value) {
    ans << value;
}

template<typename T>
class MySerializeRead : public IDataSourceRead <T> {
private:
	FILE *fil;
public:

	explicit MySerializeRead(std::string& filename) {
		fil = fopen(filename, "rb");
	}

	void get(T &value) {
		fread(&value, sizeof(T), 1, fil);
	}

	bool hasNext() {
		return !feof(fil);
	}

	~MySerializeRead() {
		fclose(fil);
	}
};

template<typename T>
class MySerializeWrite : public IDataSourceWrite <T> {
private:
	FILE* fil;
public:
	explicit MySerializeWrite(std::string& filename) {
		fil = fopen(filename, "wb+");
	}

	void put(const T &value) {
		fwrite(&value, sizeof(T), 1, fil);
	}

	~MySerializeWrite() {
		fclose(fil);
	}

};