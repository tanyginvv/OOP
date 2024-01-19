#pragma once

const std::string INVALID_INPUT = " Неправильный ввод ";
const std::string INVALID_INPUT_GEAR = " Неправильный ввод, нужно ввести число для передачи ";
const std::string INVALID_INPUT_SPEED = " Неправильный ввод, нужно ввести число для скорости ";
const std::string ERROR_SPEED_RANGE = "Ошибка: неподходящая скорость для передачи. Допустимая скорость ";
const std::string BECAUSE = " потому что ";
const std::string STAND = "стоим на месте";
const std::string BACK = "назад";
const std::string FORWARD = "вперед";
const std::string ERROR_GEAR = "Ошибка: неверная передача";
const std::string ERROR_SPEED = "Ошибка: неверная скорость";
const std::string ERROR_COMMAND = "Команда не найдена";
const std::string ENGINE = "Двигатель: ";
const std::string IS_TURNED = "включен";
const std::string NOT_IS_TURNED = "выключен";
const std::string DIRECTION = "Направление: ";
const std::string SPEED = "Скорость: ";
const std::string GEAR = "Передача: ";
const std::string TURN_ON_ENGINE = "Двигатель включен";
const std::string TURN_ON_ENGINE_YET = "Двигатель уже включен";
const std::string TURN_OFF_ENGINE = "Двигатель выключен";
const std::string ERROR_TURN_ENGINE = "Невозможно выключить двигатель";
const std::string GEAR_SET = "Передача установлена на ";
const std::string ERROR_GEAR_SET = "Невозможно установить передачу на ";
const std::string SPEED_SET = "Скорость установлена на ";
const std::string ERROR_SPEED_SET = "Невозможно установить скорость на ";
const std::string INFO = "Info";
const std::string ENGINE_ON = "EngineOn";
const std::string ENGINE_OFF = "EngineOff";
const std::string SET_GEAR = "SetGear";
const std::string SET_SPEED = "SetSpeed";
const std::string SYMBOL1 = ":";
const std::string SYMBOL2 = " - ";
const std::string SLASH = "\n";
const int REVERSE = -1;
const int ZERO = 0;
const int ONE = 1;
const int TWO = 2;
const int THREE = 3;
const int FOUR = 4;
const int FIVE = 5;
const int TWENTY = 20;
const int THIRTY = 30;
const int FIFTY = 50;
const int FORTY = 40;
const int SIXTY = 60;
const int NINETY = 90;
const int ONE_HUNDRED_FIFTY = 150;
const std::map<int, std::pair<int, int>> gearSpeedMap = {
{REVERSE, {ZERO, TWENTY}},
{ONE, {ZERO, THIRTY}},
{TWO, {TWENTY, FIFTY}},
{THREE, {THIRTY, SIXTY}},
{FOUR, {FORTY, NINETY}},
{FIVE, {FIFTY, ONE_HUNDRED_FIFTY}}
};

class Car {
public:
	bool IsTurnedOn() const;
	std::string GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;
	bool TurnOnEngine();
	bool TurnOffEngine(); 
	bool SetGear(int gear);
	bool SetSpeed(int speed);
private:
	bool engineOn = false;
	int gear = ZERO;
	int speed = ZERO;
};
