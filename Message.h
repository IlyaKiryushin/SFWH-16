#pragma once
#include <string>
class Message
{
	const std::string sender_;
	const std::string receiver_;
	const std::string message_;
public:
	Message(const std::string&, const std::string&, const std::string&);
	const std::string& getSender() const;
	const std::string& getReceiver() const;
	const std::string& getMessage() const;
};