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

	Currency* GetCurrency() const
	{
		return currency;
	}
	void SetCurrency(Currency* pCurrency)
	{
		currency = pCurrency;
	}
	void Down(Currency* pCurrency)
	{
		int yTime = 3;

		if (shares > 0)
		{
			int sharesChange = 1 + rand() % shares;
			shares -= sharesChange;
			money += shares * currency->GetCourse();
			cout << name << " sell " << shares << " shares by course " << currency->GetCourse() << endl;
		}
		else
		{
			for (int i = 0; i < yTime; i++)
			{
				cout << "Waiting..." << endl;
				Sleep(1000);
			}
			int sharesChange = 1 + rand() % abs(money / currency->GetCourse());

			shares += sharesChange;
			money -= shares * currency->GetCourse();
			cout << name << " buy " << shares << " shares by course " << currency->GetCourse() << endl;
		}
	}

	void Up(Currency* pCurrency)
	{
		int yTime = 3;

		if (shares > 0)
		{
			for (int i = 0; i < yTime; i++)
			{
				cout << "Waiting..." << endl;
				Sleep(1000);
			}
			int sharesChange = 1 + rand() % abs(money / currency->GetCourse());

			shares += sharesChange;
			money -= shares * currency->GetCourse();
			cout << name << " buy " << shares << " shares by course " << currency->GetCourse() << endl;
		}
		else
		{
			int sharesChange = 1 + rand() % shares;
			shares -= sharesChange;
			money += shares * currency->GetCourse();
			cout << name << " sell " << shares << " shares by course " << currency->GetCourse() << endl;
		}
	}


	void Show() const {
		cout << "Name: " << name << "\nMoney: " << money << endl;
		if (currency != nullptr)
			cout << shares << " shares of " << currency->GetName() << endl;
	}


};
