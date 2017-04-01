#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <dirent.h>
#include <sstream>
#include <cstring>
#include <vector>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <string>
#include <algorithm>
#include "cp.h"

using namespace std;
namespace fs = boost::filesystem;


//char *curr_dir = (char *) "/usr/bin";
//char dir[100];
string curr_dir = "/usr/bin";
string a = "";
string cm = "";

string LastDir(){//повертає останнє знач директорії

    std::vector<std::string> strs;
    boost::split(strs, curr_dir, boost::is_any_of("/"));
    return strs[strs.size()-1];

}
string CheckDot(){
    std::vector<std::string> strs;
    boost::split(strs, curr_dir, boost::is_any_of("/"));
    if (strs[0] == ".."){
        cout << "true" <<endl;
        return "true";
    }else{
        cout << "false"<<endl;
        return "false";
    }
}

void deleteLast(){
    string g = "";
    std::vector<std::string> strs;
    boost::split(strs, curr_dir, boost::is_any_of("/"));
    for (int i=0; i<strs.size()-1; i++){
        g+=strs[i];
    }
    cout<<g<<endl;


}


void splitString( string line){
    int i = 0;
    while(i != line.length()){
        if(line[i] == ' '){
            cm = line.substr(0,i);
            a = line.substr(i+1, line.length() - 1);
            break;
        }else{
            cm = line;
        }
        i++;
    }
}

int cd(){
    string args = a;

    string g = "";
    std::vector<std::string> strs;//arguments
    boost::split(strs, args, boost::is_any_of("/"));


    std::vector<std::string> lines;//curr_dir
    boost::split(lines, curr_dir, boost::is_any_of("/"));


    if (strs[0] == ".."){
        for (int i=1; i<lines.size()-1; i++){
            g+='/';
            g+=lines[i];
        }
        curr_dir = g;
        cout<<curr_dir<<endl;
    }else if (strs[0] == "."){
        cout<<"not done yet"<<endl;
    }



    else if (fs::is_directory(args)){
        chdir(args.c_str());
        curr_dir += args;
    }


    return 0;

}
int main(int argc, char* argv[], char**env)
{
    string input = "";



    while(true)  {
        cout << "> " << endl;
        getline(cin , input);
        splitString(input);

        if (cm == "pwd"){

            cout << curr_dir;
        }
//        else if ( input == "ls"){
//            ls();
//
//        }
        else if(cm == "cd") {
            cd();
        }
        else if (cm == "cp") {
            int pos = a.find(" /");
            string ar = a;
            string from = ar.substr(0, pos);
            string to = ar.substr(pos+1, a.length() - 1);
            cout << "from: " << from << "   to: " << to << endl;
            cp(from, to);

        }
        else if(cm == "exit"){
            break;
        }

        cout << "\n";

    }

    return 0;

}