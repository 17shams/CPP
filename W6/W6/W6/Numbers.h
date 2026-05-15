/* Citation and Sources...
-----------------------------------------------------------
Workshop 6
Module: Numbers
Filename: numbers.h
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/11/01  Completed function declarations
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/

#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>
namespace seneca {
   class Numbers {
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
       
       int numberCount() const;
       bool loadCount();
       void saveCount();
       
   public:
      Numbers();
      Numbers(const char* filename);
       ~Numbers();

       Numbers(const Numbers& other);
       Numbers& operator=(const Numbers& other);

       double average() const;
       double max() const;
       double min() const;

       Numbers& operator+=(double value);
       std::ostream& display(std::ostream& ostr = std::cout) const;
   };

   std::ostream& operator<<(std::ostream& os, const Numbers& N);
   std::istream& operator>>(std::istream& is, Numbers& N);

}
#endif // !SENECA_NUMBERS_H_

