/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Line
Filename: Line.cpp
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
#include <cstring>
#include "Line.h"
#include "LblShape.h"
#include "Utils.h"
 
namespace seneca {
   
    Line::Line() : LblShape(){
        m_length = 0;
    }
   
    Line::Line(const char* label, int length) : LblShape(label){
        int labelLength = strlen(label);
       
        if (length < labelLength) {
            m_length = labelLength;
        } else {
            m_length = length;
        }
    }
   
    void Line::getSpecs(std::istream& is) {
        LblShape::getSpecs(is);
        is >> m_length;       
        is.ignore(1000, '\n');

        if (m_length < (int)strlen(label())) {
            m_length = strlen(label());
        }
    }

   
void Line::draw(std::ostream& os) const{
    if (m_length > 0 && label() != nullptr){
        os << label() << std::endl;
        for (int i = 0; i < m_length; i++) {
            os << "=";
        }
    }
}
}
