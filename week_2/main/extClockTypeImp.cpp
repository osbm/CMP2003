
#include <iostream>
#include <string>
#include "extClockType.h"

using namespace std;

void extClockType::setTime(int hours, int minutes,	int seconds, zoneType tZone)
{
	clockType::setTime(hours, minutes, seconds);
	timeZone = tZone;
}

void extClockType::printTime() const
{
	static string zoneArray[8] = { "EST", "CST", "MST", "PST",
								  "EDT", "CDT", "MDT", "PDT" };

	clockType::printTime();
	cout << " " << zoneArray[timeZone];

}

extClockType::extClockType(int hours, int minutes,
	int seconds, zoneType tZone)
	:clockType(hours, minutes, seconds)
{
	timeZone = tZone;
}

