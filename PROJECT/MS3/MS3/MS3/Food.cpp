/* Citation and Sources...
Final Project Milestone 3:
Module: [Food]
Filename: Food.h
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/18  Completed .h file
-----------------------------------------------------------
 All work done by myself
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "Food.h"
#include "Billable.h"

using namespace std;

namespace seneca {
    
    Food::Food(){
        m_child = false;
        m_ordered = false;
        m_customize = nullptr;
        }
    
    void Food::init(const Food& F){
        m_child = F.m_child;
        m_ordered = F.m_ordered;
            if (F.m_customize != nullptr){
                m_customize = new char[strlen(F.m_customize) + 1];
                strcpy(m_customize, F.m_customize);
            } else {
                m_customize = nullptr;
            }
        }
    
    Food::Food(const Food& F) : Billable(F) {
        init(F);
    }

    Food& Food::operator=(const Food& F){
        if (this != &F) {
            Billable::operator=(F);
            delete[] m_customize;
            init(F);
        }
        return *this;
    }

    Food::~Food(){
        delete[] m_customize;
        m_customize = nullptr;
    }

    std::ostream& Food::print(std::ostream& ostr)const{
    //Name
        ostr.width(28);
        ostr.fill('.');
        ostr.setf(ios::left, ios::adjustfield);
        ostr << (const char*)*this;
        ostr.unsetf(ios::adjustfield);
        
    //Portion Type
        if (ordered() && m_child == true){
            ostr << "Child";
        } else if (ordered() && m_child == false) {
            ostr << "Adult";
        } else {
            ostr << ".....";
        }
            
    //Price
        ostr.width(7);
        ostr.fill(' ');
        ostr.setf(ios::right, ios::adjustfield);
        ostr.setf(ios::fixed, ios::floatfield);
        ostr.precision(2);
        ostr << price();
        ostr.unsetf(ios::adjustfield);
        
    //Customization
        if(m_customize != nullptr && &ostr == &cout){
            ostr << " >> ";
            for (int i = 0; m_customize[i] != '\0' && i < 30; i++) {
                ostr << m_customize[i];
            }
        }
        return ostr;
    }
    
    std::ifstream& Food::read(std::ifstream& file) {
        char tempName[26]{};
        double tempPrice{};

        file.getline(tempName, 25, ',');
        if (!file) {
            file.setstate(std::ios::failbit);
            return file;
        }

        file >> tempPrice;
        if (!file) {
            file.setstate(std::ios::failbit);
            return file;
        }

        file.ignore(1000, '\n');

        if (tempName[0] == '\0' || tempName[0] == ' ') {
            file.setstate(std::ios::failbit);
            return file;
        }

        Billable::name(tempName);
        Billable::price(tempPrice);

        m_child = false;
        m_ordered = false;

        delete[] m_customize;
        m_customize = nullptr;

        return file;
    }

    bool Food::ordered()const{
        return m_ordered;
    }

    bool Food::order(){
        
        int choice;
        cout << "         Food Size Selection\n";
        cout << "          1- Adult\n";
        cout << "          2- Child\n";
        cout << "          0- Back\n";        
        cout << "         > ";

        
        cin >> choice;
        switch (choice) {
            case 1 :
                m_child = false;
                m_ordered = true;
                break;
            case 2:
                m_child = true;
                m_ordered = true;
                break;
            case 0:
                m_ordered = false;
                delete[] m_customize;
                m_customize = nullptr;
                return false;
        }
        
        if(m_ordered){
            cout << "Special instructions" << endl;
            cout << "> ";
            
            char buffer[256];
            cin.ignore(1000, '\n');
            cin.getline(buffer, 256);

            if(buffer[0] == '\0'){
                delete[] m_customize;
                m_customize = nullptr;
            } else {
                m_customize = new char[strlen(buffer) + 1];
                strcpy(m_customize, buffer);
            }
        }
        return true;
    }


    double Food::price() const{
        if (ordered() && m_child){
            return Billable::price() * 0.5;
        } else {
            return Billable::price();
        }
    }
}

