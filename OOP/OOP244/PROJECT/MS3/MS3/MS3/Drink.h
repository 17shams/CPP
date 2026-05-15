/* Citation and Sources...
Final Project Milestone 3:
Module: [Drink]
Filename: Drink.h
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/18  Completed .h file
-----------------------------------------------------------
 All work done by myself
-----------------------------------------------------------*/
#ifndef SENECA_DRINK_H
#define SENECA_DRINK_H
#include <iostream>
#include <fstream>
#include "Billable.h"
 
namespace seneca {
    class Drink : public Billable {
        char m_size{};
    public:
        std::ostream& print(std::ostream& ostr=std::cout)const;
        bool order();
        bool ordered()const;
        std::ifstream& read(std::ifstream& file);
        double price() const;
    };
 
}
 
#endif // !SENECA_DRINK_H
