#pragma once

#include <iostream>
#include <string>
#include <vector>



using namespace std;

class Bus;

class Line{
 private:
  unsigned int id;
  unsigned int frequency;
  vector<string> busStopList;
  vector<int> timesList;
 public:
	Line(unsigned int id, unsigned int frequency, vector<string> busStopList, vector<int> timesList);
  Line(string textLine);
  vector<Line> lineVector;
  // get methods
  unsigned int getId() const;
  unsigned int getFrequency() const;
  vector<string> getBusStops() const;
  vector<int> getTimings() const;

  // set methods

  void setId(unsigned int id);
  void setFrequency(unsigned int frequency);
  void setbusStopList(vector<string> busStopList);
  void settimesList(vector<int> timesList);

  // other methods
  int numberBusLine(vector<int>times, int frequency);

};
