# Flights Manager---cpp-Project

The 4th class project. A program that manages flights data and flight tickets.
The project showcases the use of overloading operators using a frend method, exceptions, casting and inheritance.

Every flight has two capsules in the plane: first capsule and a regualr capsule. 
In addition to those two capsules each flight has different flight data such as flightId, destination, times of arrival and departure crew information and more.

Each capsule has information about the ticket price, an array AirlineTickets (pointers to AirlineTicket object), maxium capacity and the actual number of tickets

The first capsule has all the fields that the regular capsule have and also some additional unique fields.
Those fields are: is the seat reclining, is there entertainment, and a bartender (pointer to a Person object).
