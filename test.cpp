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
    test.close();
    if(debug){
        cout<<"File opening test passed!"<<endl;
    }
    //add read debug
    test.fileopen();
    string testread;
    getline(test.file,testread);
    if (testread!="92spoons AI header"){
        cout<<"File reading test failed!"<<endl;
        return -1;
    }
    cout<<"File reading test passed!"<<endl;
    srand(time(NULL));
    string name = "test"+to_string(rand());
    test.add((name+":test").c_str());
    test.close();
    test.read();
    vector<string>::iterator it;
    it = find (test.first.begin(), test.first.end(), name);
    if (it == test.first.end()){
        cout<<"File writing test failed!"<<endl;
        return -1;
    }else{
        //TODO: Fix this conversion error
        long nPosition = distance (test.first.begin (), it);
        if (debug){
        cout << "File writing test passed!"<<endl;
        }
    }
}
