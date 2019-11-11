//
// Created by Diya Shenoy on 2019-11-11.
//

#ifndef UNOTRIAL1_UNO_H
#define UNOTRIAL1_UNO_H

// Header file for the Uno namespace specfied as a part of the assignment requirements
using namespace std;
namespace uno {
    class card {
    public:
        // Variables
        std::string color;
        int number;

        // Constructor
        card(std::string c, int n)
        {
            color = c;
            number = n;
        }
    };
}

#endif //UNOTRIAL1_UNO_H
