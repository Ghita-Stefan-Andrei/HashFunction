#include<iostream>
#include<string>
#include<map>
#include<sstream>
#include<vector>
#include<cmath>
#include"HASH.h"

int main()
{
	HASH myHash;
	int n = 0;
	std::cout << " Number of strings:";
	std::cin >> n;
	std::vector<std::string> pass(n);
	for (int i = 0; i < pass.size(); i++)
	{
		std::string temp;
		std::cout << " ";
		std::cin >> temp;
		pass[i] = temp;
	}
	for (auto i : pass)
	{
		std::cout << " " << myHash.Hash(i) << std::endl;
	}
	return 0;
}