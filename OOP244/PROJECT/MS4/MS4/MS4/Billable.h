/* Citation and Sources...
Final Project Milestone 4:
Module: [Billable]
Filename: Billable.h
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/18  Completed .h implementation
-----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my work for function whatever.
-----------------------------------------------------------*/
#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H
#include <iostream>
#include <fstream>
 
namespace seneca {
   
    class Billable {
        char* m_name{};
        double m_price{};
    protected:
        void price(double value);
        void name(const char* name);
    public:
        Billable();
        Billable(const Billable&);
        Billable& operator=(const Billable&);
        void init(const Billable&);
        virtual ~Billable();
       
        virtual double price() const;
        virtual std::ostream& print(std::ostream& ostr = std::cout) const = 0;
        virtual bool order() = 0;
        virtual bool ordered() const = 0;
        virtual std::ifstream& read(std::ifstream& file) = 0;
        operator const char*()const;
    };
   
    double operator+(double money, const Billable& B);
    double& operator+=(double& money, const Billable& B);
}
 
#endif // !SENECA_BILLABLE_H
