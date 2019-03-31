//
// Created by lifeicheng on 2019/3/31.
//
#include "string_util.h"

using chapter_1::StringUtil;


string StringUtil::ltrim(string str) {
    string blank_chars = " \t\n\v\f\r";
    str.erase(0, str.find_first_not_of(blank_chars));
    return str;
}

string StringUtil::rtrim(string str) {
    string blank_chars = " \t\n\v\f\r";
    str.erase(str.find_last_not_of(blank_chars) + 1);
    return str;
}

string StringUtil::trim(string str) {
    return ltrim(std::move(rtrim(std::move(str))));
}