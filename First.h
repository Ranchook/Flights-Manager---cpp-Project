#pragma once
#include "Person.h"
#include "Capsule.h"

class First: public Capsule 
// class first is a derivative of class capsule
{
	bool reclinerChair; 
	bool entertainment;
	Person * bart;

public:
	//constructor
	First(const Person&, int price, int cap, bool chair, bool ent);
	bool getRecliner(); // is seat reclining
	bool getEntr(); // is there any entertainment
	void setRecliner(bool); // setting recliner data
	void setEntr(bool); // setting entertainment data
	Person* getBart(); // bartender data using class Person
	void setBart(const Person); // setting bartender data
	friend ostream& operator<<(ostream& out, const First& f); // print operator
};

