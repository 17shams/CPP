/* Citation and Sources...
Final Project Milestone 5:
Module: [Food]
Filename: Food.h
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/18  Completed .h file
-----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my work for function whatever.
-----------------------------------------------------------*/
#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H
#include <iostream>
#include <fstream>
#include "Billable.h"


namespace seneca {
    class Food : public Billable {
        bool m_ordered;
        bool m_child;
        char* m_customize;
    public:
        Food();
        Food(const Food&);
        Food& operator=(const Food&);
        void init(const Food&);
        ~Food();
        
        std::ostream& print(std::ostream& ostr=std::cout)const;
        bool order();
        bool ordered()const;
        std::ifstream& read(std::ifstream& file);
        double price() const;
        
        
    };
}
#endif // !SENECA_FOOD_H
