#include <sstream>
#include "Bus.h"


Bus::Bus(unsigned int id, unsigned int line,vector<Shift>schedule){
	this->orderInLine = id;
	this->lineId = line;
	this->schedule = schedule;

// INITIALISATION CODE GOES IN HERE
  
}


////////////////////////////////
// get methods
///////////////////////////////
unsigned int Bus::getBusOrderInLine()const {
  return orderInLine;
}

unsigned int Bus::getLineId() const {
  return lineId;
}

vector<Shift> Bus::getSchedule()const {
  return schedule;
}


//////////////////////////////
// metodos set
/////////////////////////////
void Bus::setLineId(unsigned int lineId)
{
	this->lineId = lineId;
}
void Bus::setorderInLine(unsigned int orderInLine)
{
	this->orderInLine = orderInLine;
}
void Bus::setSchedule(vector<Shift> schedule)
{
	this->schedule = schedule;
}
////////////////////////////
// other methods
///////////////////////////
void Bus::serviceB(const Shift S)
{
	schedule.push_back(S);
}