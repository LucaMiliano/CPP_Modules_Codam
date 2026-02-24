/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:50:54 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/24 18:46:09 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK
#define PHONEBOOK
#include <iostream>
#include <string>

class PhoneBook
{
	private:
		Contact contacts[8];
		int oldestContact;
		int contactCount;

	public:
		PhoneBook();
		void addContact(Contact info);
		void searchContact();
};

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
};

#endif