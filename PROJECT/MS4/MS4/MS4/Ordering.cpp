/* Citation and Sources...
Final Project Milestone 4:
Module: [Ordering]
Filename: Ordering.cpp
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/21  Completed .cpp implementation
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include "Ordering.h"
#include "constants.h"

using namespace std;

namespace seneca {

    size_t Ordering::countRecords(const char* file) const {
        size_t count = 0;
        std::ifstream fin(file);
        std::string line;

        while (std::getline(fin, line)) {
            if (!line.empty())
                count++;
        }

        return count;
    }


    Ordering::Ordering(const char* drinkFile, const char* foodFile) {

        size_t foodTotal = countRecords(foodFile);
        size_t drinkTotal = countRecords(drinkFile);

        std::ifstream fin(foodFile);
        std::ifstream din(drinkFile);

        size_t foodsRead = 0;
        size_t drinksRead = 0;

        m_foods = nullptr;
        m_drinks = nullptr;
        m_foodCounter = 0;
        m_drinkCounter = 0;

        if (fin && din) {

            m_foods = new Food[foodTotal];
            m_drinks = new Drink[drinkTotal];

            for (size_t i = 0; i < foodTotal; i++) {
                if (m_foods[i].read(fin)) {
                    foodsRead++;
                } else {
                    break;
                }
            }

            for (size_t i = 0; i < drinkTotal; i++) {
                if (m_drinks[i].read(din)) {
                    drinksRead++;
                } else {
                    break;
                }
            }

            if (drinksRead != drinkTotal || foodsRead != foodTotal) {

                delete[] m_drinks;
                delete[] m_foods;

                m_drinks = nullptr;
                m_foods = nullptr;

                m_drinkCounter = 0;
                m_foodCounter = 0;
            }
            else {
                m_drinkCounter = drinksRead;
                m_foodCounter = foodsRead;
            }
        }
    }

      


std::ostream& Ordering::printBillTitle(std::ostream& ostr) const{
    ostr << "Bill # ";
    ostr.width(3);
    ostr.fill('0');
    ostr << m_billSerialNum;
    ostr.fill(' ');
    ostr << " =============================" << std::endl;
    return ostr;
}


    std::ostream& Ordering::printTotals(double total, std::ostream& ostr) const{
        double tax = total * Tax;
        double totalTax = total + tax;
        
        ostr.setf(std::ios::fixed);
        ostr.precision(2);

        ostr << "                     Total:        " << total << std::endl;
        ostr << "                     Tax:           " << tax << std::endl;
        ostr << "                     Total+Tax:    " << totalTax << std::endl;
        ostr << "========================================" << std::endl;

        return ostr;

    }

    Ordering::~Ordering(){
        delete [] m_foods;
        delete [] m_drinks;
        m_foods = nullptr;
        m_drinks = nullptr;
        
        for (unsigned int i = 0; i < m_billCounter; i++){
            delete m_billItems[i];
            m_billItems[i] = nullptr;
        }
    }

    Ordering::operator bool() const {
        return (m_foods != nullptr && m_drinks != nullptr);
    }



    bool Ordering::hasUnsavedBill() const{
        if (noOfBillItems() > 0) {
            return true;
        } else {
            return false;
        }
    }

    void Ordering::resetBill(){
        char filename[50];
        ut.makeBillFileName(filename, m_billSerialNum);
       
        std::ofstream fout(filename);
        if (fout.is_open()){
            printBill(fout);
        }
       
        cout << "Saved bill number " << m_billSerialNum << std::endl;
        cout << "Starting bill number " << (m_billSerialNum + 1) << std::endl;

       
        for (unsigned int i = 0; i < m_billCounter; i++) {
            delete m_billItems[i];
            m_billItems[i] = nullptr;
        }
        m_billSerialNum++;
        m_billCounter = 0;
    }

    Ordering& Ordering::orderDrink() {
        Menu drinkMenu("Drink Menu", "Back to Order", 3, 2);
     
            for (unsigned int i = 0; i < m_drinkCounter; i++) {
                drinkMenu << (const char*)m_drinks[i];
            }
            int selection = drinkMenu.select();
           
            if (selection == 0) {
                return *this;
            }
     
            unsigned index = selection - 1;
            Billable* temp = new Drink(m_drinks[index]);
     
            m_billItems[m_billCounter] = temp;
     
            if (m_billItems[m_billCounter]->order()) {
                m_billCounter++;
            } else {
                delete m_billItems[m_billCounter];
                m_billItems[m_billCounter] = nullptr;
            }
            return *this;
        }
     
    Ordering& Ordering::orderFood() {
        Menu foodMenu("Food Menu", "Back to Order", 3, 2);
       
        for (unsigned i = 0; i < m_foodCounter; i++) {
            foodMenu << (const char*)m_foods[i];
        }
        int selection = foodMenu.select();
       
        if (selection == 0) {
            return *this;
        }
        unsigned index = selection - 1;
        Billable* temp = new Food(m_foods[index]);
       
        m_billItems[m_billCounter] = temp;
       
        if (m_billItems[m_billCounter]->order()) {
            m_billCounter++;
        } else {
            delete m_billItems[m_billCounter];
            m_billItems[m_billCounter] = nullptr;
        }
        return *this;
    }

    unsigned int Ordering::noOfBillItems() const{
        return m_billCounter;
    }

    std::ostream& Ordering::listDrinks(std::ostream& ostr) const{
        ostr << "List Of Avaiable Drinks" << endl;
        ostr << "========================================" << endl;
        
        for (unsigned int i = 0; i < m_drinkCounter ; i++) {
            m_drinks[i].print(ostr);
            ostr << endl;
        }
        
        ostr << "========================================" << endl;
        return ostr;
    }

    std::ostream& Ordering::listFoods(std::ostream& ostr) const{
        
        ostr << "List Of Avaiable Meals" << endl;
        ostr << "========================================" << endl;
        
        for (unsigned int i = 0; i < m_foodCounter ; i++) {
            m_foods[i].print(ostr);
            ostr << endl;
        }
        
        ostr << "========================================" << endl;
        return ostr;
    }

    std::ostream& Ordering::printBill(std::ostream& ostr) const{
        double totalPrice{};
        printBillTitle(ostr);
        for (unsigned int i = 0; i < m_billCounter; i++){
            m_billItems[i]->print(ostr);
            ostr << endl;
            totalPrice += m_billItems[i]->price();
        }
        printTotals(totalPrice, ostr);
        
        return ostr;
    }
}
