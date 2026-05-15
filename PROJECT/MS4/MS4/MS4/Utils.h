/* Citation and Sources...
Final Project Milestone 4:
Module: [Utils]
Filename: [Utils].h
Version #.1#
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2025/11/05  No Changes
-----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my work for function whatever.
-----------------------------------------------------------*/
#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H
namespace seneca {
   class Utils {
   public:
      char* alocpy(const char* src)const;
      char* alocpy(char*& des, const char* src)const;
      char* strcpy(char* des, const char* src)const;
      int strlen(const char* str)const;
      bool isspace(char ch)const;
      bool isspace(const char* cstring)const;
       int getInt();
       int getInt(int min, int max);
       char* makeBillFileName(char*, size_t)const;
   };
   extern Utils ut;   // makes the ut object available where Utils.h is included
                     // to call a Utils function call it as follows
                     // ut.strcpy(des, src);
}

#endif // !SENECA_UTILS_H
