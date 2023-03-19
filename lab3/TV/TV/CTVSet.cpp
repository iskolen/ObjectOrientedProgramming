#include "CTVSet.h"

const int MIN_AVAILABLE_CHANNEL = 1;
const int MAX_AVAILABLE_CHANNEL = 99;

bool CTVSet::IsTurnedOn() const
{
	return m_isOn;
}

void CTVSet::TurnOn()
{
	m_isOn = true;
}

void CTVSet::TurnOff()
{
	m_isOn = false;
}

int CTVSet::GetChannel() const
{
	if (m_isOn)
		return m_selectedChannel;
	else
		return 0;
}

bool CTVSet::SelectChannel(int channel)
{
	bool isAvailableChannel = (channel >= MIN_AVAILABLE_CHANNEL) && (channel <= MAX_AVAILABLE_CHANNEL);
	if (isAvailableChannel && m_isOn)
	{
		m_selectedChannel = channel;
		return true;
	}
	return false;
}