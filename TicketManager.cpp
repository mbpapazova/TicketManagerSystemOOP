#include <iostream>
#include <cstring>
#include "Performance.cpp"
using namespace std;

class TicketManager {
private:

    Performance* performances;
    unsigned capacity;
	unsigned size;

    void copy(const TicketManager& other) {
		capacity = other.capacity;
		size = other.size;

		performances = new Performance[other.capacity];
		for (unsigned i = 0; i < size; i++) {
			performances[i] = other.performances[i];
		}
	}

    
public:

    TicketManager(unsigned N) : capacity(N), size(0){
        performances = new Performance[capacity];
    }

    TicketManager(const TicketManager& other) {
		copy(other);
	}

	TicketManager& operator=(const TicketManager& other) {
		if (this != &other) {
			delete[] performances;
			copy(other);
		}
		return *this;
	}

	~TicketManager() { delete[] performances; }

    int getCapacity() const { return capacity; }

	int getSize() const { return size; }

    bool isHallDateEmpty(int date, Hall hallNum){
        for(unsigned i = 0; i < size; i++){
           if(performances[i].getDate() == date && performances[i].getHall().getNumberOfHall() == hallNum.getNumberOfHall()){
               return false;
           }
        }

        return true;
    }
//ново събитие
    void addNewEvent(char* name, int date, Hall hallNum){
        if(isHallDateEmpty(date, hallNum)){
           performances[size] = Performance(name, date, hallNum);
           size++;
        }
        else {
            std::cerr<< "Event already exists!" << std::endl;
        }
    }

//свободни места
    void freeSeats(char* name, int date){

        for(unsigned i = 0; i < size; i++){
            if(strcmp(performances[i].getName(), name) == 0 && performances[i].getDate() == date){
                cout << "FOUND: " << performances[i].getName() << endl;
                cout << "-------------------------" << endl;
                performances[i].getHall().printFreeSeats();
                cout << "-------------------------" << endl;
            }
        }
        
    }

//резервация на билет


//отмяна на резервация

//закупуване на билет

//списък с резервации

//справка за закупени билети

     void printAll() const{
        for(unsigned i = 0; i < size; i++){
            std::cout << performances[i].getName() << " " << performances[i].getHall().getNumberOfHall() << " " << performances[i].getDate() << std::endl; 
        }
    }

};

