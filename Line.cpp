#include <sstream>
#include "Line.h"


Line::Line(unsigned int id, unsigned int frequency, vector<string> busStopList, vector<int> timesList) {
	this->id = id;
	this->frequency = frequency;
	this->busStopList = busStopList;
	this->timesList = timesList;
}
Line::Line(string textLine){

  // INITIALISATION CODE GOES IN HERE
	
	istringstream lineStream(textLine);
	string listOfStops;
	string stop;
	string listOfTimes;
	string time;

	lineStream >> id;
	lineStream.ignore(1000, ';');

	lineStream >> frequency;
	lineStream.ignore(1000, ';');

	getline(lineStream, listOfStops, ';');
	istringstream stopStream(listOfStops);
	while(getline(stopStream,stop,','))
	{
		stop = stop.substr(1, stop.size());
		busStopList.push_back(stop);

	}
	getline(lineStream, listOfTimes);
	istringstream timeStream(listOfTimes);
	while (getline(timeStream,time, ','))
	{
		int time1 = stoi(time);
		timesList.push_back(time1);
	}

}

////////////////
// get methods
////////////////

unsigned int Line::getId() const{
  return id;
}

unsigned int Line::getFrequency() const {
	return frequency;
}

vector<string> Line::getBusStops() const{
  return busStopList;
}

vector<int> Line::getTimings() const{
  return timesList;
}

////////////////
// set methods
////////////////

void Line::setId(unsigned int id) {
	this->id = id;
}

void Line::setFrequency(unsigned int frequency) {
	this->frequency = frequency;
}

void Line::setbusStopList(vector<string> busStopList) {
	this->busStopList = busStopList;
}

void Line::settimesList(vector<int> timesList) {
	this->timesList = timesList;
}

int Line::numberBusLine(vector <int> times, int frequency) {
	int total = 0;
	for (int i = 0; i < times.size(); i++) {
		total +=times.at(i);
	}
	total = total / frequency;
	total++;
	return total;
}