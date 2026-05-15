/* Citation and Sources...
Final Project Milestone 4:
Module: [Billable]
Filename: Billable.cpp
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/18  Completed .cpp implementation
-----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my work for function whatever.
-----------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "Billable.h"
#include "Utils.h"
 
namespace seneca {
   
    void Billable::price(double value){
        m_price = value;
    }
   
    void Billable::name(const char* name){
        ut.alocpy(m_name, name);
    }
   
    Billable::Billable(){
       m_name = nullptr;
       m_price = 0;
    }
   
    void Billable::init(const Billable& B){
        m_price = B.m_price;
       
        if (B.m_name != nullptr){
            m_name = new char[strlen(B.m_name) + 1];
            strcpy(m_name, B.m_name);
 
        } else {
            m_name = nullptr;
        }
    }
   
    Billable::Billable(const Billable& B){
       init(B);
    }
   
    Billable& Billable::operator=(const Billable& B){
        if (this != &B){
            delete[] m_name;
            init(B);
        }
        return *this;
    }
   
    Billable::~Billable(){
        delete[] m_name;
        m_name = nullptr;
    }
   
    double Billable::price() const{
        return m_price;
    }
   
    Billable::operator const char*()const{
        if (m_name != nullptr){
            return m_name;
        } else {
            return "";
        }
    }
   
    double operator+(double money, const Billable& B){
        return money + B.price();
    }
    double& operator+=(double& money, const Billable& B){
        return money += B.price();
    }
}

