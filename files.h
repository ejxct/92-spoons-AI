#ifndef UPDATE_H
#define UPDATE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class files{
    std::string edit;
    std::string name;
public:
    int size;
    std::vector<std::string> first;
    std::vector<std::string> second;
    std::fstream file;
    void operator+=(std::string add);
    [[deprecated("Use += instead")]] void add(std::string edit);
    [[deprecated("Use += instead")]] void keepline(std::string edit);
    void fileopen(std::string filename = " ");
    void read();
    void close();
    void reload();
    void start();
    void end();
    int checksize();
    void load(std::string loadname);
};
#endif
