#ifndef _LEXAN_H_
#define _LEXAN_H_

#include <string>
#include <vector>
#include <iostream>

class Lexan{

private:
	bool startsWith(const std::string &target, const std::string &prefix);
	void skipWhitespaceAndComments(std::string &input);
	bool getToken(std::string &input, std::string &sym);

public:
	std::vector<std::string> tokens;
	Lexan(std::string input);
	Lexan(const Lexan &old);
	Lexan& operator = (const Lexan &obj);
	~Lexan();
	size_t size()const;
	bool empty();
	void clear();
	std::string operator[](size_t n)const;

};
std::ostream & operator <<(std::ostream &out, const Lexan &lexan);

#endif //_LEXAN_H_
