#include "Brain.hpp"

Brain::Brain(void):NumberOfIdeas(0)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain & src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain & Brain::operator=(const Brain & rhs)
{
	if (this != &rhs)
	{
		this->NumberOfIdeas = rhs.NumberOfIdeas;
		for (size_t i = 0; i < this->NumberOfIdeas; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

size_t Brain::getNumberOfIdeas(void) const
{
	return (this->NumberOfIdeas);
}

std::string Brain::getIdea(size_t index) const
{
	if (NumberOfIdeas == 0)
	{
		std::cout << "No ideas yet" << std::endl;
		return ("*completely empty brain*");
	}
	if (index >= NumberOfIdeas)
		return (ideas[NumberOfIdeas - 1]);
	return (ideas[index]);
}

void Brain::addIdea(const std::string &idea)
{
	if (NumberOfIdeas < 100)
		ideas[NumberOfIdeas++] = idea;
	else
		std::cout << "Brain.exe can't brain nothing more" << std::endl;
}