# include "PmergeMe.hpp"

void passToNbrs(char *v, char **end)
{
	int i = 0;
	while (v[i])
	{
		if((std::isdigit(v[i]) || ((v[i] == '+' || v[i] == '-')&& v[i + 1] && std::isdigit(v[i + 1]))))
			break ;
		else if(v[i] != ' ') {
			std::cerr << "Error" << std::endl;
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
		int n = strtol(end,&end,10);
		if(n < 0){
			std::cerr << "Error: negative nbr " << n << std::endl;
			std::exit(1);
		}
		vec.push_back(n);
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
//std::deque
void deque_makeJacobNbrs(std::deque<int> &j, int size)
{
	j.push_back(0);
	j.push_back(1);
	for(int i = 3, next = 1; next < size ; i++){
		j.push_back(next);  
		next = j[i -1] + (2 * j[i - 2]);
	}
}
int deque_BinarySearch(std::deque<int> &vec, int value)
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
	
void deque_inserting(std::deque<int> &main_chain, std::deque<int> &pend)
{
	std::deque<int> j;
	deque_makeJacobNbrs(j, pend.size());
	for(size_t i = 2; i < j.size(); i++){
		main_chain.insert(main_chain.begin() + deque_BinarySearch(main_chain, pend[j[i]]), pend[j[i]]);
		pend[j[i]] = -1;
	}
	for(int i = pend.size() - 1; i >= 0; i--){
		if(pend[i] != -1)
			main_chain.insert(main_chain.begin() + deque_BinarySearch(main_chain, pend[i]), pend[i]);
	}
}

void deque_sorting(std::deque<int> &v)
{
	if(v.size() == 1)
		return ;
	if(v.size() == 2 && v[0] > v[1])
		return std::swap(v[0], v[1]);
	std::deque< std::pair<int, int> > pairs;
	for(size_t i = 0; i < v.size(); i+=2){
		if(i + 1 <  v.size())
			pairs.push_back(std::make_pair(v[i], v[i + 1]));
		else
			pairs.push_back(std::make_pair(-1 , v[i]));
	}
	for(size_t i = 0; i < pairs.size(); i++){
		if(pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}
	std::deque<int> main_chain;
	std::deque<int> pend;
	for(size_t i = 0; i < pairs.size(); i++){
		if(pairs[i].first != -1)
			pend.push_back(pairs[i].first);
		main_chain.push_back(pairs[i].second);
	}
	deque_sorting(main_chain);
	deque_inserting(main_chain, pend);
	v.swap(main_chain);
}

//std::vector
void makeJacobNbrs(std::vector<int> &j, int size)
{
	j.push_back(0);
	j.push_back(1);
	for(int i = 3, next = 1; next < size ; i++){
		j.push_back(next);  
		next = j[i -1] + (2 * j[i - 2]);
	}
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
	for(size_t i = 2; i < j.size(); i++){
		main_chain.insert(main_chain.begin() + BinarySearch(main_chain, pend[j[i]]), pend[j[i]]);
		pend[j[i]] = -1;
	}
	for(int i = pend.size() - 1; i >= 0; i--){
		if(pend[i] != -1)
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
			pairs.push_back(std::make_pair(-1 , v[i]));
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
	std::cout << "Before: " ;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	clock_t start = clock();
	sorting(vec);
	clock_t end  = clock();
	std::cout << "After:  " ;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	double  duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	std::cout << "Time to process a range of "<< vec.size() << " with std::vector : "<< duration << " us" << std::endl;
	start = clock();
	deque_sorting(deq);
	end = clock();
	duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0;
	std::cout << "Time to process a range of "<< deq.size() << " with std::deque : "<< duration << " us" << std::endl;
}