/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orudek <orudek@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:04:59 by orudek            #+#    #+#             */
/*   Updated: 2023/10/30 13:50:28 by orudek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>


void replace_str(std::string &buffer, std::string word, std::string replacement)
{
	size_t pos;
	size_t offset = 0;
	size_t word_len = word.length();
	size_t rep_len = replacement.length();
	do{
		pos = buffer.find(word, offset);
		if (pos == std::string::npos)
			break;
		buffer.erase(pos, word_len);
		buffer.insert(pos, replacement);
		offset = pos + rep_len;
	}while (1);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout<<"Incorrect number of arguments" << std::endl;
		return (1);
	}
	std::ifstream is;
	std::ofstream os;
	std::string buffer;

	is.open(argv[1]);
	if (!is.is_open())
	{
		std::cout << "Couldn't open input file \"" << argv[1] << "\"" << std::endl;
		return (1);
	}
	os.open((std::string(argv[1]) + std::string(".replace")).c_str());
	if (!os.is_open())
	{
		std::cout << "Couldn't open output file \"" << argv[1] << ".replace\"" << std::endl;
		is.close();
		return (1);
	}
	while(std::getline(is, buffer))
	{
		replace_str(buffer, argv[2], argv[3]);
		os << buffer << std::endl;
	}
	is.close();
	os.close();
	return 0;
}