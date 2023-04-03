#include "functions.h"
#include <sstream>
#include <iomanip>

//Get information about a new person
Person getPerson()
{
	Person person;

	std::cout << "Enter Enter the person's name and date of birth (YYYY/MM/DD): ";
	std::string input;
	std::getline(std::cin, input);

	std::istringstream iss(input);
	iss >> person.name;

	std::string dateStr;
	iss >> dateStr;

	std::tm t = { };
	std::istringstream dateStream(dateStr);
	dateStream >> std::get_time(&t, "%Y/%m/%d");

	if (dateStream.fail())
	{
		throw std::invalid_argument("Error! Invalid date format");
	}

	person.birthday = t;

	return person;
}

//*******************************************************************************

//Print information about a person
void printInfoAboutPerson(const Person& person) noexcept
{
	std::time_t t = std::time(nullptr);
	std::tm currentDate = *std::localtime(&t);
	std::tm birthday = person.birthday;
	std::time_t currentTime = std::mktime(&currentDate);

	int64_t age = currentDate.tm_year - birthday.tm_year;
	birthday.tm_year = currentDate.tm_year;
	std::time_t birthTime = std::mktime(&birthday);
	

	double daysSinceBirth = std::difftime(currentTime, birthTime) / (24. * 60. * 60);

	

	if (currentDate.tm_mon < birthday.tm_mon || (currentDate.tm_mon == birthday.tm_mon && currentDate.tm_mday < birthday.tm_mday))
	{
		int64_t days = -daysSinceBirth;
		std::cout << person.name << "'s birthday will be in " << days << " days and he/she will be " << age << " years old\n";
	}
	else if (currentDate.tm_mon == birthday.tm_mon && currentDate.tm_mday == birthday.tm_mday)
	{
		std::cout << person.name << " has birthday TODAY  and he/she is " << age << " years old\n";
	}
	else
	{
		int64_t days = daysSinceBirth;
		std::cout << person.name << "'s birthday was " << days << " days ago and he/she turned " << age << " years old\n";
	}
}