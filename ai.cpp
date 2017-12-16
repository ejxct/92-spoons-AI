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
void sleepcp(unsigned milliseconds){
#ifdef WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif // win32
}
    void load(/*int size*/){
        float progress = -0.01;
        int time = 100;
        /*if (size<100){
            time = size*0.5;
        }
        if (size<1000&&size>100){
            time = size*0.05;
        }
        if (size>1000){
            time = size*0.01;
        }*/
        while (progress < 1.0) {
            progress += 0.01;
            unsigned barWidth = 70;
            
            std::cout << '[';
            int pos = barWidth * progress;
            for (int i = 0; i < barWidth; ++i) {
                if (i < pos) std::cout << '=';
                else if (i == pos) std::cout << '>';
                else std::cout << ' ';
            }
            std::cout << "] " << int(progress * 100.0) << " %\r";
            std::cout.flush();
            sleepcp(time);
        }
        std::cout << endl;

    }
int main () {
    //load default conf
    files conf;
    conf.filename="default.92ai";
    //conf.checksize();
    thread loadbar (load/*,conf.size*/);
    conf.read();
    loadbar.join();
    std::cout << "Welcome to the 92 Spoons AI interface!"<<std::endl<<"If you need a tour around, say 'tour'."<<std::endl;
    while(true){
        std::string q;
        //allows for spaces in commands
        std::getline(std::cin,q);
        if (q=="exit"){
            return 0;
        }else{
            if (q=="reload"){
                conf.reload();
                }
        else{
                if (q=="load"){
                    //not tested
                    std::cout<<"What file shall I load?"<<std::endl;
                    std::string file2load;
                    std::cin>>file2load;
                    files file2;
                    file2.filename=file2load;
                    }
            else{
                    if (q=="import"){
                        std::cout<<"What file shall I import?"<<std::endl;
                        std::string file2load;
                        std::cin>>file2load;
                        std::fstream file2;
                        file2.open(file2load);
                        std::string line;
                        while(std::getline(file2,line)){
                            conf.add(line);
                            //lets hope this works i.e. not tested
                        }
                    }else{
        if (q=="write"){
            std::string edit;
            std::getline(std::cin,edit);
            conf.add(edit);
        }else{
            if (q=="tour"){
                std::cout<<"Hi!"<<std::endl<<"You can type something and this AI will respond!"<<std::endl<<"If you want to make a new command, type write."<<std::endl<<"Then type what you expect a user to type, like llama."<<std::endl<<"Then, type a colon."<<std::endl<<"Finally, tell me what I should say to respond."<<std::endl<<"For example, llama:No, llama, no!"<<std::endl;
            }else{
                vector<string>::iterator it;
                it = find (conf.first.begin(), conf.first.end(), q);
                if (it != conf.first.end()){
                    //TODO: Fix this conversion error
                    long nPosition = distance (conf.first.begin (), it);
                    std::cout << conf.second.at(nPosition)<<std::endl;
                }else{
                    std::cout << "Not found!" <<std::endl;
            }
        }
    }
    }
        }
        }
}
    }
        return 0;
}
