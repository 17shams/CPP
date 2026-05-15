/* Citation and Sources...
-----------------------------------------------------------
Workshop 7
Module: Employee
Filename: Employee.h
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/11/09  No changes
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_EMPLOYEE_H
#define SENECA_EMPLOYEE_H
#include <iostream>
namespace seneca{
   class Employee {
      char *m_name{};
      size_t m_employeeNo{};
      double m_salary{};
   protected:
      double salary()const;
   public:
      Employee() = default;
      Employee(const char* name, size_t employeeNo, double salary);
      Employee(const Employee&) = delete;
      Employee& operator=(const Employee&) = delete;
      ~Employee();

      std::istream& read(std::istream& istr = std::cin);
      std::ostream& write(std::ostream& ostr = std::cout)const;
      std::ostream& title(std::ostream& ostr = std::cout)const;
   };

   std::ostream& operator<<( std::ostream& ostr, const Employee& E );
   std::istream& operator>>( std::istream& istr, Employee& E );
}
#endif // !SENECA_EMPLOYEE_H
