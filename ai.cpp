// basic file operations
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <thread>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32
using namespace std;
void sleepcp(int milliseconds) // Cross-platform sleep function
{
#ifdef WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif // win32
}
    void load(int size){
        float progress = -0.1;
        while (progress < 1.0) {
            progress += 0.1;
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
            sleepcp((size*5));
            // for demonstration only
            
        }
        cout << endl;

    }
int write (string filename){
    //NOTE: THIS WILL APPEND
    string edit;
    cin.ignore();
    getline(cin,edit);
    fstream file;
    file.open (filename,ios::app);
    file << edit <<endl;
    file.close();
    cout<<"Run reload to add your new command"<<endl;
    return 0;
}
int main () {
    //load default conf
    fstream confsize;
    confsize.open("default.92ai");
    streampos begin,end;
    begin = confsize.tellg();
    confsize.seekg (0, ios::end);
    end = confsize.tellg();
    thread loadbar (load,(end-begin));
    //create vectors to store commands
    fstream conf;
    conf.open("default.92ai");
    string line;
    vector<string> first;
    vector<string> second;
    //TODO: Fix error that occurs when default.92ai is not a thing
    while (getline(conf,line)){
        stringstream split (line);
        string one;
        string two;
        getline(split,one,':');
        first.push_back(one);
        getline(split,two);
        second.push_back(two);
    }
    if (first.at(0)!="92spoons AI header"){
        cout<<"Oh no! A file was loaded that does not have a correct header. Make sure you loaded a 92ai file, and that you didn't make a typo on the header."<<endl;
        exit(1);
    }
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
                conf.close();
                fstream conf;
                conf.open("default.92ai");
                string line;
                first.clear();
                second.clear();
                while (getline(conf,line)){
                    stringstream split (line);
                    string one;
                    string two;
                    getline(split,one,':');
                    first.push_back(one);
                    getline(split,two);
                    second.push_back(two);
                }
                if (first.at(0)!="92spoons AI header"){
                    cout<<"Oh no! A file was loaded that does not have a correct header. Make sure you loaded a 92ai file, and that you didn't make a typo on the header."<<endl;
                    return 1;
                }
            }else{
                if (q=="load"){
                    //not tested
                    cout<<"What file shall I load?"<<endl;
                    string file2load;
                    cin>>file2load;
                    fstream file2;
                    file2.open(file2load);
                    string line;
                    while (getline(file2,line)){
                        stringstream split (line);
                        string one;
                        string two;
                        getline(split,one,':');
                        first.push_back(one);
                        getline(split,two);
                        second.push_back(two);
                    }
                }else{
        if (q=="write"){
            write("default.92ai");
        }else{
            if (q=="tour"){
                cout<<"Hi!"<<endl<<"You can type something and this AI will respond!"<<endl<<"If you want to make a new command, type write."<<endl<<"Then type what you expect a user to type, like llama."<<endl<<"Then, type a colon."<<endl<<"Finally, tell me what I should say to respond."<<endl<<"For example, llama:No, llama, no!"<<endl;
            }else{
                vector<string>::iterator it;
                it = find (first.begin(), first.end(), q);
                if (it != first.end()){
                    //TODO: Fix this conversion error
                    int nPosition = distance (first.begin (), it);
                    cout << second.at(nPosition)<<endl;
                }else{
                    cout << "Not found!" <<endl;
                }
            }
        }
    }
    }
        }
    }
    //write("\ntest","default.92ai");
    return 0;
}
