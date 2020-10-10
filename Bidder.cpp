#include "Bidder.h"

Currency* AmericanBidder::GetCurrency() const
{
	return currency;
}

void AmericanBidder::SetCurrency(Currency* pCurrency)
{
	currency = pCurrency;
}

void AmericanBidder::Down(Currency* pCurrency)
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
			cout << "Still waiting..." << endl;
			Sleep(1000);
		}
		int sharesChange = 1 + rand() % abs(money / currency->GetCourse());

		shares += sharesChange;
		money -= shares * currency->GetCourse();
		cout << name << " buy " << shares << " shares by course " << currency->GetCourse() << endl;
	}
}

void AmericanBidder::Up(Currency* pCurrency)
{
	int yTime = 3;

	if (shares > 0)
	{
		for (int i = 0; i < yTime; i++)
		{
			cout << "Still waiting..." << endl;
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

void AmericanBidder::Show() const
{
	cout << "Name: " << name << "\nMoney: " << money << endl;
	if (currency != nullptr)
		cout << shares << " shares of " << currency->GetName() << endl;
}
