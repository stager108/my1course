#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <cassert>
#include <ios>

template<typename T>
class FileStorage {
private:
    std::string fname(int number) const {
        char p[8];
        _itoa(number, p, 10);
        std::string str = std::string("file") + std::string(p) + std::string(".txt");
        return str;
    }

    std::fstream file;
    std::string filename;

public:

    int sizeF;

    FileStorage() {
        sizeF = 0;
    }

    void nameFile(int name) {
        filename = fname(name);
    }


    void openForRead() {//open for reading
        file.open(filename.c_str(), std::ios_base::in);
    }

    void openForWrite() {//open for writing
        file.open(filename.c_str(), std::ios_base::out);
    }

    void putElement(T value) {//write value
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
void FileStorage<char>::putElement(char value) {
    file << value;
    sizeF++;
}
