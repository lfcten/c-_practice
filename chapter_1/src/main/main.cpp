#include <fstream>
#include "common.h"
//#include "string_util.h"
#include "index.h"

//using chapter_1::StringUtil;
using std::ifstream;
using std::ofstream;
using chapter_1::PhoneProcess;
int main(int argc, char **argv) {
//    string src = "  This is a test!  ";
//    cout << StringUtil::ltrim(src) << "." << endl;
//    cout << StringUtil::rtrim(src) << "." << endl;
//    cout << StringUtil::trim(src) << "." << endl;
    if (argc != 2){
        cerr << "请给出文件名" << endl;
        return  -1;
    }
    ifstream in(argv[1]);
    if (!in){
        cerr << "无法打开输入文件" << endl;
        return -1;
    }
    ofstream os("out.txt");
    PhoneProcess phoneProcess;
    phoneProcess.process(os, phoneProcess.get_data(in));
    return 0;
}