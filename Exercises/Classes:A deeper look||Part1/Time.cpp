#include "Time.h"
#include <iomanip>
#include <iostream>
#include <stdexcept>

Time::Time(int hour, int minute, int second) 
{ 
	setTime(hour, minute, second); 
}
// set new Time value using universal time
void Time::setTime(int h, int m, int s) {
	setHour(h);
	setMinute(m);
	setSecond(s);
}
// set hours
void Time::setHour(int h) {
	if (h >= 0 && h < 24) {
		hour = h;
	}
	else {
		throw std::invalid_argument("hour must be 0-23");
	}
}
// set minutes
void Time::setMinute(int m) {
	if (m >= 0 && m < 60) {
		minute = m;
	}
	else {
		throw std::invalid_argument("minute must be 0-59");
	}
}
// set seconds
void Time::setSecond(int s) {
	if (s >= 0 && s < 60) {
		second = s;
	}
	else {
		throw std::invalid_argument("second must be 0-59");
	}
}
// GETTERS
int Time::getHour() { return hour; }
int Time::getMinute() { return minute; }
int Time::getSecond() { return second; }
// increment time by 1 second
void Time::tick()
{
	if (second != 59) {
		second++;
	}
	else if (second == 59) {
		second = 0;
		if(minute!=59)
			minute++;
		else {
			minute = 0;
			hour = 0;
			second = 0;
		}
	}
		
	}

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() {
	std::cout << std::setfill('0') << std::setw(2) << getHour() << ":"
		<< std::setw(2) << getMinute() << ":" << std::setw(2)
		<< getSecond();
}
// print Time in standard-time format (H:MM:SS AM PM)
void Time::printStandard() {
	std::cout << ((getHour() == 0 || getHour() == 12) ? 12 : getHour() % 12)
		<< ":" << std::setfill('0') << std::setw(2) << getMinute() << ":"
		<< std::setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
}