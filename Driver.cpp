#include <sstream>
#include "Driver.h"

Driver::Driver(unsigned int id, string name, unsigned int maxHours, unsigned int maxWeekWorkingTime, unsigned int minRestTime, vector<Shift> shifts) {
	this->id = id;
	this->name = name;
	this->maxHours = maxHours;
	this->maxWeekWorkingTime = maxWeekWorkingTime;
	this->minRestTime = minRestTime;
	this->shifts = shifts;
}
Driver::Driver(string textLine){

  // INITIALISATION CODE GOES IN HERE
	istringstream driverStream(textLine);

	driverStream >> id;
	driverStream.ignore(1000,';');
	

	getline(driverStream, name, ';');
	name = name.substr(1, name.size());
	name.pop_back();

	driverStream >> maxHours;
	driverStream.ignore(1000, ';');

	driverStream >> maxWeekWorkingTime;
	driverStream.ignore(1000, ';');

	driverStream >> minRestTime;
}

//////////////
// get methods
//////////////

unsigned int Driver::getId() const{
  return id;
}

string Driver::getName() const{
  return name;
}

unsigned int Driver::getShiftMaxDuration() const{
  return maxHours;
}

unsigned int Driver::getMaxWeekWorkingTime() const{
  return maxWeekWorkingTime;
}

unsigned int Driver::getMinRestTime() const{
  return minRestTime;
}

vector<Shift> Driver::getShifts() const{
  return shifts;
}

//////////////
// set methods
//////////////

void Driver::setId(unsigned int id) {
	this->id = id;
}

void Driver::setName(string name) {
	this->name = name;
}

void Driver::setmaxHours(unsigned int maxHours) {
	this->maxHours = maxHours;
}

void Driver::setmaxWeekWorkingTime(unsigned int maxWeekWorkingTime) {
	this->maxWeekWorkingTime = maxWeekWorkingTime;
}

void Driver::setminRestTime(unsigned int minRestTime) {
	this->minRestTime = minRestTime;
}

void Driver::setshifts(vector<Shift> shifts) {
	this->shifts = shifts;
}


//////////////
// create methods
//////////////


void Driver::service(const Shift &s)
{
	shifts.push_back(s);
}