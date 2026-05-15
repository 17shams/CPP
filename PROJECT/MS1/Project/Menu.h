/* Citation and Sources...
Final Project Milestone 1:
Module: [Menu]
Filename: Menu.h
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/05  Created and completed Menu.h
-----------------------------------------------------------
 I have done all the work myself
-----------------------------------------------------------*/

#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_

#include <iostream>

namespace seneca {


    class MenuItem {
        char* m_content{};
        unsigned int m_numofIndents{};
        unsigned int m_size{};
        int m_row{};

    public:
        MenuItem();
        MenuItem(const char* content, unsigned int indents, unsigned int size, int row);
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        ~MenuItem();

        void setEmpty();
        operator bool() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;


        friend std::ostream& operator<<(std::ostream& os, const MenuItem& M);
    };



}

#endif // !SENECA_MENU_H_

