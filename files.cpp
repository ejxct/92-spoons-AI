#include "files.h"
#include <cstdlib>
#include <fstream>
//checks size of file. does not work
int files::checksize(){
    std::fstream infile{name, std::ios::ate | std::ios::binary};
    return infile.tellg();
}
//moves iterator to the start
void files::start(){
    std::fstream *pfile;
    pfile = &file;
    pfile->seekg (0, std::ios::beg);
}
//moves iterator to the end
void files::end(){
    std::fstream *pfile;
    pfile = &file;
    pfile->seekg (0, std::ios::end);
}
//opens file
void files::fileopen(std::string filename){
    if (name==""){
        if (filename==""){
            name = filename;
        }else{
            std::cerr<<"0 arguments found, 1 expected.";
        }
    }
    std::fstream *pfile;
    pfile = &file;
    pfile->open(filename);
}
//adds line in file
void files::add(std::string edit){ //for experienced users
    std::fstream filewrite;
    filewrite.seekg(0,std::ios::end);
    filewrite << edit <<'\n';
    filewrite.close();
}
//adds text to file
void files::operator+=(std::string add) {
    std::fstream *pfile;
    pfile = &file;
    *pfile << add;
}
//adds text to file
void files::keepline (std::string edit){
    std::fstream filewrite;
    filewrite.open(name);
    filewrite << edit;
    filewrite.close();
}
//reads file and puts it in vectors
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
        exit(1);
    }
}
//closes file. allows for confirmed saves
void files::close(){
    std::fstream *pfile;
    pfile = &file;
    pfile->close();
}
//reloads file
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
//loads other file
void files::load(std::string loadname){
    files file2;
    file2.fileopen(loadname);
    file2.read();
    std::string line;
    std::string header;
    std::vector<std::string> *pfirst;
    pfirst = &first;
    std::vector<std::string> *psecond;
    psecond = &second;
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
        pfirst->push_back(one);
        getline(split,two);
        psecond->push_back(two);
    }
}
