#pragma once

const std::string INVALID_INPUT = " ������������ ���� ";
const std::string INVALID_INPUT_GEAR = " ������������ ����, ����� ������ ����� ��� �������� ";
const std::string INVALID_INPUT_SPEED = " ������������ ����, ����� ������ ����� ��� �������� ";
const std::string ERROR_SPEED_RANGE = "������: ������������ �������� ��� ��������. ���������� �������� ";
const std::string BECAUSE = " ������ ��� ";
const std::string STAND = "����� �� �����";
const std::string BACK = "�����";
const std::string FORWARD = "������";
const std::string ERROR_GEAR = "������: �������� ��������";
const std::string ERROR_SPEED = "������: �������� ��������";
const std::string ERROR_COMMAND = "������� �� �������";
const std::string ENGINE = "���������: ";
const std::string IS_TURNED = "�������";
const std::string NOT_IS_TURNED = "��������";
const std::string DIRECTION = "�����������: ";
const std::string SPEED = "��������: ";
const std::string GEAR = "��������: ";
const std::string TURN_ON_ENGINE = "��������� �������";
const std::string TURN_ON_ENGINE_YET = "��������� ��� �������";
const std::string TURN_OFF_ENGINE = "��������� ��������";
const std::string ERROR_TURN_ENGINE = "���������� ��������� ���������";
const std::string GEAR_SET = "�������� ����������� �� ";
const std::string ERROR_GEAR_SET = "���������� ���������� �������� �� ";
const std::string SPEED_SET = "�������� ����������� �� ";
const std::string ERROR_SPEED_SET = "���������� ���������� �������� �� ";
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
