#pragma once
#include <iostream>
#include <string>
class Film
{
protected:
	std::string f_filmname;
	int f_duration;
	int f_rate;
public:
	Film()
	{
		f_filmname = "0";
		f_duration = 0;
		f_rate = 0;
	}
	Film(std::string filmname, int duration, int rate)
	{
		f_filmname = filmname;
		f_duration = duration;
		f_rate = rate;
	}
	virtual void Output()
	{
		
	}
	 
	virtual ~Film()
	{

	}
};
class ShortLength :virtual public Film
{
protected:
	std::string s_topic;
	int s_views;

public:
	ShortLength()
	{

	}
	ShortLength(std::string stopic, int sviews)
	{
		this->s_topic = stopic;
		this->s_views = sviews;
	}
	~ShortLength()
	{

	}
	void Output()
	{
		std::cout << std::endl << "============Short-length==========" << std::endl;
		std::cout << "Topic :" << s_topic << std::endl;
		std::cout << "Views :" << s_views << std::endl;
	}
};

class Clip :virtual public ShortLength
{
protected:
	std::string c_bandname;
	std::string c_songname;
	int c_songduration; //in seconds
public:
	Clip()
	{

	}
	Clip(std::string cbandname, std::string csongname, int csongduration)
	{
		this->c_bandname = cbandname;
		this->c_songname = csongname;
		this->c_songduration = csongduration;
	}
	~Clip()
	{

	}
	void Output()
	{
		std::cout << std::endl << "=============Clip=============" << std::endl;
		std::cout << "Band name :" << c_bandname << std::endl;
		std::cout << "Song name :" << c_songname << std::endl;
		std::cout << "Song duration :" << c_songduration << std::endl;
	}
};

class FullLength:virtual public Film
{
protected:
	std::string fu_genre;
	std::string fu_location;
	int fu_actorsquantity;
public:
	FullLength()
	{

	}
	FullLength(std::string fugenre, std::string fulocation, int fuactorsquantity)
	{
		this->fu_genre = fugenre;
		this->fu_location = fulocation;
		this->fu_actorsquantity = fuactorsquantity;
	}
	~FullLength()
	{

	}
	void Output()
	{
		std::cout << std::endl << "=============Full-length=============" << std::endl;
		std::cout << "Genre :" << fu_genre << std::endl;
		std::cout << "Location :" << fu_location << std::endl;
		std::cout << "Actors quantity :" << fu_actorsquantity << std::endl;
	}

};


