# include "Harl.hpp"

void Harl::debug() {
	std::cout << "[ DEBUG ]"<<std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]"<<std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning() {

	std::cout << "[ WARNING ]"<<std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]"<<std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;
	void (Harl::*action[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4)
	{
		if(levels[i] == level)
			break;
		i++;
	}
	switch (i)
	{
	case 0:
		(this->*action[0])();
	case 1:
		(this->*action[1])();
	case 2:
		(this->*action[2])();
	case 3:
		(this->*action[3])();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems. ]" << std::endl;
		break;
	}
} 
