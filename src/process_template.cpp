//
// Created by Jeffrey Drake on 2015-06-05.
//

#include "process_template.h"
#include <string>
#include <istream>
#include <iterator>
#include <algorithm>
#include <tuple>
#include <fstream>
#include <codecvt>
#include <vector>
#include <regex>
#include <locale>
#include <sstream>
#include <iostream>

//namespace detail {
auto read_template(std::fstream &is) -> void {

    std::stringstream ss;
    ss << is.rdbuf();
    std::string file_content = ss.str();

    auto it = std::find(std::begin(file_content), std::end(file_content), '@');

    if (it != std::end(file_content)) {
        std::cout << "Found" << std::endl;

        auto function_begin = std::distance(std::begin(file_content), it);
        std::string copy_directly = file_content.substr(0, function_begin);

        std::cout << "File content to copy:" << std::endl;
        std::cout << copy_directly << std::endl;

        auto function_end = file_content.find("\n\n", function_begin);

        if (function_end != std::string::npos) {
            std::cout << function_begin << ", " << function_end << std::endl;
            auto function_def = file_content.substr(function_begin, function_end - function_begin);

            std::cout << "function def:" << std::endl << function_def << std::endl;

            auto rest = file_content.substr(function_end);

            std::cout << "rest of file: " << std::endl << rest << std::endl;
        }


    }

}
//}

