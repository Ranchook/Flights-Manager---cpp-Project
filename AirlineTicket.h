#pragma once
#include "Person.h"
#define INVALID_TICKET_NUMBER "Invalid ticket number"
#define INVALID_MEAL "Invalid meal"
#define INVALID_TICKET_TYPE "Invalid ticket type"
#define PASSENGER_REQUIRED "Passenger required"

typedef enum TicketType { oneWay, roundTrip };
typedef enum Meal { kosher, vegan, regular, childMeal, glutenFree, chef };


/************************************
AirlineTicket:
a class that holds information about the ticket
************************************/
class AirlineTicket
{
	Meal meal;//Holds Meal 
	Person passenger;//holds the person which ticket belongs to
	static int counter;
	TicketType ticketType;//Holds TicketType
	int ticketNumber;//primary key for unique ticket
	const static int num_of_ticket_type;//Maximum number of flight ticket types
	const static int num_of_meal;//Maximum number of meal types
	//private methods: setting ticket number
	void setTicketNumber(const int& )throw(const char*);//private method that checks ticketnumber validation and assign this value
public:
	AirlineTicket(TicketType ticketType = oneWay);
	AirlineTicket(const AirlineTicket& );

	~AirlineTicket();

	//return static counter
	static int getCounter() { return counter; }
	//return meal
	Meal getMeal() const { return meal; }
	//return passenger
	Person getPassenger() const { return passenger; }
	//return ticketType
	TicketType getTicketType() const { return ticketType; }
	//return ticket number
	int getTicketNumber() const { return ticketNumber; }
	//set meal
	void setMeal(const Meal& ) throw (const char*);// check Meal validation and assign
	//set tickettype
	void setTicketType(const TicketType& ) throw (const char*);// check tickettype validation and assign
	
	 //compare this == ticket
	bool operator== (const AirlineTicket& ) const;
	
	//compare this < ticket
	bool operator< (const AirlineTicket& ) const;
	
	//compare this > ticket
	bool operator>(const AirlineTicket& ) const;
	
	//copy ticket
	const AirlineTicket& operator= (const AirlineTicket& );//assign ticket
	
	 //convert meal to string
	const char* Meal2String(const Meal& ) const;
	//convert ticket type to string
	const char* TicketType2String(const TicketType& ) const;
	//display ticket info to console
	friend ostream& operator<< (ostream& , const AirlineTicket& );//output ricket to stream
	
};
