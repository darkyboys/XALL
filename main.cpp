/*
 * Copyright (c) xall 2024
 * Written by ghgltggamer
 * Check the LICENSE file for Licensing info
 * Check out the README.md file for more information
 */
// Source
#include <cstddef>
#include <fstream>
#include <string>
#ifndef MAIN
#define MAIN 101010111
#include "xall.h"
#include "xtrans/xtrans.hpp"


int main(int argc, char* argv[]){
   if (argc == 1){
      std::cout<<"XTrans needs a single argument at the least!\nPlease use '--help' for more information.\n";
      exit ( 3 );
   }
   std::string output_file = "a.html";
   std::vector <std::string> CLI_Arguments = {};// CLI Argument List
   for (size_t i = 0;i < argc;i++) CLI_Arguments.push_back(argv[i]);
   if (CLI_Arguments[CLI_Arguments.size()-2] == "-o"){
      output_file = CLI_Arguments[CLI_Arguments.size()-1];
      // std::cout<<output_file<<N;
      CLI_Arguments.pop_back();
      CLI_Arguments.pop_back();
   }
   if (CLI_Arguments[1] == "-v" or CLI_Arguments[1] == "--version"){
      std::cout<<"XTrans 0.1 (c) ghgltggamer\n"
               <<XALL_CONFIG::XVersion_String<<N;
   }
   else if (CLI_Arguments[1] == "-c" or CLI_Arguments[1] == "combine"){
      std::string html = "";
      for (size_t x = 2;x < CLI_Arguments.size();x++){
         // std::cout<<"Compiling "<<CLI_Arguments[x]<<N;
         html += XTrans_Make_Html(CLI_Arguments[x]);
      }
      std::ofstream ofile(output_file);
      ofile<<html;
   }
   else {
      // std::cout<<"The file was compiled as "<<output_file<<N;
      std::string html = XTrans_Make_Html(CLI_Arguments[1]);
      std::ofstream ofile(output_file);
      ofile<<html;
   }
   return 0;
}
#endif