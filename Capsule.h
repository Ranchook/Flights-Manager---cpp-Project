#pragma once
#include "AirlineTicket.h"
class Capsule
{
	int ticketPrice; 
	AirlineTicket** tickets;
	int capacity;
	int numOfTickets;
	void setCapacity(const int); // setting capsule capacity

public:
	Capsule(int cap, int price); // constructor
	void setPrice(const int); // setting price
	int getPrice();	//return price
	int getCapacity();	//return capacity
	int getNumOfTickets();	//return number of tickets
	const AirlineTicket* getTickets(int);	//return ticket
	const bool isFull() const;	// checking if capsule is full
	const bool isEmpty() const;	// checking if capsule is empty
	void operator  +=( AirlineTicket*); //adding ticket to tickets array
	void operator  -=(const AirlineTicket*); //removing ticket from tickets array
	friend ostream& operator<<(ostream& out, const Capsule& c); //printing operator
	operator int() const ; // casting data to int
	Capsule(const Capsule &c); // copy constructor
	~Capsule(); // destructor
};

