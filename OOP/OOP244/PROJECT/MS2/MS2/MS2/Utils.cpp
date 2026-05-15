/* Citation and Sources...
Final Project Milestone 2:
Module: [Utils]
Filename: [Utils].cpp
Version #.1#
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2025/11/05  No Changes
-----------------------------------------------------------
 All work done by myself
-----------------------------------------------------------*/
#include <iostream>
#include <sstream>
#include "Utils.h"

using namespace std;
namespace seneca {
   Utils ut;

   char* Utils::alocpy(const char* src) const{
      char* des{};
      return alocpy(des, src);
   }

   char* Utils::alocpy(char*& des, const char* src)const {
      delete[] des;
      des = nullptr;
      if (src) {
         des = new char[strlen(src) + 1];
         strcpy(des, src);
      }
      return des;
   }
   char* Utils::strcpy(char* des, const char* src)const {
      int i;
      for (i = 0; src[i]; i++) des[i] = src[i];
      des[i] = char(0);
      return des;
   }
   int Utils::strlen(const char* str)const {
      int len;
      for (len = 0; str[len]; len++);
      return len;
   }

   bool Utils::isspace(char ch)const {
      return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r';
   }

   bool Utils::isspace(const char* cstring) const{
      while (cstring && isspace(*cstring)) {
         cstring++;
      }
      return cstring && *cstring == 0;
   }

    int Utils::getInt(){
        
        int value{};
        bool done = false;
        
        while(!done){
            std::string input;
            std::getline(cin,input);
            
            if (input.empty()) {
                std::cout << "You must enter a value: ";
                continue;
            }
            std::stringstream ss(input);
            ss >> value;
            
            if (ss.fail()){
                std::cout << "Invalid integer: ";
                continue;
            }
            
            char leftover;
            if (ss >> leftover) {
                std::cout << "Only an integer please: ";
                continue;
            }
            done = true;
        }
        return value;
    }

    int Utils::getInt(int min, int max){
        int value{};
        bool done = false;
        
        while (!done){
            value = getInt();
            if (value < min || value > max){
                        std::cout << "Invalid value: ["
                                  << min << " <= " << value << " <= " << max
                                  << "], try again: ";
                    } else {
                done = true;
            }
        }
        return value;
    }

}
