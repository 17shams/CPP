/* Citation and Sources...
-----------------------------------------------------------
Workshop 9
Module: Marks
Filename: Marks.h
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
No changes
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_MARKS_H
#define SENECA_MARKS_H
#include <iostream>
namespace seneca {
   class Marks;
   class Mark {
      char* m_title{};
      int m_mark{-1};
      Mark() = default;
      Mark& set(const char* title, int mark);
      Mark& operator=(const Mark& other);
      virtual ~Mark();
   public:
      const char* title()const;
      int mark()const;
      friend class Marks;
   };

   class Marks {
      Mark* m_marks{};
      size_t m_noOfMarks{};
   public:
      Marks() = default;
      Marks(const Marks& other);
      Marks& operator=(const Marks& other);
      Marks& addMark(const char* title, int mark);
      const Mark& operator[](size_t index)const;
      size_t size()const;
      virtual std::ostream& display(std::ostream& ostr = std::cout)const;
      virtual ~Marks();
   };
   std::ostream& operator<<(std::ostream& ostr, const Marks& M);

}
#endif // !SENECA_MARKS_H

