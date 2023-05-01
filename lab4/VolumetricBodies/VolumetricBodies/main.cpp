#include "CController.h"

int main()
{
	setlocale(LC_ALL, RUSSIAN_LANGUAGE);
	std::vector<std::shared_ptr<CBody>> bodies;
	CController control(std::cin, std::cout);
	control.PrintStartMessage();

	int command = 0;
	while (true)
	{
		std::cout << MESSAGE_NUMBER_COMMAND;
		std::cin >> command;
		switch (command)
		{
		case COMMAND_ADD_BODY:
			control.AddBody(bodies);
			std::cout << LINE_BREAK;
			break;
		case COMMAND_FIND_MAX_MASS_BODY:
			control.FindMaxMassBody(bodies);
			std::cout << LINE_BREAK;
			break;
		case COMMAND_FIND_LIGHTEST_BODY_IN_WATER:
			control.FindLightestBodyInWater(bodies);
			std::cout << LINE_BREAK;
			break;
		case COMMAND_GET_INFO_ABOUT_ALL_BODIES:
			control.GetInfoAboutAllBodies(bodies);
			std::cout << LINE_BREAK;
			break;
		case COMMAND_EXIT_COMMAND:
			control.GetInfoAboutAllBodies(bodies);
			std::cout << MESSAGE_EXIT_PROGRAM;
			return 0;
			break;
		default:
			std::cout << MESSAGE_INCORRECT_COMMAND;
			break;
		}
	}
	return 0;
}