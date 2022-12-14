#pragma once
#include <chrono>
#include <iostream>

using namespace std;

class RunTimer
{
public:
	RunTimer() : m_beg(clock_t::now())
	{};
	RunTimer(std::string name) : m_name(name), m_beg(clock_t::now())
	{};

	void start(std::string name)
	{
		m_name = name;
		m_beg = clock_t::now();
	}
	void print() const {
		cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
	}
private:
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1>>;
	string m_name;
	chrono::time_point<clock_t> m_beg;
	double elapsed() const
	{
		return chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};