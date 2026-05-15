/* Citation and Sources...
Final Project Milestone 5:
Module: [Menu]
Filename: Menu.h
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/13  Created and completed Menu.h
-----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my work for function whatever.
-----------------------------------------------------------*/

#ifndef SENECA_MENU_H_
#define SENECA_MENU_H_

#include <iostream>
#include "constants.h"

namespace seneca {

class Menu;

class MenuItem {
        char* m_content{};
        unsigned int m_numofIndents{};
        unsigned int m_size{};
        int m_row{};

        
        MenuItem(const char* content, unsigned int indents, unsigned int size, int row);
        MenuItem(const MenuItem&) = delete;
        MenuItem& operator=(const MenuItem&) = delete;
        ~MenuItem();

        void setEmpty();
        operator bool() const;
        std::ostream& display(std::ostream& ostr = std::cout) const;
        friend class Menu;
        
    };

class Menu {
    unsigned int m_indentNum{};
    unsigned int m_indentSize{};
    unsigned int m_numofItems{};
    MenuItem m_title;
    MenuItem m_exit;
    MenuItem m_prompt;
    MenuItem* m_items[MaximumNumberOfMenuItems];
   
public:
    Menu(const char* title = nullptr,
         const char* exit = nullptr,
         unsigned int indentNum = 0,
         unsigned int indentSize = 3);
    Menu(const Menu&) = delete;
    Menu& operator=(const Menu&) = delete;
    ~Menu();
   
    Menu& operator<<(const char* menuItemcontent);
    size_t select() const;
};

size_t operator<<(std::ostream& ostr, const Menu& m);

}

#endif // !SENECA_MENU_H_

