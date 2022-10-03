#pragma once
#include <algorithm>
#include <string>

using namespace std;

int Count_if_find(const string& line, const string& elements)
{
	return count_if(line.begin(), line.end(),
		[&elements](const char& temp)
	{
		return elements.find(temp) != string::npos;
	});
}

int Count_if_for(const string& line, const string& elements)
{
	return count_if(line.begin(), line.end(),
		[&elements](const char& temp)
		{
			for (auto& element : elements)
				if (temp == element)
					return true;
			return false;
		});
}

int For_find(const string& line, const string& elements)
{
	int count(0);
	for (auto& temp : line)
		if (elements.find(temp) != string::npos)
			count++;
	return count;
}

int For_for(const string& line, const string& elements)
{
	int count(0);
	for (auto& temp : line)
	{
		for (auto& element : elements)
		{
			if (temp == element)
			{
				count++;
				break;
			}
		}
	}
	return count;
}