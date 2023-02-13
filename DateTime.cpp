#include "DateTime.h"
/*
name:DateTime
parameters:year, month, day, hour, minute, second
return value:this object
algorithm: sets data by calling setters
*/
DateTime::DateTime(int year, int month, int day, int hour, int minute, int second) {
	setYear(year);
	setMonth(month);
	setDay(day);
	setHour(hour);
	setMinute(minute);
	setSecond(second);
}
/*
name:DateTime
parameters:year
return value:this object
algorithm: call constructor with default parameters
*/
DateTime::DateTime(int year) : DateTime(year, 1, 1, 1, 0, 0) {

}
/*
name:setYear
parameters:year
return value:none
algorithm:check if data valid
is ok, set year
else throw INVALID_YEAR
*/
void DateTime::setYear(const int& year)throw (const char*) {
	if(year<0)
		throw INVALID_YEAR;

	this->year = year;
}
/*
name:setMonth
parameters:month
return value:none
algorithm:check if data valid
is ok, set month
else throw INVALID_MONTH
*/
void DateTime::setMonth(const int& month)throw (const char*) {
	if (month < 1 || month > 12)
		throw INVALID_MONTH;
	this->month = month;
}
/*
name:setDay
parameters:day
return value:none
algorithm:check if data valid
is ok, set day
else throw INVALID_DAY
*/
void DateTime::setDay(const int& day) throw (const char*) {
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (day < 1 || day > 31)
			throw INVALID_DAY;
		break;
	case 2:
		if (day < 1 || day > 28)
			throw INVALID_DAY;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (day < 1 || day > 30)
			throw INVALID_DAY;
		break;
	default:
		throw INVALID_MONTH;
		break;
	}
	this->day = day;
}
/*
name:setHour
parameters:hour
return value:none
algorithm:check if data valid
is ok, set hour
else throw INVALID_HOUR
*/
void DateTime::setHour(const int& hour) {
	if (hour < 0 || hour > 23)
		throw INVALID_HOUR;

	this->hour = hour;
}
/*
name:setMinute
parameters:minute
return value:none
algorithm:check if data valid
is ok, set minute
else throw INVALID_MINUTE
*/
void DateTime::setMinute(const int& minute) {
	if (minute < 0 || minute > 59)
		throw INVALID_MINUTE;

	this->minute = minute;
}
/*
name:setSecond
parameters:second
return value:none
algorithm:check if data valid
is ok, set second
else throw INVALID_SECOND
*/
void DateTime::setSecond(const int& second) {
	if (second < 0 || second > 59)
		throw INVALID_SECOND;

	this->second = second;
}
/*
name:operator=
parameters:date to copy
return value:this object
algorithm:copt date using setters
*/
const DateTime& DateTime::operator=(const DateTime& date) {
	if (this != &date)
	{
		setYear(date.year);
		setMonth(date.month);
		setDay(date.day);
		setHour(date.hour);
		setMinute(date.minute);
		setSecond(date.second);
	}
	return *this;
}
/*
name:operator==
parameters:data to compare
return value:true if equal
algorithm:compare while date fields and return true if all equal
*/
bool DateTime::operator==(const DateTime& date) const {
	return this->year == date.year &&
		this->month == date.month &&
		this->day == date.day &&
		this->hour == date.hour &&
		this->minute == date.minute &&
		this->second == date.second;
}
/*
name:operator<
parameters:tm object
return value:true if this < tm
algorithm:create temp DateTime object and activate < operators
*/
bool DateTime::operator<(const std::tm& date) const {
	return *this < DateTime(date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min, date.tm_sec);
}
/*
name:operator>
parameters:tm object
return value:true if this > tm
algorithm:create temp DateTime object and activate > operators
*/
bool DateTime::operator>(const std::tm& date) const {
	return *this > DateTime(date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min, date.tm_sec);
}
/*
name:operator==
parameters:tm object
return value:true if this == tm
algorithm:create temp DateTime object and activate == operators
*/
bool DateTime::operator==(const std::tm& date) const {
	return *this == DateTime(date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min, date.tm_sec);
}
/*
name:operator<=
parameters:tm object
return value:true if this <= tm
algorithm:create temp DateTime object and activate <= operators
*/
bool DateTime::operator<=(const std::tm& date) const {
	return *this <= DateTime(date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min, date.tm_sec);
}
/*
name:operator>=
parameters:tm object
return value:true if this >= tm
algorithm:create temp DateTime object and activate >= operators
*/
bool DateTime::operator>=(const std::tm& date) const {
	return *this >= DateTime(date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min, date.tm_sec);
}

/*
name:operator<
parameters:date to comapare
return value:bool
algorithm:check if this date is smaller then given date
*/
bool DateTime::operator<(const DateTime& date) const {
	return this->year < date.year ||
		(this->year == date.year && this->month < date.month) ||
		(this->year == date.year && this->month == date.month && this->day < date.day) ||
		(this->year == date.year && this->month == date.month && this->day == date.day && this->hour < date.hour) ||
		(this->year == date.year && this->month == date.month && this->day == date.day && this->hour == date.hour && this->minute < date.minute) ||
		(this->year == date.year && this->month == date.month && this->day == date.day && this->hour == date.hour && this->minute == date.minute && this->second < date.second);
}
/*
name:operator<=
parameters:date to comapare
return value:bool
algorithm:activate or between ==operator and < operator
*/
bool DateTime::operator<=(const DateTime& date) const {
	return *this == date || *this < date;
}
/*
name:operator>
parameters:date to comapare
return value:bool
algorithm:activate ! on <= operator
*/
bool DateTime::operator>(const DateTime& date) const {
	return !(*this <= date);
}
/*
name:operator>
parameters:date to comapare
return value:bool
algorithm:activate ==operator and  > operator
*/
bool DateTime::operator>=(const DateTime& date) const {
	return *this == date || *this > date;
}
/*
name:to_string
parameters:none
return value:return string format
algorithm:use ostringstream to format date and return the string format
*/
string DateTime::to_string() const {
	std::ostringstream ss;
	ss << right << setw(2) << setfill('0') << day << "/";
	ss << right << setw(2) << setfill('0') << month << "/";
	ss << year << " ";
	ss << right << setw(2) << setfill('0') << hour << ":";
	ss << right << setw(2) << setfill('0') << minute << ":";
	ss << right << setw(2) << setfill('0') << second;
	return  ss.str();
}
/*
name:operator<<
parameters:output stream
return value: output stream for continous
algorithm:call to_string method
*/
ostream& operator<<(ostream& out, const DateTime& date) {
	out << date.to_string();
	return out;
}
