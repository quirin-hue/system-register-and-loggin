#ifndef SERVER_H
#define SERVER_H
#include"Client.h"
#include<vector>
#include<fstream>
#include<istream>

//Допилино до конца.

class Server
{
private:
	std::string ClientEmail;
	std::string ClientPassword;
	std::string ClientName;
	std::string ClientLastName;
	std::string ClientTelephone;
	std::vector<std::string> Email;
	std::vector<std::string> Password;
	std::vector<std::string> ClientName_VEC;
	std::vector<std::string> ClientLastName_VEC;
	std::vector<std::string> ClientTelephone_VEC;
public:
	/*
	Создание файла.
	Чтение файла.
	*/
	void DataBase()
	{
		//Псевдо база данных пользователей.
		Email.push_back("Shishkov.alexlist@gmail.com"); //1
		Email.push_back("Shashkov.kirill@yandex.ru");//2
		Email.push_back("Kirillov.Ilya@mail.ru");//3
		Email.push_back("Frolov.Alexey@gmail.com");//4
		Email.push_back("Chernov.Egor@mail.ru");//5

		Password.push_back("FktrctqIbirjd3368!");
		Password.push_back("sdfhdfhdfhdfhF21!");
		Password.push_back("asfasf!gsdgge2515Gasfv");
		Password.push_back("ASfgdgasdgHASGHas251256126!");
		Password.push_back("FasfasfSAFASfasfasfASFASFas512512525!!!!!");

		ClientName_VEC.push_back("Alexey");
		ClientName_VEC.push_back("Kirill");
		ClientName_VEC.push_back("Ilya");
		ClientName_VEC.push_back("Alexey");
		ClientName_VEC.push_back("Egor");

		ClientLastName_VEC.push_back("Shishkov");
		ClientLastName_VEC.push_back("Shashkov");
		ClientLastName_VEC.push_back("Kirillov");
		ClientLastName_VEC.push_back("Frolov");
		ClientLastName_VEC.push_back("Chernov");

		ClientTelephone_VEC.push_back("+7 - 900 - 111 - 04 - 17");
		ClientTelephone_VEC.push_back("+7 - 920 - 161 - 73 - 35");
		ClientTelephone_VEC.push_back("+7 - 937 - 554 - 81 - 31");
		ClientTelephone_VEC.push_back("+7 - 900 - 111 - 03 - 12");
		ClientTelephone_VEC.push_back("+7 - 920 - 161 - 83 - 32");

		//Временно. Нужно доделать.
		//А что доделать, если это доделано! Это же псевдо Б/Д пользователей.
	}


	void ReadDataBase()
	{
		
		std::vector<std::string>::iterator iElementLocatorEmail = begin(Email);
		std::vector<std::string>::iterator iElementLocatorName = begin(ClientName_VEC);
		std::vector<std::string>::iterator iElementLocatorLastName = begin(ClientLastName_VEC);
		std::vector<std::string>::iterator iElementLocatorTelephone = begin(ClientTelephone_VEC);
		while (iElementLocatorEmail != end(Email))
		{
			size_t Index = std::distance(begin(Email), iElementLocatorEmail);
			std::cout << "_______________________________________" << std::endl;
			std::cout << "Index: " << Index + 1 << std::endl;
			std::cout << "Name: " << *iElementLocatorName << std::endl;
			std::cout << "Last Name: " << *iElementLocatorLastName << std::endl;
			std::cout << "Telephone: " << *iElementLocatorTelephone << std::endl;
			std::cout << "Email: " << *iElementLocatorEmail << std::endl;
			std::cout << "_______________________________________" << std::endl;

			++iElementLocatorEmail;
			++iElementLocatorName;
			++iElementLocatorLastName;
			++iElementLocatorTelephone;
		}
	}

	bool CorrectlyEmail(std::string Email_, std::string Password_, bool& TrueOrFalse)
	{
		bool Check1 = false, Check2 = false;
		std::vector<std::string>::iterator iElementLocatorEmail = begin(Email);
		//Проверка, есть ли такой емейл в псевдо б/д

		//!!!!!!!!!!ПОЛНОСТЬЮ ПЕРЕПИСАТЬ!!!!!!!!!!
		//Первое правило программиста - если работает, не трогай.

		while (iElementLocatorEmail != end(Email))
		{

			if (*iElementLocatorEmail == Email_) // OK
			{
				Check1 = true;
				break;
			}
			iElementLocatorEmail++;
		}
		//Проверка, верный ли пароль для этого емейла(если существует)

		std::vector<std::string>::iterator iElementLocatorPassword = begin(Password);
		while (iElementLocatorPassword != end(Password))
		{
			if (*iElementLocatorPassword == Password_)
			{
				//std::cout << *iElementLocatorEmail << std::endl;
				//std::cout << Password_ << std::endl;
				Check2 = true;
				break;
			}
			iElementLocatorPassword++;
		}
		if (Check1 == true && Check2 == true)
			return TrueOrFalse = true;
	}

	//Регистрация
	void Registration()
	{
		/*
		Проверка, есть ли такой емейл, если есть, то нельзя регатся, в ином случае, регистрация успешна.
		*/

		//Для начала просто регистрация с новыми значениями
		std::cout << "____________________________________" << std::endl;
		std::cout << "Your Name: "; std::cin >> ClientName; ClientName_VEC.push_back(ClientName); std::cout << std::endl;
		std::cout << "Your Last Name: "; std::cin >> ClientLastName; ClientLastName_VEC.push_back(ClientName); std::cout << std::endl;
		std::cout << "Your number telephone: "; std::cin >> ClientTelephone; ClientTelephone_VEC.push_back(ClientTelephone); std::cout << std::endl;
		std::cout << "Welcome, " << ClientName << ClientLastName << "!" << std::endl;
		std::cout << "____________________________________" << std::endl;
	}

	std::string Get(std::string Get1, std::string Get2)
	{
		std::string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		std::string Cifr = "1234567890";
		bool Flag1 = false, Flag2 = false, Flag3 = false, Flag4 = false;
		int count = 0, Flag_Count = 0;
		std::cout << "Input your Email\n>"; std::cin >> Get1;

		std::string::iterator iElementGet1 = begin(Get1);
		std::string::iterator Find;

		while (iElementGet1 != Get1.end())
		{
			if (Flag1 == false)
			{
				Find = std::find(iElementGet1, end(Get1), '.');
				if (Find != Get1.end())
					Flag1 = true;
			}

			if (Flag1 == true && Flag2 == false)
			{
				Find = std::find(iElementGet1, end(Get1), '@');
				if (Find != Get1.end())
				{
					Flag2 = true;
				}
			}
			if (Flag1 == true && Flag2 == true && Flag3 == false)
			{
				count = Get1.rfind('.');
				Flag3 = true;
				count = Get1.length() - count;

				//std::cout << "True!";
			}
			//std::cout << "|DEBUG|\n";
			//std::cout << count;
			if (Flag1 == true && Flag2 == true && Flag3 == true && 4 >= count || count >= 2)
			{
				Flag4 = true;
			}
			else
			{
				std::cout << "Email or Password not correctly!";
			}
			++iElementGet1;
		}


		bool FFlag1 = false, FFlag2 = false, FFlag3 = false, FFlag4 = false;
		/*
		FFlag1 = Проверка на хотя бы одну заглавную букву
		FFlag2 = Длина пароля от 16 до 25 символов
		FFlag3 = Наличие цифр
		FFlag4 = Наличие хотя бы одного знака(!)
		*/
		std::string::iterator iElementPassword = begin(Get2);
		if (Flag1 == true && Flag2 == true && Flag3 == true && Flag4 == true)
		{
			std::cout << "Input your password\n>"; std::cin >> Get2;
			size_t n = Alphabet.length();
			for (int i = 0; i < n; ++i)
			{
				Find = std::find(iElementPassword, end(Get2), Alphabet[i]);
				if (Find != end(Get2))
					FFlag1 = true;
			}

			if (Get2.length() >= 16 || 25 >= Get2.length())
				FFlag2 = true;
			size_t n2 = Cifr.length();
			for (int i = 0; i < n2; ++i)
			{
				Find = std::find(iElementPassword, end(Get2), Cifr[i]);
				if (Find != end(Get2))
					FFlag3 = true;
			}

			Find = std::find(iElementPassword, end(Get2), '!');
			if (Find != end(Get2))
				FFlag4 = true;

			if (FFlag1 == true && FFlag2 == true && FFlag3 == true && FFlag4 == true)
			{
				std::cout << "Password is right! " << std::endl;
			}
			else
				std::cout << "Password is not right! " << std::endl;
		}
		else
		{
			std::cout << "Email is not correctly!";
		}
		if (Flag1 == true && Flag2 == true && Flag3 == true && Flag4 == true && FFlag1 == true && FFlag2 == true && FFlag3 == true && FFlag4 == true)
		{
			Email.push_back(Get1);
			Password.push_back(Get2);
		}

		//
		return Get1, Get2;
	}

	//Тестовый
	void Check_Email(std::string Email_, std::string Password_)
	{
		std::cout << "|DEBUG|" << std::endl;
		std::cout << "CHECK EMAIL && PASSWORD";
		bool flag1 = false, flag2 = false;

		std::vector<std::string>::iterator iElementLocatorEmail = begin(Email);
		std::vector<std::string>::iterator iElementLocatorPassword = begin(Password);

		while (iElementLocatorEmail != end(Email))
		{
			if (Email_ == *iElementLocatorEmail)
			{
				std::cout << "This Email is registered! ";
				flag1 = true;
			}
			if (flag1 == true)
			{
				break;
			}
		}
		if (flag1 == true)
		{
			while (iElementLocatorPassword != end(Password))
			{
				if (*iElementLocatorPassword == Password_)
				{
					break;
					flag2 = true;
				}
			}
		}
		if (flag1 == true && flag2 == true)
		{
			std::cout << "Email and Password correctly! " << std::endl;
		}
	}
};

class SourceData : private Server
{
private:
	std::vector<std::string> SourceEmail;
	std::vector<std::string> SourcePassword;
public:
	SourceData() {};
	SourceData(std::string Email, std::string Password) { SourceEmail.push_back(Email), SourcePassword.push_back(Password); };

};

#endif SERVER_H