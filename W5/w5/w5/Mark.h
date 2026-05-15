/***********************************************************************
// OOP244 Workshop 5: Mark Module
//
// File    Mark.h
// Version 1.0
// Date    2025/06/12
// Author    partially done by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#ifndef SENECA_MARK_H
#define SENECA_MARK_H

#include <iostream>
#include <fstream>
using namespace std;

const char GPA = 'G';
const char MARK = 'M';
const char GRADE = 'R';
const char NONE = 'N';

namespace seneca {

   class Mark {
      char m_grade[3]{};
      double m_value;
      char m_type;
      bool isValid() const;

   public:

      Mark(int value = 0, char type = MARK);
      Mark(double value);
    Mark(double value, char type);

     
      Mark& operator+= (const Mark& other);
      Mark& operator-= (const Mark& other);
      Mark operator+ (const Mark& other) const;
      Mark operator- (const Mark& other) const;
      Mark& operator/= (int other);
      Mark operator/ (int other) const;

      Mark& operator= (int value);
      Mark& operator= (char type);


      double raw() const;
      operator int() const;
      operator double() const;
      operator const char* () const;
      operator bool() const;

     
      ostream& display(ostream& ostr = cout) const;

    
      friend istream& operator>>(istream& is, Mark& mark);
      friend ifstream& operator>>(ifstream& is, Mark& mark);
       
    friend Mark operator/(int lhs, const Mark& rhs);
    friend double operator/(double lhs, const Mark& rhs);
   };


   ostream& display(const Mark& mark, char type, ostream& os = cout);


   ostream& operator<<(ostream& os, const Mark& mark);
   istream& operator>>(istream& is, Mark& mark);
   ifstream& operator>>(ifstream& is, Mark& mark);

 
   double operator+(double left, const Mark& M);
   int operator+(int left, const Mark& M);
   double operator-(double left, const Mark& M);
   int operator-(int left, const Mark& M);
}

#endif // !SENECA_MARK_H

