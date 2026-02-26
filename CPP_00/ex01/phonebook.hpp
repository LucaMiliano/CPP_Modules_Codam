/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:50:54 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/26 13:34:47 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK
#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	public:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
		Contact()
		{
			firstName = "";
			lastName = "";
			nickName = "";
			phoneNumber = "";
			darkestSecret = "";
		};
};

class PhoneBook
{
	private:
		int oldestContact;
		
	public:
		PhoneBook();
		int contactCount;
		Contact contacts[8];
		void addContact();
		void searchContact();
		void showContactList();
};

#endif