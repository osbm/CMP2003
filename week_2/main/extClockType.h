
#ifndef H_ExtClockType
#define H_ExtClockType

#include "clockType.h"

enum zoneType { EST, CST, MST, PST, EDT, CDT, MDT, PDT };

class extClockType : public clockType
{
public:
	void setTime(int hours, int minutes, int seconds, zoneType tZone);
	void printTime() const;

	extClockType(int = 0, int = 0, int = 0, zoneType = EST);

private:
	zoneType timeZone;
};

#endif
#pragma once
