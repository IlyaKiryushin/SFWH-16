#include "Chat.h"
#include "Message.h"
#include "User.h"
#include <vector>
#include <iostream>
#include <map>
void Chat::createChat()
{
	isChatWorking_ = true;
}
bool Chat::isChatWorking()
{
	return isChatWorking_;
}
void Chat::regIn()
{
	std::string login;
	std::string password;
	std::string name;
	std::cout << "Введите логин: ";
	std::cin >> login;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (User user : users_)
	{
		while (login == user.getLogin())
		{
			std::cout << std::endl;
			std::cout << "Логин уже существует. Выберите действие:" << std::endl << "1 - Введите другой логин" << std::endl << "0 - Выйти из чата" << std::endl;
			std::cout << std::endl << "Ваше действие: ";
			const char TRY = '1';
			const char EXIT = '0';
			std::string op;
			while (op != "0" && op != "1")
			{
				std::cin >> op;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl;
				std::map <std::string, char> mapping;
				mapping["1"] = TRY;
				mapping["0"] = EXIT;
				switch (mapping[op])
				{
				case TRY:
					std::cout << "Введите логин: ";
					std::cin >> login;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				case EXIT:
					isChatWorking_ = false;
					std::cout << "Прощайте! " << std::endl;
					return;
				default:
					std::cout << "Введена неверная команда. Выберите действие:" << std::endl << "1 - Введите другой логин" << std::endl << "0 - Выйти из чата" << std::endl;
					std::cout << std::endl << "Ваше действие: ";
					break;
				}
			}
		}
	}
	std::cout << "Введите пароль: ";
	std::cin >> password;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "Введите имя: ";
	std::cin >> name;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	for (User user : users_)
	{
		while (name == user.getName())
		{
			std::cout << std::endl;
			std::cout << "Имя уже существует. Выберите действие:" << std::endl << "1 - Введите другое имя" << std::endl << "0 - Выйти из чата" << std::endl;
			std::cout << std::endl << "Ваше действие: ";
			std::string op;
			const char TRY = '1';
			const char EXIT = '0';
			while (op != "0" && op != "1")
			{
				std::cin >> op;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl;
				std::map <std::string, char> mapping;
				mapping["1"] = TRY;
				mapping["0"] = EXIT;
				switch (mapping[op])
				{
				case TRY:
					std::cout << "Ведите имя: ";
					std::cin >> name;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				case EXIT:
					isChatWorking_ = false;
					std::cout << std::endl;
					std::cout << "Прощайте! " << std::endl;
					return;
				default:
					std::cout << "Имя уже существует. Выберите действие:" << std::endl << "1 - Введите другое имя" << std::endl << "0 - Выйти из чата" << std::endl;
					std::cout << std::endl << "Ваше действие: ";
					break;
				}
			}
		}
	}
	User user = User(login, password, name);
	users_.push_back(user);
	currUser_ = std::make_shared<User>(user);
	std::cout << std::endl;
	std::cout << "Привет " << currUser_->getName() << "! Добро пожаловать в чат! " << std::endl;
}
void Chat::logIn()
{
	std::string login;
	std::string password;
	std::string op;
	std::cout << "Введите логин: ";
	std::cin >> login;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	currUser_ = getUserByLogin(login);
	if (!currUser_)
	{
		while (!currUser_)
		{
			const char TRY = '1';
			const char REGIN = '2';
			const char EXIT = '0';
			std::cout << std::endl;
			std::cout << "Пользователя с таким логином не существует. Выберите действие:" << std::endl << "1 - Введите другое имя" << std::endl << "0 - Выйти из чата" << std::endl;
			std::cout << std::endl << "Ваше действие: ";
			while (op != "1" && op != "2" && op != "0")
			{
				std::cin >> op;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl;
				std::map <std::string, char> mapping;
				mapping["1"] = TRY;
				mapping["2"] = REGIN;
				mapping["0"] = EXIT;
				switch (mapping[op])
				{
				case TRY:
					logIn();
					break;
				case REGIN:
					regIn();
					break;
				case EXIT:
					isChatWorking_ = false;
					std::cout << std::endl;
					std::cout << "Прощайте! " << std::endl;
					return;
				default:
					std::cout << "Введена неверная команда. Выберите действие:" << std::endl << "1 - Введите другой логин" << std::endl << "2 - Регистрация в чате" << std::endl << "0 - Выйти из чата" << std::endl;
					std::cout << std::endl << "Ваше действие: ";
					break;
				}
			}
		}
	}
	else
	{
		std::cout << "Введите пароль: ";
		std::cin >> password;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;
		while (password != currUser_->getPassword())
		{
			std::cout << "Пароль не верный. Выберите действие:" << std::endl << "1 - Введите другой пароль" << std::endl << "0 - Выйти из чата" << std::endl;
			std::cout << std::endl << "Ваше действие: ";
			std::string op;
			const char TRY = '1';
			const char EXIT = '0';
			while (op != "1" && op != "0")
			{
				std::cin >> op;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << std::endl;
				std::map <std::string, char> mapping;
				mapping["1"] = TRY;
				mapping["0"] = EXIT;
				switch (mapping[op])
				{
				case TRY:
					std::cout << "Введите пароль: ";
					std::cin >> password;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << std::endl;
					break;
				case EXIT:
					isChatWorking_ = false;
					std::cout << std::endl;
					std::cout << "Прощайте! " << std::endl;
					return;
				default:
					std::cout << "Введена неверная команда. Выберите действие:" << std::endl << "1 - Введите другой логин" << std::endl << "0 - Выйти из чата" << std::endl;
					std::cout << std::endl << "Ваше действие: ";
					break;
				}
			}
		}
		std::cout << "Привет " << currUser_->getName() << "! Добро пожаловать в чат! " << std::endl << std::endl;
	}
}
void Chat::chatOptions()
{
	std::string op;
	std::cout << std::endl << "Выберите действие:" << std::endl << "1 - Регистрация в чате" << std::endl << "2 - Вход в чат" << std::endl << "0 - Выход" << std::endl;
	std::cout << std::endl << "Ваше действие: ";
	const char REGIN = '1';
	const char LOGIN = '2';
	const char EXIT = '0';
	while (op != "1" && op != "2" && op != "0" && isChatWorking_)
	{
		std::cin >> op;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;
		std::map <std::string, char> mapping;
		mapping["1"] = REGIN;
		mapping["2"] = LOGIN;
		mapping["0"] = EXIT;
		switch (mapping[op])
		{
		case REGIN:
			regIn();
			break;
		case LOGIN:
			logIn();
			break;
		case EXIT:
			std::cout << "Прощайте! " << std::endl;
			isChatWorking_ = false;
			return;
		default:
			std::cout << "Введена неверная команда. Выберите действие:" << std::endl << "1 - Регистрация в чате" << std::endl << "2 - Вход в чат" << std::endl << "0 - Выход" << std::endl;
			std::cout << std::endl << "Ваше действие: ";
			break;
		}
	}
}

void Chat::userOptions()
{
	const char WRITE = '1';
	const char SHOW = '2';
	const char LOGOUT = '0';
	while (currUser_)
	{
		std::cout << std::endl << "Выберите действие:" << std::endl << "1 - Написать сообщение" << std::endl << "2 - Показать входящие сообщения" << std::endl << "0 - Выйти из чата" << std::endl;
		std::cout << std::endl << "Ваше действие: ";
		std::string op;
		while (op != "1" && op != "2" && op != "0")
		{
			std::cin >> op;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << std::endl;
			std::map <std::string, char> mapping;
			mapping["1"] = WRITE;
			mapping["2"] = SHOW;
			mapping["0"] = LOGOUT;
			switch (mapping[op])
			{
			case WRITE:
				writeMessage();
				break;
			case SHOW:
				showMessages();
				break;
			case LOGOUT:
				std::cout << currUser_->getName() << " покинул(а) чат! " << std::endl;
				currUser_ = nullptr;
				break;
			default:
				std::cout << "Введена неверная команда. Выберите действие:" << std::endl << "1 - Написать сообщение" << std::endl << "2 - Показать входящие сообщения" << std::endl << "0 - Выйти из чата" << std::endl;
				std::cout << std::endl << "Ваше действие: ";
				break;
			}
		}
	}
}
void Chat::writeMessage()
{
	std::string text;
	double i = 1, userNum = 1;
	std::cout << "Текст сообщения: ";
	std::cout << std::endl;
	std::getline(std::cin, text);
	std::cout << std::endl;
	std::cout << "Кому адресовать сообщение? ";
	std::cout << std::endl;
	for (User& user : users_)
	{
		std::cout << user.getName() << " - " << i << std::endl;
		i++;
	}
	std::cout << "В общем чате - " << i << std::endl;
	std::cout << "Введите номер: ";
	while (!(std::cin >> userNum))
	{
		std::cout << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Введено неверное число! Попробуйте заново!" << std::endl;
		std::cout << "Пользователь: ";
	}
	std::cout << std::endl;
	while (!userNum || userNum > i)
	{
		std::cout << "Пользователя с таким номеров не существует! Попробуйте заново!" << std::endl;
		std::cout << "Пользователь: ";
		std::cin >> userNum;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl;
	}
	if (userNum == i)
	{
		for (User& user : users_)
		{
			Message message = Message(currUser_->getName(), user.getName(), text);
			messages_.push_back(message);
		}
		std::cout << "Сообщение от " << currUser_->getName() << " в общий чат..." << std::endl;
	}
	else if (userNum > 0 && userNum < i)
	{
		Message message = Message(currUser_->getName(), users_.at(userNum - 1).getName(), text);
		messages_.push_back(message);
		std::cout << "Личное сообщение от " << currUser_->getName() << " пользователю " << users_.at(userNum - 1).getName() << "..." << std::endl;
	}
}
void Chat::showMessages()
{
	int count = 0;
	for (Message& message : messages_)
	{
		if (currUser_->getName() == message.getReceiver())
		{
			count++;
			std::cout << "Вы получили сообщение от " << message.getSender() << ": " << message.getMessage() << std::endl;
		}
	}
	if (count != 0)
	{
		std::cout << std::endl;
	}
	if (count == 0)
	{
		std::cout << "У вас нет непрочитанных сообщений..." << std::endl;
	}
}
std::shared_ptr<User> Chat::getUserByName(const std::string& name) const
{
	for (User user : users_)
	{
		if (name == user.getName())
		{
			return std::make_shared<User>(user);
		}
	}
	return nullptr;
}
std::shared_ptr<User> Chat::getUserByLogin(const std::string& login) const
{
	for (User user : users_)
	{
		if (login == user.getLogin())
		{
			return std::make_shared<User>(user);
		}
	}
	return nullptr;
}
std::shared_ptr<User> Chat::getCurrUser() const
{
	return currUser_;
}