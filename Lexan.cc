#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include "Lexan.h"

using namespace std;

Lexan::Lexan(string input){
	tokens = vector<string>();
	for(string token; getToken(input, token);){
              	tokens.push_back(token);
	}
	
}

Lexan::Lexan( const Lexan &old){
        tokens = old.tokens;
}

Lexan& Lexan::operator= (const Lexan &old){
        tokens = old.tokens;
        return *this;
}

Lexan::~Lexan(){
        vector<string>().swap(tokens);
}

bool Lexan::startsWith(const string &target, const string &prefix){
        for(size_t i = 0; i < prefix.size(); i++){
                if(tolower(target[i]) != tolower(prefix[i])){
                        return false;
		}
	}
        return true;
}

void Lexan::skipWhitespaceAndComments(string &input){
        int inCom = 0;
	while(!input.empty()){
		if(inCom){
			if(input[0] == '\n'){
				inCom = 0;
			}
			input.erase(0,1);
                }else if(isspace(input[0])){
                        input.erase(0, 1);
               }else if(input[0] == '#'){
           		inCom = 1;
			input.erase(0,1);  
                }else{
                        break;
		}
	}
}

bool Lexan::getToken(string &input, string &sym){
        static const string legalTokens[] = {
        "+=", "-=", "*=", "/=", "=", "≠", "≤", "≥", "<", ">",
        "if", "fi", "print", "return", "a", "b", "c", "d", "e", "f",
        "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r",
        "s", "t", "u", "v", "w", "x", "y", "z",};
        skipWhitespaceAndComments(input);
        if(input.empty()){
                return false;
	}
        size_t len = 0;
        while(isdigit(input[len]))
                len++;
	if(len > 15)
		throw runtime_error("Invalid input (number over 15 digits)");
        if(!len){
                for(string tok : legalTokens){
                        if(startsWith(input,tok)){
                                len = tok.size();
                                break;
                        }
		}
	}
        if(!len){
               throw runtime_error("Invalid input!");
        }
        sym.assign(input, 0, len);
        input.erase(0, len);
        for(char &c : sym){
                c = tolower(c);
	}
        return true;
}

size_t Lexan::size()const{
	return tokens.size();
}

bool Lexan::empty(){
	return (size() == 0);
}

void Lexan::clear(){
	tokens.clear();
}

std::string Lexan::operator[](size_t n)const{
	if(n >= size())
		throw out_of_range("That index is out of range for this token list!");
	return tokens[n];
}

ostream & operator <<(ostream &out, const Lexan &lexan){
	out << lexan.tokens[0];
	for(size_t i = 1; i < lexan.size(); i++)
		out << ',' << lexan.tokens[i];
	return out;
}

