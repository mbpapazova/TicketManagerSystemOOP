#include <iostream>
#include <cstring>
#include "Hall.cpp"

class Performance {
private:
    char* name;
    Hall hall;
    int date;

    void copy(const Performance& other) {
		this->name = new char[strlen(other.name) + 1];
        strcpy_s(this->name, strlen(other.name) + 1, other.name);

        this->hall = other.hall;
        this->date = other.date;
	}

public:

   Performance(){
       this->date = 0;
       this->name = nullptr;
       this->hall = Hall();
   }

   Performance(const char* name, int date, Hall hall) {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name, strlen(name) + 1, name);

        this->hall = hall;
        this->date = date;
    }


    Performance(const Performance& other){
        copy(other);
    }

    Performance& operator=(const Performance& other){
        if(this != &other) {
        delete[] name;
        copy(other);
        }

        return *this;
    }

    ~Performance() { delete[] name; }

    const char* getName() const { return name; }

    int getDate() const { return date; }
   
    Hall getHall() const { return hall; }
    
};
