/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Shape
Filename: Shape.h
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

#ifndef SENECA_SHAPE_H
#define SENECA_SHAPE_H
#include <iostream>

namespace seneca {
 
   class Shape {
   public:
      // Pure virtual function to draw the shape, implemented in derived classes
      virtual void draw(std::ostream&) const = 0;
 
      // Pure virtual function to get specifications of the shape, implemented in derived classes
      virtual void getSpecs(std::istream&) = 0;
 
      // Virtual destructor to ensure proper cleanup of derived class objects
      virtual ~Shape();
   };
 
   // Operator overload to handle output stream, relies on draw function
   std::ostream& operator<<(std::ostream& os, const Shape& s);
 
   // Operator overload to handle input stream, relies on getSpecs function
  std::istream& operator>>(std::istream& is, Shape& s);
 
}

#endif // !SENECA_SHAPE_H
