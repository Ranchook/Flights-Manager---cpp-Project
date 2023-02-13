#include "First.h"

First::First(const Person &p, int cap, int price, bool chair, bool ent) : Capsule(cap, price)
{
	//constructor, using also capsule constructor
	setEntr(ent);
	setRecliner(chair);
	setBart(p);
}

// is seat reclining
bool First::getRecliner()
{
	return reclinerChair;
}

// is there any entertainment
bool First::getEntr()
{
	return entertainment;
}

// setting recliner data
void First::setRecliner(bool chair)
{
	reclinerChair = chair;
}

// setting entertainment data
void First::setEntr(bool ent)
{
	entertainment = ent;
}

// bartender data using class Person
Person * First::getBart()
{
	return bart;
}

// setting bartender data
void First::setBart(const Person p)
{
	try{
		if (p.roleCheck(BARTENDER))
			bart = new Person(p.getId(), p.getFullName(), p.getRole());
	}
	catch (const char* emsg)
	{cout << "Bartender required!" << endl;}
}

// print operator
ostream & operator<<(ostream & out, const First & f)
{
	try {
		if(f.isEmpty())
			throw "First class is Empty!";
		Capsule fir = f; // casting to print capsule data
		
		out << "First class data: " << endl;
		
		if(f.reclinerChair)
		out << "Are seats reclining? yes" << endl;
		else 
			out << "Are seats reclining? no" << endl;
		
		if(f.entertainment)
		out << "Is there entertainment? yes" << endl;
		else
			out << "Is there entertainment? no" << endl;
		
		out << "The bartender is: " << *f.bart << endl;
		//printing using << operator of class capsule
		out << fir;
		//fir is deleted in the end of block using destructor
	}

	catch (const char* eMsg)
	{cout << eMsg << endl;}
}
