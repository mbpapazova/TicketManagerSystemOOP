#include <iostream>
#include "CashRegister.cpp"

int main() {

    Hall h1 = {1, 2, 8};
    Hall h2 = { 2, 3, 12};

    TicketManager manager(5);

    manager.addNewEvent(1, "Spinderman", h1);

    manager.printAll();



}