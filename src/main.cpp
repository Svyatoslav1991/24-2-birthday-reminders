#include <iostream>
#include <list>

#include "functions.h"
#include "person.h"

int main()
{
	std::cout << "\tTASK 24.2 BIRTHDAY REMINDERS\n";

	std::list<Person> persons;
	int decision;

	try
	{
		do {
			std::cout << "\nEnter 1, to add new users birthday,\n";
			std::cout << "Enter 2, to continue work with programm\n";
			decision = myCin<decltype(decision)>();

			if (decision == 1)
			{
				persons.push_back(getPerson());
			}
			else if (decision != 2)
			{
				std::cout << "You've entered someting wrong, try again\n";
			}

		} while (decision != 2);

		persons.sort([](const Person& p1, const Person& p2) {
			if (p1.birthday.tm_mon < p2.birthday.tm_mon)
			{
				return true;
			}
			else if (p1.birthday.tm_mon > p2.birthday.tm_mon)
			{
				return false;
			}

			return p1.birthday.tm_mday < p2.birthday.tm_mday;
			});

		std::cout << "\n";

		for (const auto& p : persons)
		{
			printInfoAboutPerson(p);
		}

	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << e.what() << "\n";
	}
	catch (...)
	{
		std::cerr << "Something went wrong\n";
	}
	


	return 0;
}
