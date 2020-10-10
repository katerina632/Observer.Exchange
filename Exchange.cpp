#include "Exchange.h"

void Exchange::AddCurrency(Currency* crypt)
{
	currencies.push_back(crypt);
}

void Exchange::Attach(Bidder* b)
{
	bidders.push_back(b);
}

void Exchange::ChangeCourses()
{
	bool isChange;

	int changeCourse = 0;
	int xTime = 5;	
	double sumChangeCourse = 0, averageChanges = 0;


	for (auto it = currencies.begin(); it != currencies.end(); it++)
	{
		for (int i = 0; i < xTime; i++)
		{
			changeCourse = -10 + rand() % 21;

			(*it)->SetCourse(changeCourse);
			sumChangeCourse += changeCourse;
		}

		averageChanges = sumChangeCourse / xTime;

		if (averageChanges < 0)
		{
			cout << "Downward trend." << endl;
			isChange = false;
			Notify((*it), isChange);
		}
		else
		{
			cout << "Tendency to increase the rate." << endl;
			isChange = true;
			Notify((*it), isChange);
		}

		cout << "Waiting..." << endl;
		Sleep(1000);
		cout << endl;
	}
}

void Exchange::Detach(Bidder* pBidder)
{
	for (auto it = bidders.begin(); it != bidders.end(); it++)
	{
		if (*it == pBidder)
		{
			bidders.erase(it);
			return;
		}
	}
}

void Exchange::Notify(Currency* c, bool change)
{
	for (auto it = bidders.begin(); it != bidders.end(); it++)
	{
		if (change == false)
			(*it)->Down(c);
		else
			(*it)->Up(c);

	}
	cout << "\n";
}
