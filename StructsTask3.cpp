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

#include <iostream>

using namespace std;

enum color {
    Brown,
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


int main()
{
    int size = 0;

    cout << "Enter how many Fruits do you want to create: ";
    cin >> size;
    Fruit** fruitsArray = new Fruit*[size];
    CreateFruits(fruitsArray, size);


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
                 cout << "\nYou must choose an option between 0 and 4!\n";
             }

         }

         if (numColor - 1 == color::Brown) {
             arr[i]->cl = color::Brown;
         }
         else if (numColor - 1 == color::Green) {
             arr[i]->cl = color::Green;
         }
         else if (numColor - 1 == color::Orange) {
             arr[i]->cl = color::Orange;
         }
         else if (numColor - 1 == color::Red) {
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
             cout << "\nChoose between 0 and 1!\n";

         }
         if (tropicalType == 0) {
             arr[i]->tropical = Yn::Yes;
         }else{
             arr[i]->tropical = Yn::No;
         }
     }

}
