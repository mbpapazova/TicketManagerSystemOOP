#include <iostream>
#include <cstring>
#include "TicketManager.cpp"
using namespace std;


int main() {
    Hall h1 = { 1, 6, 8 };
    Hall h2 = { 2, 3, 12 };
    Hall h3 = { 3, 3, 12 };

    TicketManager manager(10);

    char* movie1 = new char[10];
    strcpy_s(movie1, 10, "Spiderman");
    manager.addNewEvent(movie1, 1, h1);

    char* movie2 = new char[7];
    strcpy_s(movie2, 7, "Batman");
    manager.addNewEvent(movie2, 3, h1);

    char* movie3 = new char[8];
    strcpy_s(movie3, 8, "Ironman");
    manager.addNewEvent(movie3, 3, h2);

    std::cout << " ----------- " << std::endl;
    manager.printAll();
    std::cout << " ----------- " << std::endl;
  
    h1.printFreeSeats();
    h2.printFreeSeats();

    manager.freeSeats(movie1, 1);

    manager.freeSeats(movie2, 3);

    return 0;

}
