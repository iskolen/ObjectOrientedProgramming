#include "CController.h"

const std::string INCORRECT_COMMAND = "Неверная команда!";

int main()
{
	setlocale(LC_ALL, RUSSIAN_LANGUAGE);
	std::vector<std::shared_ptr<CBody>> bodies;
	CController controller(std::cin, std::cout, bodies);
	std::cout << START_MESSAGE;

	while (!std::cin.eof() && !std::cin.fail())
	{
		if (!controller.HandleCommand())
		{
			std::cout << INCORRECT_COMMAND << std::endl;
		}
	}
	return 0;
}