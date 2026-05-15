/* Citation and Sources...
-----------------------------------------------------------
Workshop 10
Module: Name
Filename: Name.h
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_NAME_H
#define SENECA_NAME_H
#include <iostream>
namespace seneca {

   class Name {
      char* m_name{};
   public:
      Name( ) = default;
      Name( const char* name );
      Name( const Name& other );
      Name& operator=( const Name& other );
      virtual ~Name( );
      virtual std::ostream& display( std::ostream& ostr )const;
      virtual std::istream& read( std::istream& istr );
      virtual operator bool( ) const;
   };
   std::ostream& operator<<( std::ostream& ostr, const Name& N );
   std::istream& operator>>( std::istream& istr, Name& N );
}

#endif // !SENECA_NAME_H


