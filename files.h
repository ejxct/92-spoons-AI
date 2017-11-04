#ifndef UPDATE_H
#define UPDATE_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;
class files{
    string edit;
public:
    int size;
    vector<string> first;
    vector<string> second;
    fstream file7,file;
    string filename;
    void add(string edit);
    void keepline(string edit);
    void fileopen();
    void read();
    void close();
    void reload();
    void start();
    void end();
    int checksize();
    void load(string loadname);
};
int files::checksize(){
    fstream filesize;
    filesize.open(fileset2,ios::binary);
    streampos begin,end;
    begin = filesize.tellg();
    filesize.seekg (0, ios::end);
    end = filesize.tellg();
    int size = end-begin;
    //if you hate warnings
    /**psize++;
    *psize--;*/
    files::start();
    return size;
}
void files::start(){
    fstream *pfile;
    pfile = &file;
    (*pfile).seekg (0, ios::beg);
}
void files::end(){
    fstream *pfile;
    pfile = &file;
    (*pfile).seekg (0, ios::end);
}
void files::fileopen(){
    fstream *pfile;
    pfile = &file;
    (*pfile).open(filename);
}
void files::add(string edit){ //for experienced users
    fstream filewrite;
    filewrite.open(filename);
    filewrite.seekg(0,ios::end);
    filewrite << edit <<endl;
    filewrite.close();
}
void files::keepline (string edit){
    fstream filewrite;
    filewrite.open(filename);
    filewrite << edit;
    filewrite.close();
}
void files::read(){
    files::fileopen();
    fstream *pfile;
    pfile = &file;
    vector<string> *pfirst;
    pfirst = &first;
    vector<string> *psecond;
    psecond = &second;
    string line;
    string header;
    while (getline(*pfile,line)){
        stringstream split (line);
        string one;
        string two;
        getline(split,one,':');
        (*pfirst).push_back(one);
        getline(split,two);
        (*psecond).push_back(two);
    }
    if (first.at(0)!="92spoons AI header"){
        cout<<"Oh no! A file was loaded that does not have a correct header. Make sure you loaded a 92ai file, and that you didn't make a typo on the header."<<endl;
        //cout<<"|"<<header<<"|";
        exit(1);
    }
}
void files::close(){
    fstream *pfile;
    pfile = &file;
    (*pfile).close();
}
void files::reload(){
    vector<string> *pfirst;
    pfirst = &first;
    vector<string> *psecond;
    psecond = &second;
    files::close();
    (*pfirst).clear();
    (*psecond).clear();
    files::read();
}
void files::load(string loadname){
    files file2;
    file2.fileset(loadname);
    string line;
    string header;
    getline(file2.file,header);
    if (header!="92spoons AI header"){
        cout<<"Oh no! A file was loaded that does not have a correct header. Make sure you loaded a 92ai file, and that you didn't make a typo on the header."<<endl;
        exit(1);
    }
    while (getline(file2.file,line)){
        stringstream split (line);
        string one;
        string two;
        getline(split,one,':');
        first.push_back(one);
        getline(split,two);
        second.push_back(two);
}
}
#endif
