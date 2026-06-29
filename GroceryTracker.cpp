#include <iostream>
#include <fstream>
#include "GroceryTracker.h"

using namespace std;

void GroceryTracker::LoadItems(string fileName) {
   ifstream inputFile(fileName);
   string itemName;

   if (!inputFile.is_open()) {
      cout << "Error: Could not open " << fileName << endl;
      return;
   }

   while (inputFile >> itemName) {
      itemFrequency[itemName]++;
   }

   inputFile.close();
}

void GroceryTracker::CreateBackupFile(string fileName) {
   ofstream outputFile(fileName);

   if (!outputFile.is_open()) {
      cout << "Error: Could not create " << fileName << endl;
      return;
   }

   for (auto item : itemFrequency) {
      outputFile << item.first << " " << item.second << endl;
   }

   outputFile.close();
}

int GroceryTracker::GetItemFrequency(string itemName) {
   if (itemFrequency.count(itemName) == 0) {
      return 0;
   }

   return itemFrequency[itemName];
}

void GroceryTracker::PrintAllFrequencies() {
   for (auto item : itemFrequency) {
      cout << item.first << " " << item.second << endl;
   }
}

void GroceryTracker::PrintHistogram() {
   for (auto item : itemFrequency) {
      cout << item.first << " ";

      for (int i = 0; i < item.second; ++i) {
         cout << "*";
      }

      cout << endl;
   }
}
