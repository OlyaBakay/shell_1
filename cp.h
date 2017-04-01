//
// Created by bakay on 4/1/17.
//

#ifndef SHELL_1_CP_H
#define SHELL_1_CP_H

#endif //SHELL_1_CP_H

#include <string>
using namespace std;
namespace fs = boost::filesystem;

bool cp(string copy_from, string copy_to) {

    std::vector<std::string> lines;
    boost::split(lines, copy_from, boost::is_any_of("/"));

    string g;
    vector<string> lst;
    string s1 = "";
    string name_of_file = lines[lines.size() - 1];

    for (int i = 1; i < lines.size() - 1; i++){
        g += '/';
        g += lines[i];
    }
    if (fs::is_directory(g)) {      // check if the given string contains right directory

        string s = "";
        size_t num_of_br = count(copy_from.begin(), copy_from.end(), '{') +
                           count(copy_from.begin(), copy_from.end(), '}');     //calculate amount of {} in copy_from

        if (num_of_br == 2) {       // copy_from contains more than one file to copy
            int i = 0;
            while (i != name_of_file.length()) {
                if (name_of_file[i] == '{') {
                    s = name_of_file.substr(i + 1, name_of_file.length() - 2);      // string of names of files to copy
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
                string directory = g + "/";         //form full directory to the file
//            cout << i << " : " << lst[i] << endl;
                directory += lst[i];
//                cout << directory << endl;
//                cout << copy_to << endl;
                fs::path source_path(directory);
                fs::path destination_path(copy_to);
                fs::copy_file(source_path, destination_path, fs::copy_option::overwrite_if_exists);
//            /// cp /home/bakay/Downloads/{text.txt list.txt te.txt} /home/bakay/folder/
            }
        }

        fs::path source_path(copy_from);
        fs::path destination_path(copy_to);
        fs::copy_file(source_path, destination_path, fs::copy_option::overwrite_if_exists);
    }
    else
        cout << "No such directory!"<< endl;

}