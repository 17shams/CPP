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

#ifndef SENECA_LABELEDSHAPE_H
#define SENECA_LABELEDSHAPE_H
#include <iostream>
#include "Shape.h"

namespace seneca {
 
   class LblShape : public Shape      {
      // Dynamically allocated label for the shape
      char* m_label;
   protected:
      // Returns the label string for derived classes to access
    const char* label() const;
   public:
      // Default constructor
     LblShape();
 
      // Constructor with label initialization
      LblShape(const char* label);
 
      // Copy constructor and assignment operator are deleted to prevent copying
      LblShape(const LblShape&) = delete;
      LblShape& operator=(const LblShape&) = delete;
 
      // Reads label specifications from input stream
      void getSpecs(std::istream&);
 
      // Destructor to release dynamically allocated memory
     virtual ~LblShape();
   };
}

#endif // !SENECA_LABELEDSHAPE_H
