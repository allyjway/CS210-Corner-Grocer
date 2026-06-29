#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

int main() {
   GroceryTracker tracker;
   int userChoice = 0;
   string itemName;

   tracker.LoadItems("CS210_Project_Three_Input_File.txt");
   tracker.CreateBackupFile("frequency.dat");

   while (userChoice != 4) {
      cout << endl;
      cout << "Corner Grocer Item Tracker" << endl;
      cout << "1. Search for an item" << endl;
      cout << "2. Print all item frequencies" << endl;
      cout << "3. Print item histogram" << endl;
      cout << "4. Exit" << endl;
      cout << "Enter your choice: ";
      cin >> userChoice;

      if (cin.fail()) {
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
         cout << "Invalid input. Please enter a number from 1 to 4." << endl;
         continue;
      }

      if (userChoice == 1) {
         cout << "Enter the item name: ";
         cin >> itemName;
         cout << itemName << " appears " << tracker.GetItemFrequency(itemName) << " time(s)." << endl;
      }
      else if (userChoice == 2) {
         tracker.PrintAllFrequencies();
      }
      else if (userChoice == 3) {
         tracker.PrintHistogram();
      }
      else if (userChoice == 4) {
         cout << "Goodbye!" << endl;
      }
      else {
         cout << "Invalid choice. Please enter a number from 1 to 4." << endl;
      }
   }

   return 0;
}
