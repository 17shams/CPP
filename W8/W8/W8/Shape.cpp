/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Shape
Filename: Shape.cpp
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/11/15  Completing .cpp file
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/

#include <iostream>
#include "Shape.h"
 
namespace seneca {
    Shape::~Shape(){
    };
   
    std::istream& operator>>(std::istream& is, Shape& s){
        s.getSpecs(is);
        return is;
    }
    std::ostream& operator<<(std::ostream& os, const Shape& s){
        s.draw(os);
        return os;
    }
}
