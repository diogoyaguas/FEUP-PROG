#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Line.h"
#include "Driver.h"
#include "Bus.h"
#include "Shift.h"


using namespace std;

class Bus;
class Shift;

class Company{
 private:
  string name;
  string fileDrivers;
  string fileLines;
 
 public:
	 Company(string name, string filedrivers, string filelines);
	 vector<Driver> drivers;
	 vector<Line> lines;
	 vector<Bus> bus;
  // get methods
  string getCompanyName() const;
  vector<Driver> getCompanyDrivers() const;
  vector<Line> getCompanyLines() const;
	

  void setupDrivers();
  void setupLines();
  // set methods
  void setCompanyName(string name);
  void setCompanyDrivers(vector<Driver> drivers);
  void setCompanyLines(vector<Line>lines);
  // other methods
  
  void failC(int n);
  void clearScreenC();
  
  void saveDriver();
  
  void viewLine();
  void viewDriver();
  
  void changeDriver();

  void deleteDriver();

  void createDriver();
  
  void showScheduleLine();
  void showScheduleStop();
  int SizeStop(int i, int j);
  int SizeHours(int i, int j);
  void showLineswithxStop();
  void routeBetweenStops();
  bool findStop(string stop);
  void showWorkDriver();
  void showBus();
  void showTimeswithoutDriver();
  void showDriverWithoutService();
  void ServiceDistribution();
  int NumberOfBus(int id);
  void busAux();

};
