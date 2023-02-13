#pragma once
#include "DateTime.h"
#include "First.h"
#include"Person.h"
#include "Capsule.h"

#define INVALID_DEPARTURE "Invalid departure date"
#define INVALID_ARRIVAL "Invalid arrival date"
#define INVALID_DESTINATION "Invalid Destination"
#define INVALID_FLIGHTID "Invalid Flight ID"
#define CREW_EXIST "Crew member exists"
#define CREW_NOT_EXIST "Crew member does not exist"
#define CREW_FULL "crew is full!"



class Flight
{
	int flightId;
	static int counter;//For a unique flightId
	bool coronaFree;
	DateTime arrival;
	DateTime departure;
	char* destination;
	Person** crew;
	int maxCrew;
	int currentCrew;
	First classFirst;
	Capsule classRegular;

	//private: check if pilot and stewardess exists
	//bool hasPilotAndStewardess() const;
	//private: set flight id
	void setFlightId(const int& flightID);

public:
	Flight(const Capsule& classRegular,const First& classFirst,int maxCrew=0,const char* destination = "NA",DateTime departure = 0, DateTime arrival = 0, bool coronaFree = true);
	//Flight(Flight& f);

	~Flight();

	//return flightid
	int getFlightId() const { return flightId; }
	//return crew
	Person** getCrew() const { return crew; }
	//return arrival
	DateTime getArrival() const { return arrival; }
	//return corona free
	bool getCoronaFree() const { return coronaFree; }
	//return departure
	DateTime getDeparture() const { return departure; }
	//return destination
	string getDestination() const { return destination; }
	//return capsule class regular
	const Capsule getCapsuleClassRegular() const { return classRegular; }
	//return capsule first class
	const First getCapsuleFirstClass() const { return classFirst; }
	//set coronafree
	void setCoronaFree(const bool& isCoronaFree);
	//set arrival
	void setArrival(const DateTime& arrival)  throw (const char*);
	//set departure
	void setDeparture(const DateTime& departure) throw (const char*);
	//set destination
	void setDestination(const char* destination)throw (const char*);

	//add person
	const Flight& operator+=(Person& person) throw (const char*);	//for crew addition
	//remove person
	const Flight& operator-=(Person& person) throw (const char*);//for crew removal
	//compare this > flight
	bool operator>(const Flight& flight) const;
	//compare this < flight
	bool operator< (const Flight& flight) const;
	//compare this == flight
	bool operator== (const Flight& flight) const;//compare between tickets
	//display flight
	friend ostream& operator<<(ostream& out, const Flight& f);

	
};
