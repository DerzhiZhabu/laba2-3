#include <string>
#include <iostream>
#include <sstream>
#include "fileparce.h"
#include "set.h"

using namespace std;

void commandhandler(string& filename, string& dquery);
void work_set(string& word, stringstream& query, string& filename, string& command);

int main(int argc, char* argv[]) {
    try{
        string file;
        string query;

        for (int i = 1; i < argc; ++i) {
            string arg = argv[i];

            if (arg == "--file" && i + 1 < argc) {
                file = argv[++i];
            } else if (arg == "--query" && i + 1 < argc) {
                query = argv[++i];
            }
        }

        commandhandler(file, query);
    }catch(runtime_error err){
        cerr << err.what() << endl;
    }

    return 0;
}

void commandhandler(string& filename, string& dquery){
    stringstream query;
    query << dquery;

    string word;
    string command;
    query >> command;

    if (command[0] == 'S'){
        work_set(word, query, filename, command);
    }

}


template <typename T>
void printList(T values){
    for(int i = 0; i < values.length; i++){
        cout << values[i] << ' ';
    }
}


void work_set(string& word, stringstream& query, string& filename, string& command){
    Myset res;
    Myset new_res;
    query >> word;

    find_values_in_file(filename, word, new_res);

    if (command == "SADD"){
        int value;
        query >> value;

        new_res.Add(value);

        rewrite_values_in_file_Odn(filename, word, new_res);
    }else if (command == "SDEL"){
        int value;
        query >> value;

        new_res.Remove(value);

        rewrite_values_in_file_Odn(filename, word, new_res);
    }else if (command == "SAT"){
        int value;
        query >> value;

        cout << new_res.Get(value) << endl;
    }
}