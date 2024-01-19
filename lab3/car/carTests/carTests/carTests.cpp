#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../../car/car.cpp"

SCENARIO("Создание объекта")
{
	setlocale(LC_ALL, "Russian");
	Car car;
	REQUIRE(car.IsTurnedOn() == false);
	REQUIRE(car.GetDirection() == STAND);
	REQUIRE(car.GetGear() == 0);
	REQUIRE(car.GetSpeed() == 0);
	std::cout << "Создание объекта выполнено\n" << std::endl;
}

SCENARIO("Исходное состояние: машина не может изменять скорость и передачу в выключенном состоянии")
{
	Car car;
	REQUIRE(car.IsTurnedOn() == false);
	REQUIRE(car.SetGear(1) == false);
	REQUIRE(car.SetGear(REVERSE) == false);
	REQUIRE(car.SetGear(0) == false);
	REQUIRE(car.SetSpeed(10) == false);
	REQUIRE(car.SetSpeed(0) == false);
	std::cout <<"Исходное состояние: машина не может изменять скорость и передачу в выключенном состоянии выполнено\n" << std::endl;
	}

SCENARIO("Запуск двигателя")
{
	Car car;
	REQUIRE(car.TurnOnEngine() == true);
	REQUIRE(car.IsTurnedOn() == true);
	REQUIRE(car.TurnOffEngine() == true);
	REQUIRE(car.IsTurnedOn() == false);
	std::cout << "Запуск двигателя выполнен\n"  << std::endl;
}

SCENARIO("Переключение передач стоя")
{
	Car car;
	REQUIRE(car.TurnOnEngine() == true);
	REQUIRE(car.SetGear(1) == true);
	REQUIRE(car.SetGear(REVERSE) == true);
	REQUIRE(car.SetGear(0) == true);
	REQUIRE(car.SetGear(2) == false);
	std::cout << "Переключение передач стоя выполнен\n" << std::endl;
}

SCENARIO("Изменение скорости")
{
	Car car;
	REQUIRE(car.TurnOnEngine() == true);
	REQUIRE(car.SetGear(1) == true);
	REQUIRE(car.SetSpeed(10) == true);
	REQUIRE(car.SetSpeed(20) == true);
	REQUIRE(car.SetSpeed(30) == true);
	std::cout << "Изменение скорости выполнено\n" << std::endl;
}

SCENARIO("Смена скорости и передач, проверка ограничений скорости")
{
	Car car;
	REQUIRE(car.TurnOnEngine() == true);
	//Границы задней передачи
	REQUIRE(car.SetGear(-1) == true);
	REQUIRE(car.SetSpeed(21) == false);
	REQUIRE(car.SetSpeed(20) == true);
	REQUIRE(car.SetSpeed(0) == true);
	//Границы 1 передачи
	REQUIRE(car.SetGear(1) == true);
	REQUIRE(car.SetSpeed(0) == true);
	REQUIRE(car.SetSpeed(30) == true);
	REQUIRE(car.SetSpeed(31) == false);
	//Границы 2 передачи
	REQUIRE(car.SetGear(2) == true);
	REQUIRE(car.SetSpeed(19) == false);
	REQUIRE(car.SetSpeed(20) == true);
	REQUIRE(car.SetSpeed(50) == true);
	REQUIRE(car.SetSpeed(51) == false);
	//Границы 3 передачи
	REQUIRE(car.SetGear(3) == true);
	REQUIRE(car.SetSpeed(29) == false);
	REQUIRE(car.SetSpeed(30) == true);
	REQUIRE(car.SetSpeed(60) == true);
	REQUIRE(car.SetSpeed(61) == false);

	//Границы 4 передачи
	REQUIRE(car.SetGear(4) == true);
	REQUIRE(car.SetSpeed(39) == false);
	REQUIRE(car.SetSpeed(40) == true);
	REQUIRE(car.SetSpeed(90) == true);
	REQUIRE(car.SetSpeed(91) == false);
	//Границы 5 передачи
	REQUIRE(car.SetGear(5) == true);
	REQUIRE(car.SetSpeed(49) == false);
	REQUIRE(car.SetSpeed(50) == true);
	REQUIRE(car.SetSpeed(150) == true);
	REQUIRE(car.SetSpeed(151) == false);
	std::cout << "Смена скорости и передач, проверка ограничений скорости\n" << std::endl;
}

SCENARIO("Смена скорости и передач, проверка ограничений передачи")
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Car car;
	REQUIRE(car.TurnOnEngine() == true);

	//Задняя передача скорость < 0
	REQUIRE(car.SetGear(-1) == true);
	REQUIRE(car.SetSpeed(10) == true);
	REQUIRE(car.SetSpeed(-10) == false);
	REQUIRE(car.SetGear(1) == false);
	REQUIRE(car.SetSpeed(0) == true);
	REQUIRE(car.SetSpeed(-1) == false);
	//Диапазоны 1 скорости
	REQUIRE(car.SetGear(1) == true);
	REQUIRE(car.SetSpeed(10) == true);
	REQUIRE(car.SetGear(-1) == false);
	REQUIRE(car.SetGear(2) == false);
	REQUIRE(car.SetSpeed(20) == true);
	//Диапазоны 2 скорости
	REQUIRE(car.SetGear(2) == true);
	REQUIRE(car.SetSpeed(35) == true);
	REQUIRE(car.SetGear(1) == false);
	REQUIRE(car.SetSpeed(25) == true);
	REQUIRE(car.SetGear(3) == false);
	REQUIRE(car.SetSpeed(30) == true);
	//Диапазоны 3 скорости
	REQUIRE(car.SetGear(3) == true);
	REQUIRE(car.SetSpeed(55) == true);
	REQUIRE(car.SetGear(2) == false);
	REQUIRE(car.SetSpeed(35) == true);
	REQUIRE(car.SetGear(4) == false);
	REQUIRE(car.SetSpeed(40) == true);

	//Диапазоны 4 скорости
	REQUIRE(car.SetGear(4) == true);
	REQUIRE(car.SetSpeed(65) == true);
	REQUIRE(car.SetGear(3) == false);
	REQUIRE(car.SetSpeed(45) == true);
	REQUIRE(car.SetGear(5) == false);
	REQUIRE(car.SetSpeed(50) == true);

	//Диапазоны 5 скорости
	REQUIRE(car.SetGear(5) == true);
	REQUIRE(car.SetSpeed(95) == true);
	REQUIRE(car.SetGear(4) == false);
	REQUIRE(car.SetSpeed(60) == true);
	std::cout << "Смена скорости и передач, проверка ограничений передачи выполнен\n" << std::endl;

}

SCENARIO("Переключение на нейтральную передачу и установка скорости")
{
	Car car;
	REQUIRE(car.TurnOnEngine() == true);

	//задняя скорость
	REQUIRE(car.SetGear(-1) == true);
	REQUIRE(car.SetSpeed(10) == true);
	REQUIRE(car.SetGear(0) == true);
	REQUIRE(car.SetSpeed(20) == false);
	REQUIRE(car.SetSpeed(0) == true);

	//первая
	REQUIRE(car.SetGear(1) == true);
	REQUIRE(car.SetSpeed(25) == true);
	REQUIRE(car.SetGear(0) == true);
	REQUIRE(car.SetSpeed(30) == false);
	REQUIRE(car.SetSpeed(20) == true);

	//вторая
	REQUIRE(car.SetGear(2) == true);
	REQUIRE(car.SetSpeed(35) == true);
	REQUIRE(car.SetGear(0) == true);
	REQUIRE(car.SetSpeed(40) == false);
	REQUIRE(car.SetSpeed(30) == true);

	//третья
	REQUIRE(car.SetGear(3) == true);
	REQUIRE(car.SetSpeed(45) == true);
	REQUIRE(car.SetGear(0) == true);
	REQUIRE(car.SetSpeed(50) == false);
	REQUIRE(car.SetSpeed(40) == true);
	//четвертая
	REQUIRE(car.SetGear(4) == true);
	REQUIRE(car.SetSpeed(55) == true);
	REQUIRE(car.SetGear(0) == true);
	REQUIRE(car.SetSpeed(60) == false);
	REQUIRE(car.SetSpeed(50) == true);

	//пятая
	REQUIRE(car.SetGear(5) == true);
	REQUIRE(car.SetSpeed(65) == true);
	REQUIRE(car.SetGear(0) == true);
	REQUIRE(car.SetSpeed(70) == false);
	REQUIRE(car.SetSpeed(60) == true);
	std::cout << "Переключение на нейтральную передачу и установка скорости выполнен\n"  << std::endl;
}

SCENARIO("Выключение двигателя при движении вперед ")
{
	Car car;
	REQUIRE(car.TurnOnEngine() == true);
	REQUIRE(car.IsTurnedOn() == true);
	REQUIRE(car.SetGear(1) == true);
	REQUIRE(car.SetSpeed(10) == true);
	REQUIRE(car.TurnOffEngine() == false);
	REQUIRE(car.IsTurnedOn() == true);
	REQUIRE(car.SetGear(0) == true);
	REQUIRE(car.SetSpeed(0) == true);
	REQUIRE(car.TurnOffEngine() == true);
	REQUIRE(car.IsTurnedOn() == false);
	std::cout << "Выключение двигателя при движении вперед выполнен\n " << std::endl;
}

SCENARIO("Выключение двигателя при движении назад")
{
	Car car;
	REQUIRE(car.TurnOnEngine() == true);
	REQUIRE(car.IsTurnedOn() == true);
	REQUIRE(car.SetGear(-1) == true);
	REQUIRE(car.SetSpeed(10) == true);
	REQUIRE(car.TurnOffEngine() == false);
	REQUIRE(car.IsTurnedOn() == true);
	REQUIRE(car.SetGear(0) == true);
	REQUIRE(car.SetSpeed(0) == true);
	REQUIRE(car.TurnOffEngine() == true);
	REQUIRE(car.IsTurnedOn() == false);
	std::cout << "Выключение двигателя при движении назад выполнен\n" << std::endl;
}

SCENARIO("Проверка установления передачи и скорости с задней передачи на переденюю и с передней на заднюю")
{
	Car car;
	REQUIRE(car.TurnOnEngine() == true);
	REQUIRE(car.IsTurnedOn() == true);
	REQUIRE(car.SetGear(-1) == true);
	REQUIRE(car.SetSpeed(10) == true);
	REQUIRE(car.SetGear(1) == false);
	REQUIRE(car.SetGear(0) == true);
	REQUIRE(car.SetSpeed(0) == true);
	REQUIRE(car.SetGear(1) == true);
	REQUIRE(car.SetSpeed(10) == true);
	REQUIRE(car.SetGear(-1) == false);
	std::cout << "Проверка установления передачи и скорости с задней передачи на переденюю и с передней на заднюю выполнен" << std::endl;

}