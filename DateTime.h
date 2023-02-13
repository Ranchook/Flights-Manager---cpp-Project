#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>
using namespace std;
#define INVALID_YEAR "Invalid Year"
#define INVALID_MONTH "Invalid Month"
#define INVALID_DAY "Invalid Day"
#define INVALID_HOUR "Invalid Hour"
#define INVALID_MINUTE "Invalid Minute"
#define INVALID_SECOND "Invalid Second"
#define INVALID_TIME_DIFF "Illegal time differences - needs to be today < departure < arrival"

class DateTime
{
	int day;
	int year;
	int hour;
	int month;
	int minute;
	int second;
public:
	DateTime(int year, int month, int day, int hour, int minute, int second = 0);
	DateTime(int year = 0);

	//return day
	int getDay() const { return day; }
	//return hour
	int getHour() const { return hour; }
	//return year
	int getYear() const { return year; }
	//return month
	int getMonth() const { return month; }
	//return minute
	int getMinute() const { return minute; }
	//return second
	int getSecond() const { return second; }

	//set day
	void setDay(const int& day) throw (const char *);
	//set year
	void setYear(const int& year)  throw (const char*);
	//set hour
	void setHour(const int& hour) throw (const char*);
	//set month
	void setMonth(const int& month) throw (const char*);
	//set minute
	void setMinute(const int& minute) throw (const char*);
	//set second
	void setSecond(const int& second) throw (const char*);

	//return true if this < date
	bool operator<(const DateTime& date) const;
	//return true if this > date
	bool operator>(const DateTime& date) const;
	//return true if this == date
	bool operator==(const DateTime& date) const;
	//return true if this <= date
	bool operator<=(const DateTime& date) const;
	//return true if this >= date
	bool operator>=(const DateTime& date) const;
	//return true if this < date
	bool operator<(const std::tm& date) const;
	//return true if this > date
	bool operator>(const std::tm& date) const;
	//return true if this == date
	bool operator==(const std::tm& date) const;
	//return true if this <= date
	bool operator<=(const std::tm& date) const;
	//return true if this >= date
	bool operator>=(const std::tm& date) const;
	//copy data 
	const DateTime& operator=(const DateTime& date);
	//return date string format
	string to_string() const;
	//display data 
	friend ostream& operator<<(ostream& out, const DateTime& date);
	
};