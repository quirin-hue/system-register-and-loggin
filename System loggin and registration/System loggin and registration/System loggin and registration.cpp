#include"Client.h"
#include"Server.h"
#include<algorithm>
#include<ctime>
#include<Windows.h>

struct time {
	int tm_sec, tm_min, tm_hour, tm_mday, tm_mon, tm_year, tm_wday, tm_yday, tm_isdst;
};

void Display()
{
	std::cout << "=================================================================" << std::endl;
	std::cout << "\t\t\t\tWelcome.\t\t\t\t" << std::endl;
	std::cout << "If you need help input '-help' " << std::endl;
	std::cout << "prod. Alexey" << std::endl;
	/*time_t now = std::time(0);
	char* dt = std::ctime(&now);
	std::cout << "The local date and time is: " << dt << std::endl;

	tm* gmtm = gmtime(&now);
	dt = asctime(gmtm);
	std::cout << "The UTC date and time is: " << dt << std::endl;
	*/
	std::cout << "=================================================================" << std::endl;


}

void Control()
{

}

//main
void func()
{

	Client Cl;
	Server Sr;
	Sr.DataBase(); //Тестовая Б/Д
	bool Hi = true;
	for (;;)
	{
		std::string Email, Password;
		std::string Str;

		if (Hi == true)
		{
			Display();
			Hi = false;
		}

		std::cin >> Str;
		std::transform(begin(Str), end(Str), begin(Str), tolower); //На всякий

		if (Str == "-help")
		{
			std::cout << "________________________________________________" << std::endl;
			std::cout << "\t\tList of commands" << std::endl;
			std::cout << "Input - Input your Email and Password" << std::endl;
			std::cout << "List - all users of this system      " << std::endl;
			std::cout << "Registration or Reg - Registration in the system" << std::endl;
			std::cout << "Loggin or Log - Log in to the system" << std::endl;
			std::cout << "Quit or Q - exit" << std::endl;
			std::cout << "________________________________________________" << std::endl;
		}
		else if (Str == "input")
		{
			//Не понятно, писал от балды, а теперь не знаю, что сюда впихнуть.
		}
		//Настроено.
		else if (Str == "registration" || Str == "reg")
		{
			bool flag_reg = false;
			Sr.Registration();
			flag_reg = true;
			if (flag_reg == true)
			Sr.Get(Email, Password);
		}
		else if (Str == "loggin" || Str == "log")
		{
			bool TrueOrFalse = false;
			std::cout << "\t\tLOGGIN" << std::endl;
			std::cout << "Email: "; std::cin >> Email;
			std::cout << "Password: "; std::cin >> Password;
			Sr.CorrectlyEmail(Email, Password, TrueOrFalse);
			if (TrueOrFalse == true)
			{
				std::cout << "Loggin Succsesfull! " << std::endl;
			}
			else
			{
				std::cout << "Loggin not succsesfull, please, check password and email!" << std::endl;
			}
		}

		else if (Str == "list")
		{

			Sr.ReadDataBase();
		}

		else if (Str == "q" || Str == "quit")
		{
			std::cout << "Bye, bye! " << std::endl;
			Sleep(2000);
			exit(0);
		}
	}


}


int main()
{
	std::setlocale(LC_ALL, "Russian");
	std::system("color 02");
	func();
	std::system("pause");
	return 0;
}