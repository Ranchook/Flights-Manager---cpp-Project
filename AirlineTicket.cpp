#include "AirlineTicket.h"
const int AirlineTicket::num_of_meal = chef;
const int AirlineTicket::num_of_ticket_type = roundTrip;
int AirlineTicket::counter = 0;
/*
name:AirlineTicket
parameters:TicketType
return value:this object
algorithm: increase ticket number by one(unique data)
call set meal,settickettype,and passneger default data
*/
AirlineTicket::AirlineTicket(TicketType ticketType) :passenger(Person()), ticketNumber(++counter)
{
	setMeal(regular);
	setTicketType(ticketType);
}
/*
name:AirlineTicket
parameters:ticket to copy
return value:this object
algorithm:increase ticket number by one(unique data) and call =operator
*/
AirlineTicket::AirlineTicket(const AirlineTicket& ticket) :passenger(ticket.passenger)
{
	*this = ticket;
}
/*
name:setTicketNumber
parameters:ticket numebr
return value:none
algorithm:validate ticket numbet > 0
if ok set this->ticketnumbet and update counter if ticketnumber is bigger
else throw INVALID_TICKET_NUMBER
*/
void AirlineTicket::setTicketNumber(const int& ticketNumber)throw(const char*)
{
	if(ticketNumber<0)
		throw INVALID_TICKET_NUMBER;

	this->ticketNumber = ticketNumber;
	if (counter < this->ticketNumber) 
		counter = this->ticketNumber;
}
/*
name:setMeal
parameters:Meak
return value:none
algorithm:check if meal is in enum range
if ok set meal
else throw INVALID_MEAL
*/
void AirlineTicket::setMeal(const Meal& meal) throw (const char*)
{
	if (meal < 0 || meal > num_of_meal)
		throw INVALID_MEAL;
	this->meal = meal;
}

/*
name:setTicketType
parameters:ticketType
return value:none
algorithm:check if ticket type is in enum range
if ok set ticket type
else throw INVALID_TICKET_TYPE
*/
void AirlineTicket::setTicketType(const TicketType& ticketType)throw (const char*)
{
	if (ticketType < 0|| ticketType > num_of_ticket_type)
		throw INVALID_TICKET_TYPE;

	this->ticketType = ticketType;
}
/*
name:operator<<
parameters:output stream, ticket to display,
return value:output stream for continuos
algorithm: display the ticket and print passenger
*/
ostream& operator<<(ostream& out, const AirlineTicket& ticket)
{
	out << left << setw(25) << setfill(' ') << "";
	out << left << setw(20) << setfill(' ') << ticket.ticketNumber;
	out << left << setw(12) << setfill(' ') << ticket.Meal2String(ticket.meal);
	out << left << setw(15) << setfill(' ') << ticket.TicketType2String(ticket.ticketType);
	out << left << setw(93) << setfill(' ') << "" << endl << endl;
	//out << (ticket.passenger);
	return out;
}
/*
name:operator==
parameters: ticket to compare
return value:true if equal
algorithm:compare between the ticket's numbers
*/
bool AirlineTicket::operator==(const AirlineTicket& ticket) const
{
	return this == &ticket;
}
/*
name:operator<
parameters:ticket to compare
return value:true if small
algorithm:compare between the order's ids and return if this < numberticket
*/
bool AirlineTicket::operator<(const AirlineTicket& ticket) const
{
	return this->ticketNumber < ticketNumber;
}
/*
name:operator>
parameters:ticket to compare
return value:true if greater
algorithm:check if ticket is NOT equal AND NOT bigger then this (using De morgan laws)
*/
bool AirlineTicket::operator>(const AirlineTicket& ticket) const
{
	return !(*this < ticket || *this == ticket);
}
/*
name:TicketType2String
parameters:TicketType
return value:string of enum
algorithm:find the required enum value and return it's string
*/
const char* AirlineTicket::TicketType2String(const TicketType& ticketType) const {
	switch (ticketType)
	{
	case oneWay:
		return "oneWay";
	case roundTrip:
		return "roundTrip";
	default:
		return "";
	}

}
/*
name:Meal2String
parameters:Meal
return value:string of enum
algorithm:find the required enum value and return it's string
*/
const char* AirlineTicket::Meal2String(const Meal& meal) const {
	switch (meal)
	{
	case kosher:
		return "kosher";
	case vegan:
		return "vegan";
	case regular:
		return "regular";
	case childMeal:
		return "child Meal";
	case glutenFree:
		return "gluten Free";
	case chef:
		return "chef";
	default:
		return "";
	}
}
/*
name:operato=
parameters:ticket to copy
return value:this object
algorithm: if address are different we set ticket's data
*/
const AirlineTicket& AirlineTicket::operator=(const AirlineTicket& ticket)
{
	if (this != &ticket)
	{
		setTicketType(ticket.ticketType);
		setMeal(ticket.meal);
		this->ticketNumber = ticket.ticketNumber;
	}
	return *this;
}

AirlineTicket::~AirlineTicket() 
{
	counter--;
}
