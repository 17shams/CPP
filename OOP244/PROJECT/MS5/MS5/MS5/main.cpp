/* Citation and Sources...
Final Project Milestone 5:
Module: [Main]
Filename: main.cpp
Version 1.0
Author: Shamar Harmon, StNo: 126746239, Email: sharmon@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/30  Completed main.cpp
-----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my work for function whatever.
-----------------------------------------------------------*/
#include <iostream>
#include "Menu.h"
#include "Ordering.h"
using namespace std;
using namespace seneca;

int main() {

    Ordering ord("drinks.csv", "foods.csv");

    if (!ord) {
        cout << "Failed to open data files or the data files are corrupted!" << endl;
        return 1;
    }

    Menu mainMenu("Seneca Restaurant ", "End Program");
    mainMenu << "Order"
             << "Print Bill"
             << "Start a New Bill"
             << "List Foods"
             << "List Drinks";

    Menu orderMenu("Order Menu", "Back to main menu", 1, 3);
    orderMenu << "Food"
              << "Drink";

    Menu exitConfirm(
        "You have bills that are not saved, are you sue you want to exit?",
        "No",
        0,
        1
    );
    exitConfirm << "Yes";

    size_t mainSelection = 0;

    do {
        mainSelection = mainMenu.select();

        switch (mainSelection) {

        case 1: {
            size_t orderSelection = 0;

            do {
                orderSelection = orderMenu.select();

                switch (orderSelection) {
                case 1:
                    ord.orderFood();
                    break;

                case 2:
                    ord.orderDrink();
                    break;
                }

            } while (orderSelection != 0);

            break;
        }

        case 2:
            ord.printBill(cout);
            break;

        case 3:
            ord.resetBill();
            break;

        case 4:
            ord.listFoods(cout);
            break;

        case 5:
            ord.listDrinks(cout);
            break;

            case 0:
                if (ord.hasUnsavedBill()) {
                    size_t confirm = exitConfirm.select();

                    if (confirm == 1) {
                        return 0;
                    }
                    else {
                        mainSelection = 1;
                        break;
                    }
                }
                else {
                    return 0;
                }
            break;
        }

    } while (mainSelection != 0);

    return 0;
}

