#pragma once
#include<string>
#include<map>
#include<sstream>
#include<vector>
#include<cmath>

class HASH
{
private:
	std::map<std::string, int> dex;
	std::map<int, std::string> rDex;
	template <typename T, typename TT>
	TT convert(T a);
	int reverseNr(int arg);
	std::map<std::string, int> GenerateDex();
	std::map<int, std::string> GenerateReverseDex(const std::map<std::string, int>& arg);
public:
	HASH();
	std::string Hash(std::string arg);
};

template <typename T, typename TT>
TT HASH::convert(T a)
{
	TT b;
	std::stringstream ss;
	ss << a;
	ss >> b;
	return b;
}