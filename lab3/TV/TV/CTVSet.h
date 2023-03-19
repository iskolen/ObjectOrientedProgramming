#pragma once

class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	bool SelectChannel(int channel);
	bool IsTurnedOn()const;
	int GetChannel()const;

private:
	bool m_isOn = false;
	int m_selectedChannel = 1;
};
