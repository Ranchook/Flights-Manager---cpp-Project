#include "Capsule.h"

Capsule::Capsule(int cap = 0, int price = 0)
{
	//Capsule constructor
	setPrice(price);
	setCapacity(cap);
	numOfTickets = 0;
	tickets = nullptr;
}

void Capsule::setCapacity(int cap)
{
	//setting capacity as declared in main file
	try {
		if (cap <= 0)
			throw "Error! Capacity invalid";
		capacity = cap;
	}
	catch (const char* emsg)
	{cout << emsg << endl;}	
}

void Capsule::setPrice(int price)
{
	//setting ticket price as declared in main file
	try {
		if (price <= 0)
			throw "Error! Price invalid";
		ticketPrice = price;
	}
	catch (const char* emsg)
	{cout << emsg << endl;}	
}

int Capsule::getPrice()
{
	return ticketPrice;
}

int Capsule::getCapacity()
{
	return capacity;
}

int Capsule::getNumOfTickets()
{
	return numOfTickets;
}

const AirlineTicket * Capsule::getTickets(int indx)
{
	//return specific ticket
	try{
		if (indx > numOfTickets || indx < 0)
			throw "invalid index";
		return tickets[indx];
	}
	catch (const char* eMsg)
	{cout << eMsg << endl;}
}

const bool Capsule::isFull()const
{
	//checking if capsule is full
	if (numOfTickets == capacity)
		return true;
	return false;
}

const bool Capsule::isEmpty() const
{
	//checking if capsule is empty
	if (numOfTickets == 0)
		return true;
	return false;
}

void Capsule::operator+=(AirlineTicket * ticket)
{
	int i;
	try {
		//if capsule is full, exit
		if (isFull())
			throw "Error! Full capacity!";
		//if not first ticket
		if (numOfTickets != 0)
		{
			for (i = 0; i < numOfTickets; i++)
			{
				//if ticket already exists, exit
				if (ticket == tickets[i])
					throw ticket;
			}
		}
	}
	catch(const char* eMsg)
	{cout << eMsg << endl;}

	catch (const AirlineTicket* bad)
	{cout << "Error! The ticket " << bad << " was already used!" << endl;}

	//adding new ticket to tickets array
	numOfTickets++;
	AirlineTicket** temp = new AirlineTicket*[numOfTickets];
	for (i = 0; i < numOfTickets-1; i++)
		temp[i] = tickets[i];
	temp[i] = ticket;
	tickets = temp;
}

void Capsule::operator-=(const AirlineTicket *ticket)
{
	//saving original number of tickets for future use
	int tempNum = numOfTickets;
	try {
		//if capsule is empty, exit
		if (isEmpty())
			throw "Error! Plane is Empty!";
	
		for (int i = 0; i < numOfTickets; i++)
		{
			//if found ticket, delete it
			if (ticket == tickets[i])
			{
				//if last ticket - delete it
				if (i == numOfTickets - 1)
					delete tickets[i];
				//if not last ticket
				else
				{
					//pushback array
					for (int j = i; j < numOfTickets - 1; j++)
						tickets[j] = tickets[j + 1];
					//copy array to temp excluding the last duplicated item
					AirlineTicket** temp = new AirlineTicket*[numOfTickets - 1];
					for (int j = 0; j < numOfTickets - 1; j++)
						temp[j] = tickets[j];
					//delete array and assigning the corrected one to place
					delete[] tickets;
					delete ticket;
					tickets = temp;
				}
				//decrease number of tickets
				numOfTickets--;
			}
		}
		//if ticket not found
		if(tempNum == numOfTickets)
			throw ticket;
	}

	catch (const char* eMsg) // enpty plane
	{cout << eMsg << endl;}

	catch (AirlineTicket bad) // no ticket found
	{cout << "The ticket " << bad << " doesn't exist!" << endl;}
}

Capsule::operator int() const
{
	//casting to int, returning available seats
	return capacity - numOfTickets;
}

Capsule::Capsule(const Capsule & c)
{
	//copy constructor
	this->numOfTickets = 0; // will be changed automatically with += operator
	this->capacity = c.capacity;
	this->ticketPrice = c.ticketPrice;
	this->tickets = nullptr; // will be changed automatically with += operator
	//copy tickets by value
	for (int i = 0; i < c.numOfTickets; i++)
		this->operator+= (new AirlineTicket(*c.tickets[i]));
}

Capsule::~Capsule()
{
	//destructor
	int temp = numOfTickets;// saving original number of tickets to use in loop
	for (int i = temp - 1; i >= 0; i--)
		this->operator-=(tickets[i]);	
	delete[] tickets;
}

ostream & operator<<(ostream & out, const Capsule & c)
{
	//print operator
	try {
		out << "The price of a ticket is: " << c.ticketPrice << endl;
		out << "Capacity of Capsule is: " << c.capacity << endl;
		out << c.numOfTickets << " tickets were sold." << endl;

		if (c.isEmpty())
			throw "Capsule is Empty!";

		cout << "Tickets data:" << endl;
		for (int i = 0; i < c.numOfTickets; i++)
			out << *c.tickets[i];
		cout << endl;
	}
	catch (const char* eMsg)
	{cout << eMsg << endl;}
}