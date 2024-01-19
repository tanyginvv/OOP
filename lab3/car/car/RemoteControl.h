#pragma once
#include <ostream>
#include <functional>
#include <map>

class Car;

class CRemoteControl
{
public:
	CRemoteControl(Car& car, std::istream& input, std::ostream& output);
	bool HandleCommand();
private:
	bool TurnOnEngine(std::istream& args);
	bool TurnOffEngine(std::istream& args);
	bool Info(std::istream& args);
	bool SetGear(std::istream& args);
	bool SetSpeed(std::istream& args);
private:

	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	Car& m_car;
	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;
};
