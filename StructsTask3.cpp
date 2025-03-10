/*
Задача 3. Структурата Fruit, определяща плод, е дефинирана по следния начин:
struct Fruit
{
  char name[32]; // име на плод
  color cl;      // цвят на плод
  yn annual;     // едногодишен плод
  yn perennial;  // многогодишен плод
  yn tropical;   // тропически плод
};
където:
- color е изброен тип за цвят (напр. brown, green, orange, red, yellow и т.н.)
- yn е изброен тип с две стойности Yes и No
Напишете програма, която:
а) създава едномерен масив от указатели към структури, задаващи плодове и прочита данните от клавиатурата;
б) сортира по име, цвят и продължителност на плододаване плодовете, зададени чрез масива;
в) извежда данните за плодовете, зададени чрез масива, след сортирането им;
г) извежда многогодишните, тропически плодове с даден цвят, сортирани в низходящ ред по име на плода.
За целта да се дефинират подходящи функции. Постарайте се да гарантирате коректност на данните.
*/

/*
Task 3. The Fruit structure defining a fruit is defined as follows:
struct Fruit
{
  char name[32]; // fruit name
  color cl; // fruit color
  yn annual; // annual fruit
  yn perennial; // perennial fruit
  yn tropical; // tropical fruit
};
where:
- color is an enumerated type for color (e.g. brown, green, orange, red, yellow, etc.).
- yn is an enumerated type with two values Yes and No
Write a program that:
(a) creates a one-dimensional array of pointers to structures specifying fruits and reads the data from the keyboard;
b) sorts by name, color, and fruiting duration the fruits specified by the array;
c) outputs the data for the fruits specified by the array after sorting them;
d) outputs the perennial, tropical fruits of a given color, sorted in descending order by fruit name.
For this purpose, define appropriate functions. Try to ensure correctness of the data.
*/

#include <iostream>
#include <algorithm>

using namespace std;

enum color {
    Brown = 1,
    Green,
    Orange,
    Red,
    Yellow
};

enum Yn {
    Yes,
    No
};

struct Fruit {
    char name[32];
    color cl;
    Yn annual;
    Yn perennial;
    Yn tropical;
};

void CreateFruits(Fruit* arr[], const size_t& s);
string ColorToString(color a);
string TypeCycleToString(Yn a);
bool CompareFruitsAscending(Fruit* a, Fruit* b);
bool CompareFruitsDescending(Fruit* a, Fruit* b);
void SortFruitsAscending(Fruit* arr[], int size);
void SortFruitsDescending(Fruit* arr[], int size);
void PrintFruits(Fruit* arr[], int size);
void PrintTropicalFruits(Fruit* arr[], int size);


int main()
{
    int size = 0;

    cout << "Enter how many Fruits do you want to create: ";
    cin >> size;

    //Allocates memory for the fruits
    Fruit** fruitsArray = new(nothrow) Fruit*[size];
    if (!fruitsArray) {
        cerr << "Couldn`t allocate memory!\n";
        return -1;
    }

    Fruit** tempFruitsArray = new Fruit*[size];
 
    CreateFruits(fruitsArray, size);
    copy(fruitsArray, fruitsArray + size, tempFruitsArray);
    SortFruitsAscending(fruitsArray,size);
    PrintFruits(fruitsArray,size);
    PrintTropicalFruits(tempFruitsArray, size);


    //Release the allocated memory
    for (size_t i = 0; i < size; ++i) {
        delete fruitsArray[i];
    }
    delete[] fruitsArray;
}

 void CreateFruits(Fruit* arr[], const size_t& s) {
     int numColor = 0;
     int tropicalType = 0;
     int timeCycle = 0;



     for (size_t i = 0; i < s; ++i) {
         arr[i] = new Fruit();

         //This sets the Fruit name
         cout << "Enter Fruit name: ";
         cin >> arr[i]->name;


         //This sets the Fruit Color
         cout << "Choose Fruit color: \n";
         cout << "1. Brown\n";
         cout << "2. Green\n";
         cout << "3. Orange\n";
         cout << "4. Red\n";
         cout << "5. Yellow\n";

         while (true) {
             cin >> numColor;
             if (numColor >= 1 && numColor <= 5) {
                 break;
             }
             else {
                 cout << "\nYou must choose an option between 1 and 5!\n";
             }

         }

         if (numColor == color::Brown) {
             arr[i]->cl = color::Brown;
         }
         else if (numColor == color::Green) {
             arr[i]->cl = color::Green;
         }
         else if (numColor == color::Orange) {
             arr[i]->cl = color::Orange;
         }
         else if (numColor == color::Red) {
             arr[i]->cl = color::Red;
         }
         else {
             arr[i]->cl = color::Yellow;
         }


         //Sets the time cycle of the fruit to either annual or perenniel
         cout << "Choose if the fruit time cycle is annual or perennial: \n";
         cout << "1. Annual\n";
         cout << "2. Perennial\n";
         while (true) {
             cin >> timeCycle;
             if (timeCycle == 1 || timeCycle == 2) {
                 break;
             }
             cout << "\nYou have to choose between option 1 or 2!\n";
         }

         if (timeCycle == 1) {
             arr[i]->annual = Yn::Yes;
             arr[i]->perennial = Yn::No;
         }
         else {
             arr[i]->annual = Yn::No;
             arr[i]->perennial = Yn::Yes;
         }

        
         //Sets if the fruit is tropical or not
         cout << "Is the fruit tropical?\n";
         cout << "1. Yes\n";
         cout << "2. No\n";

         while (true) {
             cin >> tropicalType;
             if ((tropicalType - 1) == 0 || (tropicalType - 1) == 1) {
                 break;
             }
             cout << "\nYou have to choose between option 1 or 2!\n";

         }
         if (tropicalType - 1 == 0) {
             arr[i]->tropical = Yn::Yes;
         }else{
             arr[i]->tropical = Yn::No;
         }
     }

}

 
 void SortFruitsAscending(Fruit* arr[], int size) {    
     sort(arr, arr + size, CompareFruitsAscending);
 }

 void SortFruitsDescending(Fruit* arr[], int size) {
     sort(arr, arr + size, CompareFruitsDescending);
 }

 //Compare fruits based on name, color and TypeCycle in ascending way
 bool CompareFruitsAscending(Fruit* a, Fruit* b) {
     if (strcmp(a->name, b->name) == 0) {
         if (a->cl == b->cl) {
             return a->annual < b->annual;
         }

         return a->cl < b->cl;
     }

     return strcmp(a->name, b->name) < 0;
 }

 bool CompareFruitsDescending(Fruit* a, Fruit* b) {
     return a->name > b->name;
 }

 void PrintTropicalFruits(Fruit* arr[], int size) {
     size_t  option = 0;
     cout << "\nChoose the color of the tropical fruits that you want to print\n";
     cout << "1. Brown\n";
     cout << "2. Green\n";
     cout << "3. Orange\n";
     cout << "4. Red\n";
     cout << "5. Yellow\n";

     while (true) {
         cin >> option;
         if (option >= 1 && option <= 5) {
             break;
         }
         cout << "\nYou have to choose between options from 1 to 5!\n";
     }

     //Create a temporary array to store only the tropical fruits
     Fruit** tropicalFruits = new Fruit* [size];
     int tropicalFruitsCount = 0;

     //Store the tropical fruits in the new array
     for (size_t i = 0; i < size; ++i) {
         if (arr[i]->cl == option && arr[i]->tropical == Yn::Yes) {
             tropicalFruits[tropicalFruitsCount] = arr[i];
             tropicalFruitsCount++;
         }
     }

     //Check if there are any tropical fruits at all
     if (tropicalFruitsCount == 0) {
         cout << "\nThere are no tropical fruits!\n";
         delete[] tropicalFruits;
             return;
     }

     //Sorts the tropical fruits in descending order
     SortFruitsDescending(tropicalFruits, tropicalFruitsCount);

     cout << "Tropical Fruits: \n";
     for (size_t i = 0; i < tropicalFruitsCount; ++i) {
             cout << "Name: " << tropicalFruits[i]->name << "\n";
             cout << "Color: " << ColorToString(tropicalFruits[i]->cl) << "\n";
             cout << "Annual: " << TypeCycleToString(tropicalFruits[i]->annual) << "\n";
             cout << "Perennial: " << TypeCycleToString(tropicalFruits[i]->perennial) << "\n";
             cout << "Tropical: " << TypeCycleToString(tropicalFruits[i]->tropical) << "\n";
             cout << "\n";
         }

     delete[] tropicalFruits;

 }

 void PrintFruits(Fruit* arr[], int size) {
     for (size_t i = 0; i < size; ++i) {
         cout << "Name: " << arr[i]->name << "\n";
         cout << "Color: " << ColorToString(arr[i]->cl) << "\n";
         cout << "Annual: " << TypeCycleToString(arr[i]->annual) << "\n";
         cout << "Perennial: " << TypeCycleToString(arr[i]->perennial) << "\n";
         cout << "Tropical: " << TypeCycleToString(arr[i]->tropical) << "\n";
         cout << "\n";
     }
 }


 string ColorToString(color a) {
     switch (a) {
     case color::Brown: return "Brown";
     case color::Green: return "Green";
     case color::Orange: return "Orange";
     case color::Red: return "Red";
     case color::Yellow: return "Yellow";
     default: return "Unknown";
     }
 }

 string TypeCycleToString(Yn a) {
     switch (a) {
     case Yn::Yes: return "Yes";
     case Yn::No: return "No";
     default: return "Unknown";
     }
 }
