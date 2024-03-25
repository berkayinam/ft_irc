#include "Execute.hpp"

void Execute::part(int &fd, Server *server, std::string message){
	Execute exec;
	User *user = server->getUser(fd);
	std::string msg = "";
	std::string inc = "Once you";
	size_t position = message.find(inc);
	if (position != std::string::npos)
		message = ":ad";
	if (check::checkPart(message, user, server) == false)
		return ;
	std::string include = ":Once you ";

	std::string channelName = message.substr(0, message.find(" "));
	if (message.find(":") != std::string::npos)
		msg = message.substr(message.find(":") + 1);
	Channel *channel = server->getChannel(channelName);
	if (user == channel->getOwner())
		channel->cedeOwnership(server);
		
	channel->removeUser(user);
	user->removeChannel(channel);
	channel->removeOperator(user);
	if (msg != "")
		exec.execute(fd, server, "PRIVMSG " + channelName + " :" + msg);
	server->sender(fd, utils::getPrefix(user) + " PART " + channelName);
	std::vector<User*> users = channel->getUsers();
	for (std::vector<User*>::iterator it = users.begin(); it != users.end(); it++)
	{
		int toSend = (*it)->getFd();
		server->sender(toSend, utils::getPrefix(user) + " PART " + channelName);
	}
	if (channel->getUsers().size() == 0)
	{
		server->removeChannel(channel);
		delete channel;
		return ;
	}
}