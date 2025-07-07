# include "PmergeMe.hpp"

int therIsMoreNbrs(char *v)
{
	for(int i = 0; v[i]; i++){
		if(v[i] != ' '){
			if(std::isdigit(v[i]) || ((v[i] == '-' || v[i] == '+') && v[i + 1] && std::isdigit(v[i + 1])))
				return 0;
			return -1;
		}
	}
	return 1;
}

void set_nbr(char *v, std::vector<int> &vec)
{
	char *end;
	int n = strtol(v, &end, 10);
	if(therIsMoreNbrs(v) == -1 || n < 0){
			std::cerr << "invalid input" << std::endl;
			std::exit(1);
	}
	vec.push_back(n);
	while (end[0])
	{
		int x = therIsMoreNbrs(end);
		n = strtol(end,&end, 10);
		if(n < 0 || x == -1){
			std::cerr << "invalid input" << std::endl;
			std::exit(1);
		}
		else if(x == 1)
			break;
		vec.push_back(n);
	}
}

void passToNbrs(char *v, char **end)
{
	int i = 0;
	while (v[i])
	{
		if((std::isdigit(v[i]) || (v[i] == '+' && v[i + 1] && std::isdigit(v[i + 1]))))
			break ;
		else if(v[i] != ' ') {
			std::cerr << "invalid input" << std::endl;
			std::exit(1);
		}
		i++;
	}
	*end = &v[i];
}

void set_nbrs(char *v, std::vector<int> &vec)
{
	char *end;
	passToNbrs(v, &end);

	while (end[0])
	{
		vec.push_back(strtol(end,&end,10));
		passToNbrs(end,&end);
	}
}


void get_nbrs(char **v, std::vector<int> &vec, std::deque<int> &deq)
{
	for(int i = 1; v[i]; i++){
		set_nbrs(v[i], vec);
	}
	if(vec.empty()){
		std::cerr << "insert some nbrs " << std::endl;
		std::exit(1);
	}
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		deq.push_back(*it);
}
void makeJacobNbrs(std::vector<int> &j, int size)
{
	j.push_back(0);
	if(size == 1 || size == 2)
		return ;
	j.push_back(1);
	for(int i = 2; j[i] < size ; i++)
		j.push_back(j[i -1] + 2 * j[i - 2]);  
}
int BinarySearch(std::vector<int> &vec, int value)
{
	int left = 0;
    int right = vec.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left; 
}
	
void inserting(std::vector<int> &main_chain, std::vector<int> &pend)
{
	std::vector<int> j;
	makeJacobNbrs(j, pend.size());
	for(int i = 2; j.size() >= 3 && j[i] < (int)pend.size(); i++){
		main_chain.insert(main_chain.begin() + BinarySearch(main_chain, pend[j[i]]), pend[j[i]]);
		pend[j[i]] = -1;
	}
	for(int i = pend.size() - 1; i >= 0; i--){
		if(pend[i] == -1)
			continue;
		main_chain.insert(main_chain.begin() + BinarySearch(main_chain, pend[i]), pend[i]);
	}
}

void sorting(std::vector<int> &v)
{
	if(v.size() == 1)
		return ;
	if(v.size() == 2 && v[0] > v[1])
		return std::swap(v[0], v[1]);
	std::vector< std::pair<int, int> > pairs;
	for(size_t i = 0; i < v.size(); i+=2){
		if(i + 1 <  v.size())
			pairs.push_back(std::make_pair(v[i], v[i + 1]));
		else
			pairs.push_back(std::make_pair(v[i], -1));
	}
	for(size_t i = 0; i < pairs.size(); i++){
		if(pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}
	std::vector<int> main_chain;
	std::vector<int> pend;
	for(size_t i = 0; i < pairs.size(); i++){
		if(pairs[i].first != -1)
			pend.push_back(pairs[i].first);
		main_chain.push_back(pairs[i].second);
	}
	sorting(main_chain);
	inserting(main_chain, pend);
	v.swap(main_chain);
}
void PmergeMe(char **v)
{
	std::vector<int> vec;
	std::deque<int> deq;
	get_nbrs(v, vec, deq);
	sorting(vec);
	
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}