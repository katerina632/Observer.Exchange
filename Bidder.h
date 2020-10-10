#pragma once
#include<iostream>
#include<Windows.h>
#include "Currency.h"
using namespace std;

class Bidder
{
public:
	virtual void Up(Currency*) = 0;
	virtual void Down(Currency*) = 0;
};

class AmericanBidder : public Bidder
{
private:
	Currency* currency;
	string name;
	int money;
	int shares;
public:
	AmericanBidder(string name, int shares, int money = 100000) : name(name), shares(shares), money(money) {}

	Currency* GetCurrency() const;
	
	void SetCurrency(Currency* pCurrency);
	
	void Down(Currency* pCurrency);	

	void Up(Currency* pCurrency);	

	void Show() const;


};
