#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

using namespace std;

class GroceryTracker {
   private:
      map<string, int> itemFrequency;  

   public:
      void LoadItems(string fileName);
      void CreateBackupFile(string fileName);
      int GetItemFrequency(string itemName);
      void PrintAllFrequencies();
      void PrintHistogram();
};

#endif
