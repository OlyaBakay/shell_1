//
// Created by bakay on 4/1/17.
//

#ifndef SHELL_1_CP_H
#define SHELL_1_CP_H

#endif //SHELL_1_CP_H

#include <string>
#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>
#include <iostream>

using namespace std;
namespace fs = boost::filesystem;

bool cp(string copy_from, string copy_to) {
    string s_path, d_path;
    vector<string> lst;
    string s1 = "";

    std::vector<std::string> source_path;
    boost::split(source_path, copy_from, boost::is_any_of("/"));

    std::vector<std::string> destination_path;
    boost::split(destination_path, copy_to, boost::is_any_of("/"));

    string source_file_name = source_path[source_path.size() - 1];

    for (int i = 1; i < source_path.size() - 1; i++){           // directory to copy from
        s_path += '/';
        s_path += source_path[i];
    }

    for (int i = 1; i < destination_path.size() - 1; i++){      // directory to copy in
        d_path += '/';
        d_path += destination_path[i];
    }

    if (fs::is_directory(s_path) && fs::is_directory(d_path)) {      // check if the given string contains right directory
//        cout << "check" << endl;
        string s = "";
        size_t num_of_br = count(copy_from.begin(), copy_from.end(), '{') +
                           count(copy_from.begin(), copy_from.end(), '}');     //calculate amount of {} in copy_from

        if (num_of_br == 2) {       // copy_from contains more than one file to copy

            int i = 0;
            while (i != source_file_name.length()) {
                if (source_file_name[i] == '{') {
                    s = source_file_name.substr(i + 1, source_file_name.length() - 2);      // string of names of files to copy
                    break;
                }
                i++;

            }

            for (int i = 0; i <= s.length(); ++i) {

                if (s[i] != ' ' && i != s.length()) {
                    s1 += s[i];             // form a string - name of a file to add to lst
                } else {
                    lst.push_back(s1);      // vector that contains all names of files to be copied
                    s1 = "";
                }

            }

            for (size_t i = 0; i < lst.size(); ++i) {
                string s_directory = s_path + "/";         // form full directory to the file
                string d_directory = d_path + "/";         // form full directory to the copied file

                s_directory += lst[i];                     // add name of file to the directory
                d_directory += lst[i];                     // add name of file to the directory

                fs::path source(s_directory);
                fs::path destination(d_directory);
                fs::copy_file(source, destination, fs::copy_option::overwrite_if_exists);
            }

        }
        else {
            fs::path source(copy_from);
            fs::path destination(copy_to);
            fs::copy_file(source, destination, fs::copy_option::overwrite_if_exists);
        }
    }
    else
        cout << "No such directory!"<< endl;

}