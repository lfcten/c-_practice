//
// Created by lifeicheng on 2019/3/31.
//

#ifndef CHAPTER_1_INDEX_H
#define CHAPTER_1_INDEX_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <regex>

using std::map;
using std::vector;
using std::string;
using std::smatch;
using std::ifstream;
using std::ofstream;

namespace chapter_1 {
    struct PersonInfo {
        string name;
        vector<string> phones;
    };

    class PhoneProcess {
    public:
        string format(const string &s);

        bool valid(const smatch &m);

        vector<PersonInfo> get_data(ifstream &is);

        int process(ofstream &os, vector<PersonInfo> people);
    };
}
#endif //CHAPTER_1_INDEX_H
