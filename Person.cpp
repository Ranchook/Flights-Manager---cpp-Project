#include "Person.h"

const int Person::num_of_role = NONE;

void Person::idCheck(const char *id)
{
	int i=0;
	if(*id == '\0')
		throw "ID is empty!";
	while (id[i] >= '0'&& id[i] <= '9')
		i++;
	if(i != strlen(id))
		throw "ID is incorrect!";
}

void Person::nameCheck(const char *fullName)
{
	int i = 0;
	if (*fullName == '\0')
		throw "Name is empty!";
	while ((fullName[i] >= 'a'&& fullName[i] <= 'z') || (fullName[i] >= 'A'&& fullName[i] <= 'Z'))
		i++;
	if (i != strlen(fullName))
		throw "Name is incorrect!";
}


bool Person::roleCheck(Role Prole) const
{
	for (int i = 0; i < num_of_role; i++)
	if (Prole == i)
			return true;
	throw "No valid role!";
}

/*
name:Person
parameters:id, fullName
return value:this object
algorithm:call setters
*/
Person::Person(const char* id,const char* fullName, Role role)
{
	setId(id);
	setFullName(fullName);
	setRole(role);
}
/*
name:Person
parameters:role
return value:this object
algorithm:Enter ID number and name per person and call setter for fole 
*/
Person::Person(Role role)
{
	char tmpId[9], tmpName[100];
	cout << "enter id: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(tmpId, 9);
	setId(tmpId);
	cout << "enter full name: ";
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(tmpName, 100);
	setFullName(tmpName);
	setRole(role);
}
/*
name:Person
parameters:p
return value:this object
algorithm:Enter NULL in dynamic values and run operator =
*/
Person::Person(const Person& p)
{
	this->id = NULL;
	this->fullName =NULL;
	*this = p;
}

void Person::setRole(const Role& role) 
{
	try {
		this->role = role;
		roleCheck(role);
	}
	catch(const char* emsg)
	{cout << emsg << endl;}

}
/*
name:setId
parameters:id
return value:none
algorithm:check if is valid (only numbers)
if ok set data
else throw INVALID_ID
*/
void Person::setId(const char* id)
{
	char tmpId[9];
	int flag = 1;
	while (flag)
	{
		try {
			this->id = _strdup(id);
			idCheck(id);
			flag = 0;
		}
		catch (const char* emsg)
		{
			cout << emsg << endl;
			cout << "please re-enter id: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(tmpId, 9);
			setId(tmpId);
		}
		return;
	}
}
/*
name:setFullName
parameters:full name
return value:none
algorithm:check if is valid
if ok set data
else throw INVALID_NAME
*/
void Person::setFullName(const char* fullName)
{
	char tmpName[100];
	int flag = 1;
	while (flag)
	{
		try {
			this->fullName = _strdup(fullName);
			nameCheck(fullName);
			flag = 0;
		}
		catch (const char* emsg)
		{
			cout << emsg << endl;
			cout << "please re-enter name: ";
			cin.ignore(cin.rdbuf()->in_avail());
			cin.getline(tmpName, 100);
			setFullName(tmpName);
		}
		return;
	}
}

/*
name:operator==
parameters: peson to compare
return value:true if equal
algorithm:compare between the person's ids
*/
bool Person::operator==(const Person& person) const
{
	return strcmp(this->id,person.id)==0;
}
/*
name:operator<
parameters:person to compare
return value:true if small
algorithm:compare between the person's ids and return if this < id
*/
bool Person::operator<(const Person& person) const
{
	return strcmp(this->id, person.id)<0;
}
/*
name:operator>
parameters:person to compare
return value:true if greater
algorithm:check if person is NOT equal AND NOT bigger then this (using De morgan laws)
*/
bool Person::operator>(const Person& person) const
{
	return !(*this<person || *this==person);
}
/*
name:operator>
parameters:person to compare
return value:true if greater
algorithm:check if person is NOT bigger then this
*/
bool Person::operator>=(const Person& person) const
{
	return !(*this<person);
}

const Person& Person::operator=(const Person& p)
{
	if (this != &p) 
	{
		this->id = _strdup(p.id);
		this->fullName = _strdup(p.fullName);
		this->role = p.role;
	}
	return *this;
}

Person::~Person()
{
	delete[] id;
	delete[] fullName;
}
/*
name:operator<<
parameters:output stream, person to display,
return value:output stream for continous
algorithm: display the person
*/
ostream& operator<<(ostream& out, const Person& p)
{
	out << left << setw(12) << setfill(' ') << "";
	out << left << setw(12) << setfill(' ') << p.id << " ";
	out << left << setw(12) << setfill(' ') << p.fullName << " ";
	out << left << setw(12) << setfill(' ') << p.role << " ";
	out << left << setw(93) << setfill(' ') << "" << endl << endl;
	return out;
}


