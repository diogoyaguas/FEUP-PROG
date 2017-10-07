#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Shift.h"


using namespace std;

class Driver{
 private:
  unsigned int id;
  string name;
  unsigned int maxHours;        // maximum duration of a shift
  unsigned int maxWeekWorkingTime;  // maximum number of hours of work in a week
  unsigned int minRestTime;     // minimum number of rest hours between shifts
  vector<Shift> shifts;         // assigned shifts
 public:
  Driver(string textLine);
  Driver(unsigned int id,string name, unsigned int maxHours, unsigned int maxWeekWorkingTime, unsigned int minRestTime, vector<Shift> shifts);
  
  // get methods
  unsigned int getId() const;
  string getName() const;
  unsigned int getShiftMaxDuration() const;
  unsigned int getMaxWeekWorkingTime() const;
  unsigned int getMinRestTime() const;
  vector<Shift> getShifts() const;

  // set methods

  void setId(unsigned int id);
  void setName(string name);
  void setmaxHours(unsigned int maxHours);
  void setmaxWeekWorkingTime(unsigned int maxWeekWorkingTime);
  void setminRestTime(unsigned int minRestTime);
  void setshifts(vector<Shift> shifts);



  // outher methods
  void service(const Shift &s);
};
