#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <thread>
#include <unistd.h>
#include "files.h"
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32
using namespace std;
void sleepcp(int milliseconds){
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
            int barWidth = 70;
            
            cout << "[";
            int pos = barWidth * progress;
            for (int i = 0; i < barWidth; ++i) {
                if (i < pos) cout << "=";
                else if (i == pos) cout << ">";
                else cout << " ";
            }
            cout << "] " << int(progress * 100.0) << " %\r";
            cout.flush();
            sleepcp(time);
        }
        cout << endl;

    }
int main () {
    //load default conf
    files conf;
    conf.filename="default.92ai";
    //conf.checksize();
    thread loadbar (load/*,conf.size*/);
    conf.read();
    loadbar.join();
    cout << "Welcome to the 92 Spoons AI interface!"<<endl<<"If you need a tour around, say 'tour'."<<endl;
    while(true){
        string q;
        //allows for spaces in commands
        getline(cin,q);
        if (q=="exit"){
            return 0;
        }else{
            if (q=="reload"){
                conf.reload();
                }
        else{
                if (q=="load"){
                    //not tested
                    cout<<"What file shall I load?"<<endl;
                    string file2load;
                    cin>>file2load;
                    files file2;
                    file2.fileset(file2load);
                    }
            else{
                    if (q=="import"){
                        cout<<"What file shall I import?"<<endl;
                        string file2load;
                        cin>>file2load;
                        fstream file2;
                        file2.open(file2load);
                        string line;
                        while(getline(file2,line)){
                            conf.add(line);
                            //lets hope this works i.e. not tested
                        }
                    }else{
        if (q=="write"){
            string edit;
            getline(cin,edit);
            conf.add(edit);
        }else{
            if (q=="tour"){
                cout<<"Hi!"<<endl<<"You can type something and this AI will respond!"<<endl<<"If you want to make a new command, type write."<<endl<<"Then type what you expect a user to type, like llama."<<endl<<"Then, type a colon."<<endl<<"Finally, tell me what I should say to respond."<<endl<<"For example, llama:No, llama, no!"<<endl;
            }else{
                vector<string>::iterator it;
                it = find (conf.first.begin(), conf.first.end(), q);
                if (it != conf.first.end()){
                    //TODO: Fix this conversion error
                    int nPosition = distance (conf.first.begin (), it);
                    cout << conf.second.at(nPosition)<<endl;
                }else{
                    cout << "Not found!" <<endl;
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
