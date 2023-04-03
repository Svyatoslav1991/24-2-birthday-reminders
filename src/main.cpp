#include <iostream>
#include <list>

#include "functions.h"
#include "person.h"

int main()
{
	std::cout << "\tTASK 24.2 BIRTHDAY REMINDERS\n";

	std::list<Person> persons;

	try
	{
		Person p;
		while (true)
		{
			p = getPerson();

			if (p.name == "end")
			{
				break;
			}
			else
			{
				persons.push_back(p);
			}
		}

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

		if (persons.empty())
		{
			std::cout << "No information\n";
		}
		else
		{
			for (const auto& p : persons)
			{
				printInfoAboutPerson(p);
			}
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
