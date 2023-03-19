﻿#include <iostream>
#include <string>
#include "CTVSet.h"

const char RUSSIAN_LANGUAGE[8] = "Russian";

const std::string COMMAND_TURN_ON = "TurnOn";
const std::string COMMAND_TURN_OFF = "TurnOff";
const std::string COMMAND_SELECT_CHANNEL = "SelectChannel";
const std::string COMMAND_INFO = "Info";
const std::string ERROR_INVALID_COMMAND = "Invalid command";
const std::string ERROR_INVALID_CHANNEL = "Invalid channel";
const std::string TV_ON = "TV is on";
const std::string TV_OFF = "TV is off";
const std::string CHANNEL_SWITCHED = "Channel switched to ";
const std::string CURRENT_CHANNEL = "Current channel is ";

void PrintStartMessage()
{
	std::cout << "TurnOn - Включает телевизор, если он был выключен.\n"
		<< "TurnOff - Выключает телевизор, если он был включен.\n"
		<< "SelectChannel <номер канала> - Выбирает указанный номер канала.\n"
		<< "Info - Выводит текущее состояние телевизора (выключен или включен, номер канала).\n\n";
}

int main()
{
	setlocale(LC_ALL, RUSSIAN_LANGUAGE);
	PrintStartMessage();

	CTVSet tv;
	std::string command;

	while (std::cin >> command)
	{
		if (command == COMMAND_TURN_ON)
		{			
			tv.TurnOn();
		}
		else if (command == COMMAND_TURN_OFF)
		{
			tv.TurnOff();
		}
		else if (command == COMMAND_SELECT_CHANNEL)
		{
			int channel;
			std::cin >> channel;
			if (tv.SelectChannel(channel))
			{
				std::cout << CHANNEL_SWITCHED << channel << std::endl;
			}
			else if (tv.IsTurnedOn() == 0)
			{
				std::cout << TV_OFF << std::endl;
			}
			else
			{
				std::cout << ERROR_INVALID_CHANNEL << std::endl;
			}
		}
		else if (command == COMMAND_INFO)
		{
			std::cout << (tv.IsTurnedOn() ? TV_ON : TV_OFF) << std::endl;
			std::cout << CURRENT_CHANNEL << tv.GetChannel() << std::endl;
		}
		else
		{
			std::cout << ERROR_INVALID_COMMAND << std::endl;
		}
	}

	return 0;
}