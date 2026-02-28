/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 13:46:37 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/28 14:29:15 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

void replace_words(std::string &line, const std::string &str_from, const std::string &str_to)
{
	size_t i = 0;
	
	while((i = line.find(str_from, i)) != std::string::npos)
	{
		line.erase(i, str_from.length());
		line.insert(i, str_to);
		i += str_to.length();
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Wrong amount of arguments.\n";
		return (1);
	}
	std::string filename = argv[1];
	std::ifstream input_stream(filename);
	std::ofstream output_stream(filename + ".replace");
	if (!input_stream || !output_stream)
	{
		std::cerr << "Error opening file!\n";
		return (1);
	}
	std::string line;
	while (std::getline(input_stream, line))
	{
		replace_words(line, argv[2], argv[3]);
		output_stream << line << '\n';
	}
	input_stream.close();
	output_stream.close();
}