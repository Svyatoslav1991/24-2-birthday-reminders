#pragma once

#include <iostream>

#include "person.h"


//Get information about a new person
Person getPerson();

//Print information about a person
void printInfoAboutPerson(const Person& person) noexcept;