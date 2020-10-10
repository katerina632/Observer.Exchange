#pragma once
#include<iostream>

using namespace std;
class Currency
{
private:
	string name;
	int course;
public:
	Currency() : name("No name"), course(0) {}
	Currency(int c, string  n) : name(n), course(c) {}


	string GetName() const
	{
		return name;
	}

	void SetCourse(int value)
	{
		course += value;
	}

	int GetCourse() const
	{
		return course;
	}

	void ShowCourse() const
	{
		cout << "\nCryptocurrency: " << name << "\nCourse: " << course << endl;
	}


};

