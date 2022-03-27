#include "HASH.h"
int HASH::reverseNr(int arg)
{
	if (arg < 10)
	{
		return arg * 10;
	}
	else
	{
		return arg % 10 * 10 + arg / 10;
	}
}
std::map<std::string, int> HASH::GenerateDex()
{
	std::map<std::string, int> dex;
	int value = 1;
	for (int i = 33; i < 127; i++)
	{
		dex[convert<char, std::string>((char)i)] = value++;
	}
	return dex;
}
std::map<int, std::string> HASH::GenerateReverseDex(const std::map<std::string, int>& arg)
{
	std::map<int, std::string> dex;
	for (auto i : arg)
	{
		dex[i.second] = i.first;
	}
	return dex;
}
HASH::HASH()
{
	this->dex = this->GenerateDex();
	this->rDex = this->GenerateReverseDex(this->dex);
}
std::string HASH::Hash(std::string arg)
{
	std::vector<std::string> indv;
	for (auto i : arg)
	{
		indv.push_back(convert<char, std::string>(i));
	}
	if (indv.size() < 30)
	{
		for (int i = indv.size(); i < 30; i++)
		{
			int pozV = (i * (int)convert<std::string, char>(indv[i - indv.size()]) + ((i - indv.size()) * (int)convert<std::string, char>(indv[i - indv.size()])) % 94 + 1);
			int negV = (i * (int)convert<std::string, char>(indv[i - indv.size()]) - ((i - indv.size()) * (int)convert<std::string, char>(indv[i - indv.size()])) % 94 + 1);
			if (negV < 0)
			{
				negV = abs(negV);
			}
			indv.push_back(rDex[pozV * negV % 94 + 1]);
		}
	}
	int size = indv.size();
	std::vector<int> nr;
	for (int i = 0; i < size; i++)
	{
		nr.push_back(dex[indv[i]]);
	}
	std::vector<int> sum;
	for (int i = 0; i < size - 1; i++)
	{
		sum.push_back((nr[i] + nr[i + 1]) % 100);
	}
	sum.push_back((nr.back() + nr[0]) % 100);
	int check = 0;
	for (int i = 0; i < size; i++)
	{
		check += (nr[i] + sum[i]) % 100;
	}
	check += check >> 2 / nr.size();
	check = check % 100;
	std::vector<int> result;
	for (int i = 0; i < size; i++)
	{
		if (i % 2)
		{
			result.push_back(abs(check - nr[i]));
		}
		else
		{
			result.push_back(reverseNr(abs(check - nr[i])));
		}
		result[i] = (result[i] + abs(((i % 2) ? sum[i] : -sum[i]))) % 100;
		result[i] = result[i] % 94 + 1;
		//std::cout << result[i] << " ";
	}
	//std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		indv[i] = rDex[result[i]];
	}
	std::string ret;
	for (int i = 0; i < size; i++)
	{
		ret.append(indv[i]);
	}
	return ret;
}