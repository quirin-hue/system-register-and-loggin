#ifndef CLIENT_H
#define CLIENT_H
//Ещё не реализовано.
#include<string>
#include<iostream>
#include<fstream>
#include<thread>

class Client
{
private:
	std::string Email, Password, Name, Last_Name;
public:
	std::string Get(std::string Email_, std::string Password_, std::string Name_, std::string Last_Name_)
	{
		Email = Email_;
		Password = Password_;
		Name = Name_;
		Last_Name = Last_Name_;
	}

	std::string Analys()
	{

	}
};


#endif CLIENT_H