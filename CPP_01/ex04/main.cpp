# include <iostream>
# include <fstream>


std::string replace(std::string &input, std::string &s1, std::string &s2)
{
	std::string replaced;
	int pos;
	size_t found;

	pos = 0;
	found = input.find(s1, pos);
	while (found != std::string::npos)
	{
		replaced.append(input.substr(pos, found - pos));
		replaced.append(s2);
		pos = found + s1.length();
		found = input.find(s1 , pos);
	}
	replaced.append(input.substr(pos));
	return replaced;
}

int main(int c, char **v)
{
	if(c != 4)
	{
		std::cerr << "Usage: " << v[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string inFileName = v[1];
	std::string s1 = v[2];
	std::string s2 = v[3];

	if(s1.empty())
	{
		std::cerr << "nothing to replace"<< std::endl;
		return (1);
	}	
	std::ifstream infile(inFileName.c_str());
	if(!infile.is_open())
	{
		std::cerr << "Error: Could not open file " << inFileName << std::endl;
        return 1;
	}

	std::string line;
	std::string content;
	std::string result;

	while (std::getline(infile, line))
		content.append(line + "\n");
	infile.close();
	result = replace(content, s1, s2);
	std::ofstream outfile((inFileName + ".replace").c_str());
	if(!outfile.is_open())
	{
		std::cerr << "Error: Could not open file " << (inFileName + ".replace") << std::endl;
		return (1);
	}
	outfile << result;
	outfile.close();
}
