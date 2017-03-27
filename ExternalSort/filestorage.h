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
class FileStorageBase
{
protected:
	std::string fname(int number, std::string& dir) const {
		char p[8];
		_itoa(number, p, 10);
		std::string str = dir + std::string("file") + std::string(p) + std::string(".txt");
		return str;
	}
	std::string filename;
public:
	int sizeF;

	FileStorageBase() {
		sizeF = 0;
	}

	void nameFile(int name, std::string& dir) {
		filename = fname(name, dir);
	}

//open for reading
	virtual void openForRead() = 0;
//open for writing
	virtual void openForWrite() = 0;
//write value
	virtual void putElement(const T& value) = 0;
//read value
	virtual void getElement(T &value) = 0;

	virtual void closeFile() = 0;
//reserve function for different situations
	virtual void deleteFile() = 0;

	virtual ~FileStorageBase() {}
};
/*
template<typename T>
class FileStorage : public FileStorageBase<T> {
private:
    std::fstream file;

public:

    int sizeF;

    FileStorage() {
        sizeF = 0;
    }

    void openForRead() {//open for reading
        file.open(filename, std::ios_base::in);
    }

    void openForWrite() {//open for writing
        file.open(filename, std::ios_base::out);
    }

    void putElement(const T& value) {//write value
        file << value << " ";
        sizeF++;
    }

    void getElement(T &value) {//read value
        file >> value;
        sizeF--;
    }

    void closeFile() {
        file.close();
    }

    void deleteFile() {//reserve function for different situations
        std::remove(filename.c_str());
    }

    ~FileStorage() {
        std::remove(filename.c_str());
    }

};

template<>
void FileStorage<char>::putElement(const char& value) {
    file << value;
    sizeF++;
}
*/
template<typename T>
class FileStorage : public FileStorageBase<T> {
private:
	FILE* file;
	size_t sizeF;
public:

	FileStorage() {
		sizeF = 0;
	}

	size_t sizeFile() const {
		return sizeF;
	}
	void openForRead() {//open for reading
		file = fopen(filename.c_str(), "rb");
	}

	void openForWrite() {//open for writing
		file = fopen(filename.c_str(), "wb+");
	}

	void putElement(const T& value) {//write value
		fwrite(&value, sizeof(T), 1, file);
		sizeF++;
	}

	void getElement(T &value) {//read value
		fread(&value, sizeof(T), 1, file);
        sizeF--;
	}

	void closeFile() {
		fclose(file);
	}

	void deleteFile() {//reserve function for different situations
		std::remove(filename.c_str());
	}

	~FileStorage() {
		std::remove(filename.c_str());
	}

};

/*template <>
void FileStorage<char>::putElement(const char &value) {
	file << value;
	sizeF++;
}*/