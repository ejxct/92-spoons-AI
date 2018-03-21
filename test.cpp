#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <thread>
#include "files.h"
#ifdef __MINGW32__
#include <mingw.thread.h>
#endif
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32
#ifdef NODEBUG
bool debug = false;
#else
bool debug = true;
#endif
int main(){
    files test;
    test.filename="default.92ai";
    if(test.filename!="default.92ai"){
        if(debug){
            std::cout<<"Var storage test FAILED! Here is what the var was instead:"<<test.filename<<'\n';
        }
        return -1;
    }
    if(debug){
        std::cout<<"Var storage test passed!\n";
    }
    test.fileopen();
    if(test.file.bad()){
        std::cout<<"File opening test FAILED!\n";
        return -1;
    }
    test.close();
    if(debug){
        std::cout<<"File opening test passed!\n";
    }
    //add read debug
    test.fileopen();
    std::string testread;
    std::getline(test.file,testread);
    if (testread!="92spoons AI header"){
        std::cout<<"File reading test FAILED!\n";
        return -1;
    }
    std::cout<<"File reading test passed!\n";
    srand(time(NULL));
    std::string name = "test"+std::to_string(rand());
    test+=((name+":test\n").c_str());
    test.close();
    test.read();
    std::vector<std::string>::iterator it;
    it = find (test.first.begin(), test.first.end(), name);
    if (it == test.first.end()){
        std::cout<<"File writing test FAILED!\n";
        return -1;
    }else{
        //TODO: Fix this conversion error
        long nPosition = distance (test.first.begin(), it);
        if (debug){
            std::cout << "File writing test passed!\n";
        }
    }
}
