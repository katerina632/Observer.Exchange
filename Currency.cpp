#include "Currency.h"

string Currency::GetName() const
{
	return name;
}

void Currency::SetCourse(int value)
{
	course += value;
}

int Currency::GetCourse() const
{
	return course;
}

void Currency::ShowCourse() const
{
	cout << "\nCryptocurrency: " << name << "\nCourse: " << course << endl;
}
