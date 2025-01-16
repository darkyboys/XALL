/*
 * Copyright (c) xall 2024
 * Written by ghgltggamer
 * Check the LICENSE file for Licensing info
 * Check out the README.md file for more information
 */
// Source
// Xtrans - Library for providing xtrans utilities

#include <fstream>
#include <string>

int XTrans_Line_End(std::string line){
    size_t end_block = line.find(";");
    int rval = 0;
    XALL_NM::XString xinit_xstring;
    if (end_block != std::string::npos){
        if (xinit_xstring.is_istring(line, ';') == 0){
            rval = 1;
        }
    }
    return rval;
}

std::string XTrans_Make_Html(std::string ifile_name){
    std::string rval;
    std::ifstream ifile(ifile_name);
    if (!ifile.is_open()){
        std::cout<<"The Input File (ifile)[" + ifile_name + "] was not found. Please ensure that the file path was correct or the file exists.\n";
    }
    std::string temp, file_code;
    while (std::getline(ifile, temp)){
        if (XTrans_Line_End(temp)){
            file_code += temp;
            XALL xtrans(file_code);
            rval += xtrans.to_HTML();
            file_code = "";
        }
        else {
            file_code += temp;
            continue;
        }
    }
    return rval;
}