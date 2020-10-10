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

	string GetName() const;	

	void SetCourse(int value);

	int GetCourse() const;	

	void ShowCourse() const;
	


};

