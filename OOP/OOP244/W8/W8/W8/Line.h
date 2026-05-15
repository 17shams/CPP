/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Line
Filename: Line.h
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/11/15  Completing .h file
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_LINE_H
#define SENECA_LINE_H
#include <iostream>
#include "LblShape.h"

namespace seneca {
 
   class Line : public LblShape {
       // Length of the line
       int m_length;
 
   public:
      // Default constructor
      Line();
 
      // Constructor that initializes label and length
     Line(const char* label, int length);
 
      // Draws the line, using the label and length
      void draw(std::ostream& os) const;
 
      // Gets specifications of the line (label and length) from input
     void getSpecs(std::istream&);
   };
 
}

#endif // !SENECA_LINE_H
