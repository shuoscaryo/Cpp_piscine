#pragma once
#include <iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain & src);
		~Brain(void);
		Brain & operator=(const Brain & rhs);
		std::string getIdea(size_t index) const;
		void addIdea(const std::string &idea);
		size_t getNumberOfIdeas(void) const;
	protected:
	private:
		size_t NumberOfIdeas;
		std::string ideas[100];
};
