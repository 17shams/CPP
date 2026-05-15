/* Citation and Sources...
-----------------------------------------------------------
Workshop 8
Module: LblShape
Filename: LblShape.cpp
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
#include "LblShape.h"
#include "Utils.h"

namespace seneca {
   
    const char* LblShape::label() const{
        return m_label;
    }
   
   LblShape::LblShape(){
       m_label = nullptr;
   }
  
   LblShape::LblShape(const char* label){
       m_label = nullptr;
       ut.alocpy(m_label, label);
   }
      
    void LblShape::getSpecs(std::istream& is) {
        char temp[81]{};

        delete[] m_label;
        m_label = nullptr;
        is.getline(temp, 81, ',');
        ut.alocpy(m_label, temp);
    }

   LblShape::~LblShape(){
       delete [] m_label;
       m_label = nullptr;
   }
}
