/* Citation and Sources...
Final Project Milestone 4:
Module: [Ordering]
Filename: Ordering.h
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/21  Completed .h implementation
-----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my work for function whatever.
-----------------------------------------------------------*/
#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H
#include <iostream>
#include "constants.h"
#include "Menu.h"
#include "Utils.h"
#include "Food.h"
#include "Billable.h"
#include "Drink.h"
 
namespace seneca {
   
    class Ordering {
        unsigned int m_foodCounter{};
        unsigned int m_drinkCounter{};
        unsigned int m_billCounter{};
        unsigned int m_billSerialNum{1};
        Food* m_foods;
        Drink* m_drinks;
        Billable* m_billItems[MaximumNumberOfBillItems];
       
        size_t countRecords(const char* file) const;
        std::ostream& printTotals(double total, std::ostream& ostr = std::cout) const;
        std::ostream& printBillTitle(std::ostream& ostr = std::cout) const;
       
        public:
        Ordering(const char* drinkFile, const char* foodFile);
        ~Ordering();
        operator bool() const;
        bool hasUnsavedBill() const;
        void resetBill();
        unsigned int noOfBillItems() const;
        Ordering& orderFood();
        Ordering& orderDrink();
        std::ostream& listDrinks(std::ostream& ostr = std::cout) const;
        std::ostream& listFoods(std::ostream& ostr = std::cout) const;
        std::ostream& printBill(std::ostream& ostr = std::cout) const;
    };
}

#endif // !SENECA_ORDERING_H
