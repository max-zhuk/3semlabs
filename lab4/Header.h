#pragma once
#include <iostream>
#include <string>

class Film
{
protected:
	std::string f_name;
	double f_duration; //in hours
	int f_rate;

public:
	Film()
	{

	}
	Film(std::string fname,double fduration,int frate)
	{
		this->f_name = fname;
		this->f_duration = fduration;
		this->f_rate = frate;
	}
	~Film()
	{

	}
	void OutputFilm()
	{
		std::cout << std::endl << "===========Film===========" << std::endl;
		std::cout << "Film :" << f_name << std::endl;
		std::cout << "Duration :" << f_duration << std::endl;
		std::cout << "Rate :" << f_rate << std::endl;
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
	void OutputShortLength()
	{
		std::cout << std::endl << "============Short-length==========" << std::endl;
		std::cout << "Topic :" << s_topic<< std::endl;
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
	void OutputClip()
	{
		std::cout << std::endl << "=============Clip=============" << std::endl;
		std::cout << "Band name :" << c_bandname << std::endl;
		std::cout << "Song name :" << c_songname << std::endl;
		std::cout << "Song duration :" << c_songduration << std::endl;
	}
};

class FullLength :virtual public Film
{
protected:
	std::string fu_genre;
	std::string fu_location;
	int fu_actorsquantity;
public:
	FullLength()
	{

	}
	FullLength(std::string fugenre , std::string fulocation , int fuactorsquantity)
	{
		this->fu_genre = fugenre;
		this->fu_location = fulocation;
		this->fu_actorsquantity = fuactorsquantity;
	}
	~FullLength()
	{

	}
	void OutputFullLength()
	{
		std::cout << std::endl << "=============Full-length=============" << std::endl;
		std::cout << "Genre :" << fu_genre << std::endl;
		std::cout << "Location :" << fu_location << std::endl;
		std::cout << "Actors quantity :" << fu_actorsquantity << std::endl;
	}

};

class Mult :virtual public FullLength
{
protected:
	int m_allowedage;
	int m_fps;
	std::string m_studio;
	
public:
	Mult()
	{

	}
	Mult(int mallowedage, int mfps, std::string mstudio)
	{
		this->m_allowedage = mallowedage;
		this->m_fps = mfps;
		this->m_studio = mstudio;
	}
	~Mult()
	{

	}
	void OutputMult()
	{
		std::cout << std::endl << "================Mult================" << std::endl;
		std::cout << "Allowed age :" << m_allowedage << std::endl;
		std::cout << "Frames per second :" << m_fps << std::endl;
		std::cout << "Studio :" << m_studio << std::endl;
	}


};
class Actor : virtual public Clip, virtual public Mult
{
protected:
	std::string a_name;
	std::string a_fam;
	int a_age;
	
public:
	Actor()
	{

	}
	Actor(std::string fname, double fduration, int frate, std::string stopic, int sviews, std::string cbandname,
		std::string csongname, int csongduration, std::string fugenre, std::string fulocation, int fuactorsquantity,
		int mallowedage, int mfps, std::string mstudio,std::string aname, std::string afam, int aage)
	{
		this->f_name = fname;
		this->f_duration = fduration;
		this->f_rate = frate;
		this->s_topic = stopic;
		this->s_views = sviews;
		this->c_bandname = cbandname;
		this->c_songname = csongname;
		this->c_songduration = csongduration;
		this->fu_genre = fugenre;
		this->fu_location = fulocation;
		this->fu_actorsquantity = fuactorsquantity;
		this->m_allowedage = mallowedage;
		this->m_fps = mfps;
		this->m_studio = mstudio;
		this->a_name = aname;
		this->a_fam = afam;
		this->a_age = aage;
	}
	~Actor()
	{

	}
	void OutputActor()
	{
		std::cout << std::endl << "=================Actor================" << std::endl;
		std::cout << "Name :" << a_name << std::endl;
		std::cout << "Fam :" << a_fam << std::endl;
		std::cout << "Age :" << a_age << std::endl;
	}

};