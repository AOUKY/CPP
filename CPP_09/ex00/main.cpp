# include "BitcoinExchange.hpp"

int main(int c, char ** v)
{
	if(c < 2){
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	std::map<std::string, float> data;
	if(Load_DB(data))
		return 1;
	setPrice(v[1], data);
}

