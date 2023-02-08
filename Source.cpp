#include "Chat.h"
#include <Windows.h>
int main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Chat chat;
	chat.createChat();
	while (chat.isChatWorking())
	{
		chat.chatOptions();

		while (chat.getCurrUser())
		{
			chat.userOptions();
		}
	}
	return 0;
}