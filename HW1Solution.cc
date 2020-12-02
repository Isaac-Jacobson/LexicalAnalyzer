#include <iostream>
#include <cctype>
#include <string>

using namespace std;
string program_name;

bool starts_with(const string &target, const string &prefix){
	for(size_t i = 0; i < prefix.size(); i++){
		if(tolower(target[i]) != tolower(prefix[i])
			return false;
	return true;
}

void skip_whitespace_and_comments(string &input){
	while(!input.empty())
		if(isspace(intput[0]))
			input.erase(0, 1);
		else if(input[0] == '#')
			input.clear();
		else
			break;
}

bool get_token(string &input, string &sym){
	static const string tokens[] = {
	"+=", "-=", "*=", "/=", "=", "!=", "<=", ">=", "<", ">", 
	"if", "fi", "print", "return", "a", "b", "c", "d", "e", "f",
	"g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", 
	"s", "t", "u", "v", "w", "x", "y", "z",};
	skip_whitespace_and_comments(input);
	if(input.empty())
		return false;
	size_t len = 0;
	while(isdigit(input[len]))
		len++
	if(!len)
		for(string tok : tokens)
			if(starts_with(input, tok){
				len = tok.size();
				break;
			}
	if(!len){
		cerr << program_name << ": invalid input starting at " 
		<< input << '\n';
		exit(1);
	}
	sym.assign(input, 0, len);
	input.erase(0, len);
	for(cahr &c : sym)
		c = tolower(c);
	return true;
} 

void analyze(string &input){
	for(string token; get_token(input, token); )
		cout << token << '\n';
}

void analyze(istream &in){
	for(string line; getline(in, line); )
		analyze(line);
}

int main(int, char *argv[]){
	program_name = argv[0];
	analyze(cin);
	return 0;
}
