#include "Flight.h"

int Flight::counter = 0;
/*
name:Flight
parameters:departure, arrival, destination, isCoronaFree
return value:this object
algorithm:constructor, that update flightID by increment by 1 the counter
and call setters
*/
Flight::Flight(const Capsule& classRegular, const First& classFirst, int maxCrew , const char* destination , DateTime departure, DateTime arrival, bool coronaFree) :classFirst(classFirst), flightId(++counter),classRegular(classRegular)
{
	setDeparture(departure);
	setArrival(arrival);
	setDestination(destination);
	setCoronaFree(coronaFree);
	this->maxCrew = maxCrew;
	crew = new Person * [maxCrew];
	this->currentCrew = 0;
}
/*
name:~Flight
parameters:none
return value:none
algorithm:free all crew and capsules with the help of the free method template
*/
Flight::~Flight()
{
	for (int i = 0; i < currentCrew; i++)
		delete crew[i];
	delete[] crew;
}

/*
name:setDeparture
parameters:departure
return value:none
algorithm:check validation
if ok set data
else throw INVALID_DEPARTURE
*/
void Flight::setDeparture(const DateTime& departure)  throw (const char*)
{
	if (departure < 0)
		throw INVALID_DEPARTURE;

	this->departure = departure;
}
/*
name:setArrival
parameters:arrival
return value:none
algorithm:check validation
if ok set data
else throw INVALID_ARRIVAL
*/
void Flight::setArrival(const DateTime& arrival)  throw (const char*)
{
	if (arrival < 0)
		throw INVALID_ARRIVAL;

	this->arrival = arrival;
}
/*
name:setDestination
parameters:destination
return value:none
algorithm:check validation
if ok set data
else throw INVALID_DESTINATION
*/
void Flight::setDestination(const char* destination)throw (const char*)
{
	for (int i = 0; destination[i] != '\0'; i++)
		if (isdigit(destination[i]))
			throw INVALID_DESTINATION;

	delete[]this->destination;
	this->destination = _strdup(destination);
}
/*
name:setFlightId
parameters:flightID
return value:none
algorithm:check validation
if ok set data
else throw INVALID_FLIGHTID
*/
void Flight::setFlightId(const int& flightID) {
	if(flightID<0)
		throw INVALID_FLIGHTID;

	this->flightId = flightID;
	if (counter < this->flightId) 
		counter = this->flightId;
}
/*
name:setCoronaFree
parameters:isCoronaFree
return value:none
algorithm:set data
*/
void Flight::setCoronaFree(const bool& isCoronaFree) 
{
	this->coronaFree = isCoronaFree;
}


/*
name:operator+=
parameters:person to add
return value:this object
algorithm:check if person exits, throw CREW_EXIST if so
add person to crew
*/
const Flight& Flight::operator+=(Person& p)  throw (const char*)
{
	for (int i = 0; i < currentCrew; i++)
		if (*crew[i]==p)
			throw CREW_EXIST;

		if (currentCrew <= maxCrew)
			crew[currentCrew++] = new Person(p);
		else throw CREW_FULL;
	return *this;
}

/*
name:operator-=
parameters:person to remove
return value:this object
algorithm:check if person exits, throw CREW_NOT_EXIST if not
remove and delte crew
*/
const Flight& Flight::operator-=(Person& p)  throw (const char *)
{
	bool isexsist = false;
	for (int i = 0; i < currentCrew; i++)
	{
		if (*crew[i] == p)
		{	
			for (; i < currentCrew-1; i++)
			{
				delete crew[i];
				crew[i] = new Person(*crew[i + 1]);
				isexsist = true;
			}
			currentCrew--;
		}
	}
	if (!isexsist)
		throw CREW_NOT_EXIST;
	return *this;
}
/*
name:operator<<
parameters:output stream, flight to display,
return value:output stream for continuos
algorithm: display the flight  and call template method print for the crew and capsules
*/
ostream& operator<<(ostream& out, const Flight& f)
{
	out << left << setw(12) << setfill(' ') << "Flight ID";
	out << left << setw(22) << setfill(' ') << "Departure";
	out << left << setw(22) << setfill(' ') << "Arrival";
	out << left << setw(22) << setfill(' ') << "Destination";
	out << left << setw(15) << setfill(' ') << "Corona Free" << endl;
	out << left << setw(93) << setfill('_') << "" << endl << endl;

	out << left << setw(12) << setfill(' ') << f.flightId;
	out << left << setw(22) << setfill(' ') << f.departure;
	out << left << setw(22) << setfill(' ') << f.arrival;
	out << left << setw(22) << setfill(' ') << f.destination;
	out << left << setw(15) << setfill(' ') << (f.coronaFree ? "True" : "False") << endl << endl;
	out << left << setw(93) << setfill(' ') << "" << endl << endl;

	if (f.currentCrew)
	{
		out << left << setw(12) << setfill(' ') << "Crew: "; 
		out << left << setw(12) << setfill(' ') << "ID";
		out << left << setw(12) << setfill(' ') << "FullName";
		out << left << setw(12) << setfill(' ') << "Role" << endl;
		out << left << setw(93) << setfill('_') << "" << endl << endl;
		for (int i = 0; i < f.currentCrew; i++)
		{
			out << *f.crew[i]<<endl;
		}
	}
	out << left << setw(25) << setfill(' ') << "Capsule standard class: ";
	out <<f.classRegular;

	
	cout << f.classFirst;
	
	return out;
}

/*
name:operator==
parameters: flight to compare
return value:true if equal
algorithm:compare between the flight's ids
*/
bool Flight::operator==(const Flight& flight) const {
	return this->getFlightId() == flight.getFlightId();
}
/*
name:operator<
parameters:flight to compare
return value:true if small
algorithm:compare between the flight's ids and return if this < flightID
*/
bool Flight::operator<(const Flight& flight) const {
	return this->getFlightId() < flight.getFlightId();
}
/*
name:operator>
parameters:flight to compare
return value:true if greater
algorithm:check if flight is NOT equal AND NOT bigger then this (using De morgan laws)
*/
bool Flight::operator>(const Flight& flight) const {
	return !(*this < flight || *this == flight);
}
