/*
 * Copyright (c) xall 2024
 * Written by ghgltggamer
 * Check the LICENSE file for Licensing info
 * Check out the README.md file for more information
 */
// Source starts from here
#include <cstddef>
#include <cstdlib>
#ifndef XALL_MAIN_HEADER
#define XALL_MAIN_HEADER 11110101
#define N "\n"
#include <iostream>
#include   <string>
#include  <fstream>
#include   <vector>
#include    <cmath>

// XALL String Lib
namespace XALL_NM {
    class XString{
        public:
        int is_string(std::string line, std::string char_){
            int result = 0;
            size_t is_before_line_found = line.find(char_, 0);
            if (is_before_line_found != std::string::npos){
                size_t str_coat_1 = line.find("\"");
                if (is_before_line_found != std::string::npos){
                    if (is_before_line_found > str_coat_1){
                        size_t string_coat_2 = line.find("\"", str_coat_1+1);
                        if (string_coat_2 != std::string::npos){
                            if (string_coat_2 > is_before_line_found){
                                // Yes it was in string
                                result = 1;
                            }
                        }
                        else {
                            std::cout<<"Error , Xall Program was invalid. An Invalid String Found, The String coates must be closed once oppened.\n";
                            exit(3 );
                        }
                    }
                }
            }
            else return (2);
            return result;
        }


        int is_istring(std::string line, size_t pos){
            int result = 0;
            size_t is_before_line_found = pos;
            // if (is_before_line_found != std::string::npos){
                size_t str_coat_1 = line.find("\"");
                if (is_before_line_found != std::string::npos){
                    if (is_before_line_found > str_coat_1){
                        size_t string_coat_2 = line.find("\"", str_coat_1+1);
                        if (string_coat_2 != std::string::npos){
                            if (string_coat_2 > is_before_line_found){
                                // Yes it was in string
                                result = 1;
                            }
                        }
                        else {
                            std::cout<<"Error , Xall Program was invalid. An Invalid String Found, The String coates must be closed once oppened.\n";
                            exit(3 );
                        }
                    }
                }
            // }
            // else return (2);
            return result;
        }
    };
}

namespace XALL_CONFIG {
    std::string XVersion_String = "XALL Version 0.1";
    double XVersion_Double = 0.1;
    int XVersion_Int = 0;
    float XVersion_Float = 0.1f;
}

class XALL {
    public:
        std::string line_p = "";
        XALL(std::string code) : line_p(code) {}
        std::string to_HTML(){
            std::string program_html = ""; // This is the variable where our HTML Is going to be stored
            // for (size_t)
            std::string config_tag_name, config_tag_content; // config for the tag
            XALL_NM::XString init_xstring;
            bool is_function_loaded = false, is_string_started = false;
            for (size_t i = 0;i < line_p.length();i++){
                // size_t sem_pos = line_p.find(";", 0);
                // std::cout<<line_p[i]<<N;


                // if (line_p[i] == ')' && is_function_loaded == true){
                //     if (init_xstring.is_istring(line_p, i) == 0){
                //         // is_function_loaded = false;
                //     }
                //     // std::cout<<"I is ) right now\n";1
                // }
                if (is_function_loaded == true && line_p[i] == ')' && is_string_started == false){
                    is_function_loaded = false;
                }

                else if (is_function_loaded && line_p[i] == '"' && is_string_started == true){
                    is_string_started = false;
                }
                else if (is_function_loaded && is_string_started) config_tag_content += line_p[i];
                else if (is_function_loaded && line_p[i] == '"' && is_string_started == false){
                    is_string_started = true;
                }
                // else if (is_function_loaded){
                //     if (line_p[i] == '"' && is_string_started == false){ 
                //         is_string_started = true;std::cout<<"The string coat 1 found at: "<<i<<N;
                //     }
                //     else if (line_p[i] == '"' && is_string_started) {
                //         is_string_started = false;std::cout<<"The string coat 2 founds at: "<<i<<N;
                //     }
                // }
                else if (line_p[i] == ';'){
                    if (init_xstring.is_istring(line_p, i) == 0){
                        break;
                    }
                }
                else if (line_p[i] == '(' && is_function_loaded == false){
                    if (init_xstring.is_istring(line_p, i) == 0){
                        std::string tag_name = "";
                        for (int x = i-1;true;x--){
                            if (x == 0) {
                                tag_name += line_p[x];
                                // std::cout<<"Index : "<<x<<" value: "<<N;
                                break;
                            }
                            else if (line_p[x] == ' '){
                                continue;
                            }
                            else {
                                tag_name += line_p[x];
                            }
                            // std::cout<<"Index : "<<x<<N;
                            if (line_p[x] == ' ') break;
                        }
                        std::string tag_name_main = "";
                        for (int y = (tag_name.length()-1);y != -1;y--){
                            tag_name_main += tag_name[y];
                        }
                        // std::cout<<"Tag name is : "<<tag_name_main<<N;
                        config_tag_name = tag_name_main;
                        is_function_loaded = true;            
                    }
                }


            }
            // Clear spaces from the tag name
            std::string final_config_tag_name;
            for (size_t i = 0;i < config_tag_name.length();i++){
                if (config_tag_name[i] == ' ') continue;
                else final_config_tag_name += config_tag_name[i];
            }
            // std::cout<<"Tag name: "<<config_tag_name<<" and tag content is : "<<config_tag_content<<N;
            program_html = "<" + final_config_tag_name + ">" + config_tag_content + "</" + final_config_tag_name + ">";
            return program_html;
        }
};
#endif
