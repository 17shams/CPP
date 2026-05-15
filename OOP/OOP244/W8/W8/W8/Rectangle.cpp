/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: Rectangle
Filename: Rectangle.cpp
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
#include "Rectangle.h"
#include "LblShape.h"
#include "Utils.h"
 
namespace seneca {
    Rectangle::Rectangle() : LblShape() {
        m_width = 0;
        m_height = 0;
    }
   
Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label) {
    m_height = (height < 3) ? 3 : height;

    int minWidth = strlen(this->label()) + 2;

    m_width = (width < minWidth) ? minWidth : width;
}
   
void Rectangle::getSpecs(std::istream& is) {
    LblShape::getSpecs(is);

    is >> m_width;
    is.ignore();

    is >> m_height;
    is.ignore(1000, '\n');

    if (m_height < 3) m_height = 3;

    int minWidth = strlen(label()) + 2;
    if (m_width < minWidth) m_width = minWidth;
}




    
    void Rectangle::draw(std::ostream& os) const {
            if (m_width > 0 && m_height > 0 && label() != nullptr) {
                // First Line
                os << "+";
                for (int i = 0; i < m_width - 2; i++) {
                    os << "-";
                }
                os << "+" << std::endl;
                // Second Line
                os << "|";
                os << label();
                int spaces = m_width - 2 - strlen(label());
                for (int i = 0; i < spaces; i++) {
                    os << " ";
                }
                os << "|" << std::endl;

                // Middle lines
                for (int i = 0; i < m_height - 3; i++) {
                    os << "|";
                    for (int j = 0; j < m_width - 2; j++) {
                        os << " ";
                    }
                    os << "|" << std::endl;
                }

                // Bottom Line
                if (m_height > 1) {
                    os << "+";
                    for (int i = 0; i < m_width - 2; i++) {
                        os << "-";
                    }
                    os << "+";
                }
            }
        }
}
