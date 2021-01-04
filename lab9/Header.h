#pragma once
#include <iostream>
#include <string>
#include <locale.h>
#include <algorithm> 
#include<vector>
#include<iterator>
#include <fstream>
#include <list>
using namespace std;
namespace myClass
{
	class Wear
	{
	public:
		string m_name;
		int m_id;
		double m_cost;
	public:
		Wear()
		{
			m_name = "";
			m_cost = 0;
		}
		Wear(string name, int id, double cost)
		{
			m_name = name;
			m_id = id;
			m_cost = cost;
		}
	};

	class ExceptionStack
	{
	public:
		ExceptionStack(std::string error)
		{
			m_exception = error;
		}
		const char* getError()
		{

			return m_exception.c_str();
		}

	private:
		std::string m_exception;
	};
}