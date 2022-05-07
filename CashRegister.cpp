#include <iostream>
#include "Performance.cpp"

const int MAX_SIZE = 100;

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

    bool isHallDateEmpty(int date, Hall hallNum){
        for(int i = 0; i < size; i++){
           if(performances[i].date == date && performances[i].hall == hallNum){
               return false;
           }
        }

        return true;
    }

    void addNewEvent(int date, char* name, Hall hallNum){
        if(isHallDateEmpty(date, hallNum)){
            performances[size] = new Performance(name, date, hallNum);
            size++;
        }
        else {
            std::cerr<< "Event already exists!" << std::endl;
        }
    }

    void printAll() const{
        for(int i = 0; i < size; i++){
            std::cout<< performances[i].name << " " << performances[i].hall << " " << performances[i].date << std::endl; 
        }
    }

};
