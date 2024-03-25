#include "Execute.hpp"

void Execute::notice(int &fd, Server *server, std::string message){
	std::string toWho = message.substr(0, message.find(" "));
	std::string msg = message.substr(message.find(" ") + 1);

	int recvFd;

	if (server->getUser(toWho) != NULL)
	{
		recvFd = server->getUser(toWho)->getFd();
	}
	else
	{
		server->sender(fd, utils::getPrefix(server->getUser(fd)) + " 401 " + server->getUser(fd)->getNickname() + " " + toWho + " :No such nick/channel");
		return;
	}

	std::vector<Channel *> channels = server->getChannels();
	std::vector<Channel *>::iterator it = channels.begin();
	for (; it != channels.end(); it++)
	{
		std::vector<User *> users = (*it)->getUsers();
		std::vector<User *>::iterator it2 = users.begin();
		for (; it2 != users.end(); it2++)
		{
			if ((*it2)->getFd() == fd)
			{
				if (message.find("LAG") != std::string::npos)
					break;
				std::string channelName = (*it)->getName();
				std::string nickname = (*it2)->getNickname();
				server->sender(recvFd, utils::getPrefix(server->getUser(fd)) + " NOTICE " + channelName + " :" + msg);
			}
		}
	}
}