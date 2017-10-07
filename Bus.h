#pragma once

#include <iostream>
#include <vector>
#include "Shift.h"

using namespace std;

class Bus{
 private:
  unsigned int orderInLine;
  unsigned int lineId;
  vector<Shift> schedule;
 public:
  Bus(unsigned int id, unsigned int line, vector<Shift>schedule);
 
  // get methods
 
  unsigned int getBusOrderInLine() const;
  
  unsigned int getLineId() const;
  vector<Shift> getSchedule()const;
  // set methods
    void setLineId(unsigned int lineId);
	void setorderInLine(unsigned int orderInLine);
	void setSchedule(vector <Shift> schedule);
  // other methods
	void serviceB(const Shift S);
};
