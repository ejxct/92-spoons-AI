#ifndef UPDATE_H
#define UPDATE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class files{
    std::string edit;
public:
    int size;
    std::vector<std::string> first;
    std::vector<std::string> second;
    std::fstream file;
    std::string filename;
    void add(std::string edit);
    void keepline(std::string edit);
    void fileopen();
    void read();
    void close();
    void reload();
    void start();
    void end();
    int checksize();
    void load(std::string loadname);
};
#endif
