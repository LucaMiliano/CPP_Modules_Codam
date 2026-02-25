/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:49:48 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/25 18:46:51 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	oldestContact = 0;
	contactCount = 0;
}

void PhoneBook::addContact()
{
	Contact newContact;
	
	auto getValidInput = [](const std::string &prompt) -> std::string
	{
		std::string input;
		while(1)
		{
			std::cout << prompt;
			if (!std::getline(std::cin, input) || input.empty())
				std::cout << "Cannot be empty, try again.\n";
			else
				return (input);
		}
	};

	auto getValidPhone = []() -> std::string
	{
		std::string phone_number;
		while(1)
		{
			std::cout << "Enter phone number: ";
			if (!std::getline(std::cin, phone_number) || phone_number.empty())
				std::cout << "Cannot be empty, try again.\n";
			else if (!std::all_of(phone_number.begin(), phone_number.end(), ::isdigit))
				std::cout << "Phone number can have digits only, try again.\n";
			else
				return (phone_number);
		}
	};
	
	newContact.firstName = getValidInput("Enter first name: ");
	newContact.lastName = getValidInput("Enter last name: ");
	newContact.nickName = getValidInput("Enter nickname: ");
	newContact.phoneNumber = getValidPhone();
	newContact.darkestSecret = getValidInput("Enter darkest secret: ");

	if (contactCount < 8)
	{
		contacts[contactCount] = newContact;
		contactCount++;	
	}
	else
	{
		contacts[oldestContact] = newContact;
		oldestContact = (oldestContact + 1) % 8; 
	}
	std::cout << "Contact added succesfully!\n";
}
std::string truncateString(const std::string &str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
void PhoneBook::showContactList()
{
	std::cout << std::setw(10) << "Index" << "|"
	<< std::setw(10) << "First Name" << "|"
	<< std::setw(10) << "Last Name" << "|"
	<< std::setw(10) << "Nickname" << "\n";
	std::cout << std::string(44, '-') << "\n";

	for (int i = 0; i < contactCount; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|"
		<< std::setw(10) << truncateString(contacts[i].firstName) << "|"
		<< std::setw(10) << truncateString(contacts[i].lastName) << "|"
		<< std::setw(10) << truncateString(contacts[i].nickName) << "\n";
	}
}

void PhoneBook::searchContact()
{
	showContactList();

	std::string index_input;
	int index = -1;
	while (1)
	{
		if (!std::getline(std::cin, index_input))
		{
			std::cout << "Exiting program, goodbye!\n";
			break ;
		}
		std::cout << "Enter the index of contact to display:\n";
		if (!std::getline(std::cin, index_input) || index_input.empty())
		{
			std::cout << "Invalid index. Try between 1 and " << contactCount << ".\n";
			showContactList();
		}
		else if (!std::all_of(index_input.begin(), index_input.end(), ::isdigit))
		{
			std::cout << "Invalid index. Try between 1 and " << contactCount << ".\n";
			showContactList();
		}
		else
		{
			index = std::stoi(index_input) - 1;
			break;	
		}
	}
	if (index < 0 || index >= contactCount)
	{
		std::cout << "Invalid index. Try between 1 and " << contactCount << ".\n";
		PhoneBook::searchContact();
	}
	else
	{
	std::cout << "First Name: " << contacts[index].firstName << "\n";
	std::cout << "Last Name: " << contacts[index].lastName << "\n";
	std::cout << "Nickname: " << contacts[index].nickName << "\n";
	std::cout << "Phone Number: " << contacts[index].phoneNumber << "\n";
	std::cout << "Darkest Secret: " << contacts[index].darkestSecret << "\n";
	}
}

int main(void)
{
	std::cout << "Welcome to your Phonebook!\n";
	std::cout << "You can add a new contact through the ADD command,\n";
	std::cout << "search contacts through the SEARCH command,\n";
	std::cout << "or exit the program through the EXIT command.\n";

	std::string command;
	PhoneBook phonebook;

	while(1)
	{
		std::cout << "What do you want to do?\n";
		if (!std::getline(std::cin, command))
		{
			std::cout << "Exiting program, goodbye!\n";
			break ;
		}
		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
		{
			if (phonebook.contactCount >= 1)
				phonebook.searchContact();
			else
				std::cout << "No contacts available.\n";
		}
		else if (command == "EXIT")
		{
			std::cout << "Exiting program, goodbye!\n";
			break ;
		}
		else
			continue;
	}
}
