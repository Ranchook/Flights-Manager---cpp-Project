#pragma once
#include <iostream>
using namespace std;
#include <iomanip>
#include <string>
#include <exception>

typedef enum Role { PASSENGER, PILOT, BARTENDER, STEWARDESS, NONE }Role;

class Person
{
	char* id;
	char* fullName;
	Role role;
	const static int num_of_role;//Maximum number of roles
public:

	void idCheck(const char*);
	void nameCheck(const char*);
	bool roleCheck(Role) const;

	Person(const char* ,const char* ,Role role = Role::PASSENGER);
	Person(Role role = Role::PASSENGER);
	Person(const Person&);
	//return role
	Role getRole() const { return role; }
	//return id
	char* getId() const {return id;}
	//return full name
	char* getFullName() const { return fullName; }
	//set role
	void setRole(const Role& role);
	//set id
	void setId(const char* );
	//set full name
	void setFullName(const char*);
	//compare this == person
	bool operator==(const Person& ) const;
	//compare this < person
	bool operator<(const Person& ) const;
	//compare this > person
	bool operator>(const Person& ) const;
	//compare this >= person
	bool operator>=(const Person& ) const;
	
	//display person
	friend ostream& operator<< (ostream& , const Person& );
	
	const Person& operator=(const Person&);

	~Person();
};

