#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <vector>
#include <fstream>

// Local imports
#include "uno.h"

using namespace std;

int main(int argc, char *argv[])
{
    // Variables to hold the files
    string deckFilePath = argv[1];
    string rulesFilePath = argv[2];

    if (argc == 4)
    {
        // Convert the string to an integer
        srand(atoi(argv[3]));
    }
    else
    {
        srand(chrono::system_clock::now().time_since_epoch().count());
    }

    // Open the deck file for reading
    fstream deckFile;
    deckFile.open(deckFilePath, ios::in);
    cout << deckFile.is_open() << "\n";

    // Declare the deck which will be a vector of type card
    vector<uno::card> deck;

    string line;
    // Read file line by line
    while (getline(deckFile, line))
    {
        string values[3];
        int valueNumber = 0;
        for (int i = 0; i < line.size(); i++)
        {
            // If current character is a space, consider the value finalized
            if (line[i] != ' ')
            {
                values[valueNumber].push_back(line[i]);
            }
            else
            {
                // We've encountered a space. Move on to the next value
                valueNumber++;
            }
        }

        // We now have all 3 values
        // The first value is a number
        int numberOfCards = stoi(values[0]);

        // Second value is color
        string color = values[1];

        // Third is the number
        int number = stoi(values[2]);

        // Add these cards to the deck
        for (int i = 0; i < numberOfCards; i++)
        {
            deck.push_back(uno::card(color, number));
        }
    }

    // -- Diya --> Below code is only to display the deck. You can delete it and build the rules.
    cout << "Cards in the deck\n---------------------------\n";
    for (int i = 0; i < deck.size(); i++)
    {
        cout << "Card " << i + 1 << ":";
        cout << "\nColor: " << deck[i].color;
        cout << "\nNumber: " << deck[i].number;
        cout << "\n\n";
    }
}