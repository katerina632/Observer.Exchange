#pragma once
#include<iostream>
#include<list>
#include "Bidder.h"

using namespace std;
class Exchange
{
private:
	list<Bidder*> bidders;
	list<Currency*> currencies;

public:
	void AddCurrency(Currency* crypt);
	
	void Attach(Bidder* b);	

	void ChangeCourses();	

	void Detach(Bidder* pBidder);	

	void Notify(Currency* c, bool change);
	
};

