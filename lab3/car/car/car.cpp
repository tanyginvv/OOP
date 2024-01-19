#include "stdafx.h"
#include "Car.h"
#include "RemoteControl.h"

bool Car::IsTurnedOn() const {
	return engineOn;
}
std::string Car::GetDirection() const {
	if (speed == ZERO) {
		return STAND;
	}
	else if (gear == REVERSE) {
		return BACK;
	}
	else {
		return FORWARD;
	}
}
int Car::GetSpeed() const {
	return abs(speed);
}
int Car::GetGear() const{
	return gear;
}
bool Car::TurnOnEngine() {
	if (!engineOn) {
		engineOn = true;
	    std::cout << TURN_ON_ENGINE << std::endl;
		return true;
	}
	else {
		std::cout << TURN_ON_ENGINE_YET << std::endl;
	}
	return false;
}
bool Car::TurnOffEngine() {
	if (engineOn && gear == ZERO && speed == ZERO) {
		engineOn = false;
		std::cout << TURN_OFF_ENGINE << std::endl;
		return true;
	}
	else {
		std::cout << ERROR_TURN_ENGINE << std::endl;
	}
	return false;
}
bool Car::SetGear(int m_gear) {
	if (!engineOn) {
		std::cout << TURN_OFF_ENGINE << std::endl;
		return false;
	}

	if (m_gear < REVERSE || m_gear > FIVE) {
		std::cout << ERROR_GEAR_SET << m_gear << std::endl;
		return false;
	}

	if (((gear == REVERSE && GetDirection() == BACK) && m_gear == ONE) || (gear == ONE && GetDirection() == FORWARD) && m_gear == REVERSE) {
		std::cout << ERROR_GEAR_SET << m_gear << std::endl;
		return false;
	}

	if (m_gear == ZERO) {
		gear = m_gear;
		return true;
	}

	int gearSpeedMin = ZERO;
	int gearSpeedMax = ZERO;

	auto gearSpeed = gearSpeedMap.find(m_gear);
	if (gearSpeed == gearSpeedMap.end()) {
		return false;
	}

	gearSpeedMin = gearSpeed->second.first;
	gearSpeedMax = gearSpeed->second.second;

	if (speed < gearSpeedMin || speed > gearSpeedMax) {
		std::cout << ERROR_GEAR_SET << m_gear << BECAUSE << GetSpeed() << std::endl;
		return false;
	}

	gear = m_gear;
	return true;
}

bool Car::SetSpeed(int m_speed) {
	if (m_speed < ZERO || m_speed > ONE_HUNDRED_FIFTY) {
		return false;
	}

	if (!engineOn) {
		std::cout << TURN_OFF_ENGINE << std::endl;
		return false;
	}

	if (gear == ZERO && m_speed < speed) {
		speed = m_speed;
		return true;
	}

	int gearSpeedMin = ZERO;
	int gearSpeedMax = ZERO;

	auto gearSpeed = gearSpeedMap.find(gear);
	if (gearSpeed == gearSpeedMap.end()) {
		return false;
	}

	gearSpeedMin = gearSpeed->second.first;
	gearSpeedMax = gearSpeed->second.second;

	if (m_speed < gearSpeedMin || m_speed > gearSpeedMax) {
		std::cout << ERROR_SPEED_RANGE << SYMBOL1 << gearSpeedMin << SYMBOL2 << gearSpeedMax << std::endl;
		return false;
	}

	speed = m_speed;
	return true;
}

