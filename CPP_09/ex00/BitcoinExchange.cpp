# include "BitcoinExchange.hpp"

bool validDate(str& date, bool sp)
{
	int year, month, day;

	for(int i = 0; i < 10; i++)
	{
		if((i == 4 || i == 7) && date[i] == '-')
			continue;
		if(!std::isdigit(date[i]))
			return 1;	
	}

	if((!sp && date.length() > 10) || (sp && (date[10] != ' ' || date.length() != 11)))
		return 1;
	year = std::atoi(date.substr(0, 4).c_str());
    month = std::atoi(date.substr(5, 2).c_str());
    day = std::atoi(date.substr(8, 2).c_str());
	if(year < 1 || month < 1 || month > 12)
		return 1;
	int dayInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
	if(leap && month == 2)
		return (day < 1 || day > 29);
	else
		return(day < 1 || day > dayInMonth[month - 1]);
}
bool separate(str& date, str& nbr, str& line, char& c, bool sp)
{
	size_t sep = line.find(c);
	if(sep == str::npos || sep == 0 || sep == line.length() - 1)
		return 1;
	date = line.substr(0, sep);
	if(validDate(date, sp))
		return 1;
	nbr = line.substr(sep + 1);
	return 0;
}
bool setup_map(str& line,std::map<std::string, float>& data, char c)
{
	str date, nbr;
	
	if(separate(date, nbr, line, c, 0))
		return 1;
	char *end;
	double value = std::strtod(nbr.c_str(), &end);
	for(int i = 0; end[i]; i++)
	{
		if(end[i] != ' ')
			return 1;
	}
	data[date] = value;
	return 0;
}

bool Load_DB(std::map<std::string, float>& data) 
{
	std::ifstream dataB("data.csv");
	if(!dataB.is_open()) {
		std::cerr << "Error: Unable to open the database file." << std::endl;
		return 1;
	}
	str line;
	std::getline(dataB, line);
	if(line != "date,exchange_rate"){
		std::cerr << "first line of the database shoud be : date,exchange_rate" << std::endl;
		return 1;
	}
	while(std::getline(dataB, line)){
		 if(setup_map(line, data, ',')){
			std::cerr << "Error: Database format incorect" << std::endl;
		 	return 1;
		 }
	}
	return 0;
}

bool validInp(str &line, double& value, str& date, char c)
{
	str nbr;
	if((separate(date, nbr, line, c, 1)) || (nbr[0] != ' ' )){
		std::cerr << "Error: bad input => " << line <<std::endl;
		return 1;
	}
	char *end;
	value = std::strtod(nbr.c_str(), &end);
	for(int i = 0; end[i]; i++){
		if(end[i] != ' '){
			std::cerr << "Error: bad input => " << line <<std::endl;
			return 1;
		}
	}
	if(value < 0){
		std::cerr << "Error: not a positive number." << std::endl;
		return 1;
	}
	if(value > 10000){
		std::cerr << "Error: too large a number" << std::endl;
		return 1;
	}
	date.erase(10);
	return 0;
}

float get_value(const std::map<std::string, float>& data, const std::string& date) {
    std::map<std::string, float>::const_iterator it = data.upper_bound(date);

    if (it == data.begin()){
		std::cerr << "no matshing date" << std::endl;
        return -1;
	}
    --it;
    return it->second;
}

void setPrice(char* filename, std::map<std::string, float>& data)
{
	std::ifstream inp(filename);
	if(!inp.is_open()){
		std::cerr << "Error: Unable to open the input file.";
		return ;
	}
	str line;
	str date;
	double value;
	std::getline(inp, line);
	if(line != "date | value"){
		std::cerr << "first line of the input shoud be : date | value" << std::endl;
		return ;
	}
	while (std::getline(inp, line))
	{
		if(validInp(line, value, date, '|'))
			continue ;
		float val = get_value(data, date);
		if(val == -1)
			continue ;
		std::cout << date << " => " << value << " = " << value * val << std::endl;
	}
	
}