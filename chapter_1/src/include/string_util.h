//
// Created by lifeicheng on 2019/3/31.
//

#ifndef CHAPTER_1_STRING_UTIL_H
#define CHAPTER_1_STRING_UTIL_H

#include "common.h"

namespace chapter_1 {
    class StringUtil {
    public:
        // left去空格
        static string ltrim(string str);

        // right去空格
        static string rtrim(string str);

        // 两侧去空格
        static string trim(string str);
    };
}
#endif //CHAPTER_1_STRING_UTIL_H
