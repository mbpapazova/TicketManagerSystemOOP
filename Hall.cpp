#include <iostream>

class Hall {
private:

    int numberOfHall;
    int numberOfLines;
    int numberOfSeats;


public:

    Hall(int numberOfHall, int numberOfLines, int numberOfSeats);

    int getNumberOfHall() const { return numberOfHall; } 
    int getNumberOfLines() const { return numberOfLines; } 
    int getNumberOfSeats() const { return numberOfSeats; } 

   friend bool operator==(const Hall& l, const Hall& r) {
        return l.getNumberOfHall() == r.getNumberOfHall();
    }

};
