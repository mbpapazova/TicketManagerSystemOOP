#include <iostream>
#include "Hall.cpp"

class Performance {
private:

    char* name;
    Hall hall;
    int date;

      void copy(const Performance& other) {
		this->name = new char[other.name];
		for (unsigned i = 0; i < size; i++) {
			name[i] = name[i];
		}

        this->hall = other.hall;
        this->date = other.date;
	}

public:

    Performance(const char* name, Hall hall, int date){
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);

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
    
};