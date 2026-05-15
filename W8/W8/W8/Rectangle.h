/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Rectangle
Filename: Rectangle.h
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
#ifndef SENECA_RECTANGLE_H
#define SENECA_RECTANGLE_H
#include <iostream>
#include "LblShape.h"

namespace seneca {
 
   class Rectangle : public LblShape {
      // Width of the rectangle
      int m_width{};
      // Height of the rectangle
        int m_height{};
   public:
      // Default constructor
      Rectangle();
 
      // Constructor that initializes label, width, and height
      Rectangle(const char* label, int width, int height);
 
      // Draws the rectangle using the label, width, and height
      void draw(std::ostream&) const;
 
      // Gets specifications of the rectangle (label, width, height) from input
      void getSpecs(std::istream&);
   };
 
}

#endif // !SENECA_RECTANGLE_H
