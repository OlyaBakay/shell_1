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

string LastDir(){//Ð¿Ð¾Ð²ÐµÑÑÐ°Ñ Ð¾ÑÑÐ°Ð½Ð½Ñ Ð·Ð½Ð°Ñ Ð´Ð¸ÑÐµÐºÑÐ¾ÑÑÑ

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


//bool cp(string copy_from, string copy_to) {
//
//    std::vector<std::string> lines;
//    boost::split(lines, copy_from, boost::is_any_of("/"));
//
//    string g;
//    vector<string> lst;
//    string s1 = "";
//    string name_of_file = lines[lines.size() - 1];
//
//    for (int i = 1; i < lines.size() - 1; i++){
//        g += '/';
//        g += lines[i];
//    }
//    if (fs::is_directory(g)) {      // check if the given string contains right directory
//
//        string s = "";
//        size_t num_of_br = count(copy_from.begin(), copy_from.end(), '{') +
//                           count(copy_from.begin(), copy_from.end(), '}');     //calculate amount of {} in copy_from
//
//        if (num_of_br == 2) {       // copy_from contains more than one file to copy
//            int i = 0;
//            while (i != name_of_file.length()) {
//                if (name_of_file[i] == '{') {
//                    s = name_of_file.substr(i + 1, name_of_file.length() - 2);      // string of names of files to copy
//                    break;
//                }
//                i++;
//
//            }
//
//            for (int i = 0; i <= s.length(); ++i) {
//                if (s[i] != ' ' && i != s.length()) {
//                    s1 += s[i];             // form a string - name of a file to add to lst
//                } else {
//                    lst.push_back(s1);      // vector that contains all names of files to be copied
//                    s1 = "";
//                }
//
//            }
//
//            for (size_t i = 0; i < lst.size(); ++i) {
//                string directory = g + "/";         //form full directory to the file
////            cout << i << " : " << lst[i] << endl;
//                directory += lst[i];
////                cout << directory << endl;
////                cout << copy_to << endl;
//                fs::path source_path(directory);
//                fs::path destination_path(copy_to);
//                fs::copy_file(source_path, destination_path, fs::copy_option::overwrite_if_exists);
////            /// cp /home/bakay/Downloads/{text.txt list.txt te.txt} /home/bakay/folder/
//            }
//        }
//
//        fs::path source_path(copy_from);
//        fs::path destination_path(copy_to);
//        fs::copy_file(source_path, destination_path, fs::copy_option::overwrite_if_exists);
//    }
//    else
//        cout << "No such directory!"<< endl;
//
//}
void ls() {
    fs::path p{a.length() > 1 ? a : curr_dir};
    if (is_directory(p)) {
        for (auto &entry : boost::make_iterator_range(fs::directory_iterator(p), {})) {
            cout << entry << "\n";
        }
    }
}


    void mkdir(){
        std::size_t found = a.find("/");
        if (found!=std::string::npos) {
            boost::filesystem::create_directories(curr_dir + a);
        } else {
            boost::filesystem::create_directory(curr_dir + a);
        }
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
    string input;

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
