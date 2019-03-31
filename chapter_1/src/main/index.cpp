//
// Created by lifeicheng on 2019/3/31.
//
#include "index.h"
#include <sstream>

using std::regex;
using std::istringstream;
using std::ostringstream;
using std::endl;
using std::cerr;
using std::sregex_iterator;
using chapter_1::PersonInfo;
using chapter_1::PhoneProcess;

string PhoneProcess::format(const string &s) {
    return s;
}

bool PhoneProcess::valid(const smatch &m) {
    if (m[1].matched) {
        return m[3].matched && (m[4].matched == 0 || m[4].str() == " ");
    } else {
        return !m[3].matched && m[4].str() == m[6].str();
    }
}

vector<PersonInfo> PhoneProcess::get_data(ifstream &is) {
    string phone = R"((\()?(\d{3})(\))?([-. ]?)(\d{3})([-. ]?)(\d{4}))";
    regex r(phone);

    smatch m;
    string line, word;
    vector<PersonInfo> people;

    while (getline(is, line)) {
        PersonInfo info;
        istringstream record(line);
        record >> info.name;
        getline(record, line);
        for (sregex_iterator it(line.begin(), line.end(), r), end_it; it != end_it; ++it) {
            if (valid(*it)) {
                info.phones.push_back("V" + it->str());
            } else {
                info.phones.push_back("I" + it->str());
            }
        }
        people.push_back(info);
    }
    return people;
}

int PhoneProcess::process(ofstream &os, vector<chapter_1::PersonInfo> people) {
    for (const auto &entry : people) {
        ostringstream formatted, badNums;
        for (const auto &nums : entry.phones) {
            if (nums[0] == 'V'){
                formatted << format(nums.substr(1)) << " ";
            }else{
                badNums << nums.substr(1) << endl;
            }
        }
        if (badNums.str().empty()){
            os << entry.name << " " << formatted.str().substr(0, -1) << endl;
        }else{
            cerr << "input error: " << entry.name << " invalid number(s) " << badNums.str() << endl;
        }
    }
    return 0;
}