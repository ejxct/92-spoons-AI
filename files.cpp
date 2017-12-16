#include "files.h"

int files::checksize(){
    std::fstream infile{filename, std::ios::ate | std::ios::binary};
    return infile.tellg();
}
void files::start(){
    std::fstream *pfile;
    pfile = &file;
    pfile->seekg (0, std::ios::beg);
}
void files::end(){
    std::fstream *pfile;
    pfile = &file;
    pfile->seekg (0, std::ios::end);
}
void files::fileopen(){
    std::fstream *pfile;
    pfile = &file;
    pfile->open(filename);
}
void files::add(std::string edit){ //for experienced users
    std::fstream filewrite;
    filewrite.open(filename);
    filewrite.seekg(0,std::ios::end);
    filewrite << edit <<'\n';
    filewrite.close();
}
void files::keepline (std::string edit){
    std::fstream filewrite;
    filewrite.open(filename);
    filewrite << edit;
    filewrite.close();
}
void files::read(){
    files::fileopen();
    std::fstream *pfile;
    pfile = &file;
    std::vector<std::string> *pfirst;
    pfirst = &first;
    std::vector<std::string> *psecond;
    psecond = &second;
    std::string line;
    std::string header;
    while (getline(*pfile,line)){
        std::stringstream split (line);
        std::string one;
        std::string two;
        getline(split,one,':');
        pfirst->push_back(one);
        getline(split,two);
        psecond->push_back(two);
    }
    if (first.at(0)!="92spoons AI header"){
        std::cout<<"Oh no! A file was loaded that does not have a correct header. Make sure you loaded a 92ai file, and that you didn't make a typo on the header.\n";
        //cout<<"|"<<header<<"|";
        exit(1);
    }
}
void files::close(){
    std::fstream *pfile;
    pfile = &file;
    pfile->close();
}
void files::reload(){
    std::vector<std::string> *pfirst;
    pfirst = &first;
    std::vector<std::string> *psecond;
    psecond = &second;
    files::close();
    pfirst->clear();
    psecond->clear();
    files::read();
}
void files::load(std::string loadname){
    files file2;
    file2.filename=loadname;
    std::string line;
    std::string header;
    getline(file2.file,header);
    if (header!="92spoons AI header"){
        std::cout<<"Oh no! A file was loaded that does not have a correct header. Make sure you loaded a 92ai file, and that you didn't make a typo on the header.\n";
        exit(1);
    }
    while (getline(file2.file,line)){
        std::stringstream split (line);
        std::string one;
        std::string two;
        getline(split,one,':');
        first.push_back(one);
        getline(split,two);
        second.push_back(two);
    }
}
