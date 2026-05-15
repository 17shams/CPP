/* Citation and Sources...
-----------------------------------------------------------
Workshop 9
Module: Transcript
Filename: Transcript.h
-----------------------------------------------------------
Author: Shamar Harmon
Student number: 126746239
Email: sharmon@myseneca.ca
Subject: OOP244 NBB
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.7    2025/11/20  Completing .h file
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#ifndef SENECA_TRANSCRIPT_H
#define SENECA_TRANSCRIPT_H
#include <iostream>
#include "Marks.h"

namespace seneca {

    class Transcript : public Marks {
        char* m_stuName{};
        unsigned int m_stuNum{};
    public:
        Transcript(const char* stuName, unsigned int stuNo);
        Transcript(const Transcript&);
        Transcript& operator=(const Transcript&);
        ~Transcript();
        void init(const Transcript&);
        std::ostream& display(std::ostream& ostr = std::cout)const;
    };
}
#endif // !SENECA_TRANSCRIPT_H
