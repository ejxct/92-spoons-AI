#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <thread>
#include <unistd.h>
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
using namespace std;
int main(){
    files test;
    test.filename="default.92ai";
    if(test.filename!="default.92ai"){
        if(debug){
            cout<<"Var storage test failed! Here is what the var was instead:"<<test.filename<<endl;
        }
        return -1;
    }
    if(debug){
        cout<<"Var storage test passed!"<<endl;
    }
    test.fileopen();
    if(test.file.bad()){
        cout<<"File opening test failed!"<<endl;
        return -1;
    }
    if(debug){
        cout<<"File opening test passed!"<<endl;
    }
}
