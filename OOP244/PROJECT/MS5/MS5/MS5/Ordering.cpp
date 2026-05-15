/* Citation and Sources...
Final Project Milestone 5:
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
#include "Ordering.h"
#include "Utils.h"
#include "Menu.h"
#include <iostream>
#include <fstream>
using namespace std;

namespace seneca {

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

    unsigned int Ordering::noOfBillItems() const {
        return m_billCounter;
    }


    Ordering::operator bool() const {
        return m_foods && m_drinks;
    }

    bool Ordering::hasUnsavedBill() const {
        return m_billCounter > 0;
    }

    ostream& Ordering::printBillTitle(ostream& os) const {
        os << "Bill # ";
        os.width(3);
        os.fill('0');
        os << m_billSerialNum;
        os.fill(' ');
        os << " =============================" << endl;
        return os;
    }

    ostream& Ordering::printTotals(double total, ostream& os) const {
        double tax = total * Tax;
        double totalTax = total + tax;

        os.setf(ios::fixed);
        os.precision(2);

        os << "                     Total:         " << total << endl;
        os << "                     Tax:           " << tax << endl;
        os << "                     Total+Tax:     " << totalTax << endl;
        os << "========================================" << endl;
        return os;
    }

    ostream& Ordering::printBill(ostream& os) const {
        printBillTitle(os);

        double total = 0;
        for (unsigned i = 0; i < m_billCounter; i++) {
            m_billItems[i]->print(os) << endl;
            total += m_billItems[i]->price();
        }
        return printTotals(total, os);
    }

    void Ordering::resetBill() {
        char name[64];
        ut.makeBillFileName(name, m_billSerialNum);

        ofstream f(name);
        if (f) printBill(f);

        cout << "Saved bill number " << m_billSerialNum << endl;
        cout << "Starting bill number " << (m_billSerialNum + 1) << endl;

        for (unsigned i = 0; i < m_billCounter; i++) {
            delete m_billItems[i];
            m_billItems[i] = nullptr;
        }

        m_billCounter = 0;
        m_billSerialNum++;
    }

    Ordering& Ordering::orderFood() {
        Menu m("Food Menu", "Back to Order", 2, 3);
        for (unsigned i = 0; i < m_foodCounter; i++)
            m << (const char*)m_foods[i];

        int sel = m.select();
        if (sel == 0) return *this;

        Food* f = new Food(m_foods[sel - 1]);
        if (f->order()) m_billItems[m_billCounter++] = f;
        else delete f;

        return *this;
    }

    Ordering& Ordering::orderDrink() {
        Menu m("Drink Menu", "Back to Order", 2, 3);
        for (unsigned i = 0; i < m_drinkCounter; i++)
            m << (const char*)m_drinks[i];

        int sel = m.select();
        if (sel == 0) return *this;

        Drink* d = new Drink(m_drinks[sel - 1]);
        if (d->order()) m_billItems[m_billCounter++] = d;
        else delete d;

        return *this;
    }

    ostream& Ordering::listFoods(ostream& os) const {
        os << "List Of Avaiable Meals\n"
           << "========================================\n";

        for (unsigned i = 0; i < m_foodCounter; i++)
            m_foods[i].print(os) << endl;

        os << "========================================\n";
        return os;
    }

    ostream& Ordering::listDrinks(ostream& os) const {
        os << "List Of Avaiable Drinks\n"
           << "========================================\n";

        for (unsigned i = 0; i < m_drinkCounter; i++)
            m_drinks[i].print(os) << endl;

        os << "========================================\n";
        return os;
    }

    Ordering::~Ordering() {
        delete[] m_foods;
        delete[] m_drinks;

        for (unsigned i = 0; i < m_billCounter; i++)
            delete m_billItems[i];
    }
}

