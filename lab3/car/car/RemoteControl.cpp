#include "RemoteControl.h"
#include <sstream>
#include "Car.h"
#pragma once

using namespace std;
using namespace std::placeholders;

CRemoteControl::CRemoteControl(Car& car, std::istream& input, std::ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		  { ENGINE_ON, [this](istream& strm) {
			   return TurnOnEngine(strm);
		   } },
		  { ENGINE_OFF, bind(&CRemoteControl::TurnOffEngine, this, std::placeholders::_1) },
		  { INFO, bind(&CRemoteControl::Info, this, _1) },
		  { SET_GEAR, bind(&CRemoteControl::SetGear, this, _1) },
		  { SET_SPEED, bind(&CRemoteControl::SetSpeed, this, _1) },
		})
{
}


bool CRemoteControl::HandleCommand()
{
	while (!m_input.eof() && !m_input.fail())
	{
		if (!HandleCommand())
		{
			m_output << ERROR_COMMAND << endl;
		}
	}
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CRemoteControl::TurnOnEngine(std::istream& args)
{
	m_car.TurnOnEngine();
	return true;
}

bool CRemoteControl::TurnOffEngine(std::istream& args)
{
	m_car.TurnOffEngine();
	return true;
}

bool CRemoteControl::Info(std::istream& args)
{
	string info = (m_car.IsTurnedOn())
		? (TURN_ON_ENGINE + SLASH + GEAR + to_string(m_car.GetGear()) + SLASH + SPEED + to_string(m_car.GetSpeed()) + SLASH + DIRECTION + m_car.GetDirection() + SLASH)
		: (TURN_OFF_ENGINE + SLASH + GEAR + to_string(m_car.GetGear()) + SLASH + SPEED + to_string(m_car.GetSpeed()) + SLASH + DIRECTION + m_car.GetDirection() + SLASH);

	m_output << info;

	return true;
}

bool CRemoteControl::SetGear(std::istream& args)
{
	try {
		int gear;
		args >> gear;
		if (args.fail()) {
			m_output << INVALID_INPUT_GEAR << std::endl;
			args.clear();
			args.ignore(numeric_limits<streamsize>::max(), '\n');
			return false;
		}

		if (m_car.SetGear(gear)) {
			m_output << GEAR_SET << gear << endl;
		}
	}
	catch (const std::ios_base::failure& e) {
		m_output << INVALID_INPUT << e.what() << endl;
		return false;
	}

	return true;
}


bool CRemoteControl::SetSpeed(std::istream& args)
{
	try {
		int speed;
		args >> speed;
		if (args.fail()) {
			m_output << INVALID_INPUT_SPEED << endl;
			args.clear();
			args.ignore(numeric_limits<streamsize>::max(), '\n');
			return false;
		}

		if (m_car.SetSpeed(speed)) {
			m_output << SPEED_SET  << speed << endl;
		}
	}
	catch (const std::ios_base::failure& e) {
		m_output << INVALID_INPUT << e.what() << endl;
		return false;
	}

	return true;
}
