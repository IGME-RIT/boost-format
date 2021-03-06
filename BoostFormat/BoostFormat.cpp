#include <boost/format.hpp>
#include <iostream>
#include <string>

struct animal
{
	std::string name;
	int legs;
};

std::ostream & operator<<(std::ostream &os, const animal &a)
{
	return os << a.name << ", " << a.legs;
}

int main()
{
	std::cout << boost::format{ "%1%.%2%.%3%" } % 31 % 1 % 2018 << std::endl;
	std::cout << boost::format{ "%2%/%1%/%3%" } % 31 % 1 % 2018 << std::endl;

	std::cout << boost::format{ "%1% %2% %1%" } % boost::io::group(std::showpos, 1) % 2 << std::endl;

	std::cout << boost::format{ "%|1$+| %2% %1%" } % 1 % 2 << std::endl;

	try
	{
		std::cout << boost::format{ "%|+| %2% %1%" } % 1 % 2 << std::endl;
	}
	catch (boost::io::format_error &ex)
	{
		std::cout << ex.what() << std::endl;
	}

	std::cout << boost::format{ "%|+| %|| %||" } % 1 % 2 % 1 << std::endl;

	std::cout << boost::format{ "%+d %+d %+d" } % 1 % 2 % 1 << std::endl;

	animal a{ "cat", 4 };
	std::cout << boost::format{ "%1%" } % a << std::endl;
}