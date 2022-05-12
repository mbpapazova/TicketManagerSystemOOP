#include <iostream>

class Hall {
private:

    int numberOfHall;
    int numberOfRows;
    int numberOfSeats;
    int seats[20][20];

public:

    Hall(){
        numberOfHall = 0;
        numberOfRows = 0;
        numberOfSeats = 0;

        this->setSeats();
    }

    Hall(int numberOfHall, int numberOfRows, int numberOfSeats) {
        this->numberOfHall = numberOfHall;
        this->numberOfRows = numberOfRows;
        this->numberOfSeats = numberOfSeats;

        this->setSeats();
    }

    Hall(const Hall& other){
        numberOfHall = other.numberOfHall;
        numberOfRows = other.numberOfRows;
        numberOfSeats = other.numberOfSeats;
        
        for(int i=0; i < this->numberOfRows; i++){
            for(int j=0; j < this->numberOfSeats; j++) {
                this->seats[i][j] = other.seats[i][j];
            }
        }
    }

    Hall& operator=(const Hall& other){
        if(this != &other){
            numberOfHall = other.numberOfHall;
            numberOfRows = other.numberOfRows;
            numberOfSeats = other.numberOfSeats;
            
            for (int i = 0; i < this->numberOfRows; i++) {
                for (int j = 0; j < this->numberOfSeats; j++) {
                    this->seats[i][j] = other.seats[i][j];
                }
            }
        }
        return *this;
    }

    int getNumberOfHall() const { return numberOfHall; } 
    int getNumberOfRows() const { return numberOfRows; } 
    int getNumberOfSeats() const { return numberOfSeats; } 

    void setSeats() {
        for (int i = 0; i < this->numberOfRows; i++) {
            for (int j = 0; j < this->numberOfSeats; j++) {
                this->seats[i][j] = 0;
            }
        }
    }


   void getFreeSeats() {
        std::cout<< "Free seats: " << std::endl;

        for(int i=0; i < numberOfRows; i++){
            for(int j=0; j < numberOfSeats; j++) {
                if(this->seats[i][j] == 0) {
                   std::cout << "SEAT AT ROW: " << i << ", NUM: " << j << " is free" << std::endl; 
                }
            }
        }
    }

   void printFreeSeats() {
       for (int i = 0; i < numberOfRows; i++) {
           for (int j = 0; j < numberOfSeats; j++) {
               if (this->seats[i][j] == 0) {
                   std::cout << "0 ";
               }
               else {
                   std::cout << "1 ";
               }
           }
           std::cout << std::endl;
       }
   }

    friend bool operator==(const Hall& l, const Hall& r) {
        return l.getNumberOfHall() == r.getNumberOfHall();
    }

    friend std::ostream& operator<<(std::ostream& os, const Hall& hall){
         os<< hall.getNumberOfHall() << " " << hall.getNumberOfRows() << " " << hall.getNumberOfSeats() << std::endl;
    return os;
    }

};
