#include <iostream>
#include "cmdline.hpp"
#include "cmd.hpp"
#include "semicolon.hpp"
#include "pound.hpp"
#include "or.hpp"
#include "and.hpp"
#include <vector>
#include <string>
#include <cstring>
#include <boost/tokenizer.hpp>
#include <locale>
using namespace boost;


//NOTE TO SELF: MAKE SURE TO MAKE THE DISTINCTION BETWEEN EXECUTE AND ISVALID, ISVALID CURRENTLY EXECUTES A FUNCTION

int main()
{
vector<char> substr;
string uInput;
//getline(cin, uInput);
//uInput = "ls ; ls || ls && ls # ls";
uInput = "ls&&ls ";
//char* newInput;
//newInput = strtok(uInput, " ");
tokenizer<> tok(uInput);
bool isValid = true;

for (string::iterator i = uInput.begin(); i != uInput.end(); i++)
{
	if ((*i) == ';' || (*i) == '|' || (*i) == '&')
	{
		substr.push_back((*i));
	}
}


for (unsigned i = 0; i < substr.size(); i++)
{
	if (substr.at(i) == substr.at(i+1))
	{
		substr.erase(substr.begin() + (i+1));
	}
}


cout << "substr: " << endl;
for (unsigned i = 0; i < substr.size(); i++)
{
	cout << substr.at(i) << " ";
}
cout << endl;

cout << "TOKENIZER" << endl;


string temp;
tokenizer<>::iterator i = tok.begin();
Cmd* first = new Cmd((*i));
first->execute((*i));
//isValid = first->isValid();
i++;


for (unsigned j = 0; j < substr.size(); j++)
{
	Cmd* uCmd = new Cmd((*i));
	switch(substr.at(j))
	{
		case ';':
		{
			cout << "HIT CASE SEMICOLON" << endl;
			Semicolon* sHolder = new Semicolon(isValid, uCmd);
			sHolder->execute((*i));
			// isValid = sHolder->isValid();
			delete sHolder;	
			break;
		}
		case '|':
		{
			cout << "HIT CASE OR" << endl;
			Or* oHolder = new Or(isValid, uCmd);
			oHolder->execute(*i);
			//isValid = oHolder->isValid();
			delete oHolder;
			break;
		}
		case '&':
		{
			cout << "HIT CASE AND" << endl;	
			And* aHolder = new And(isValid, uCmd);
			aHolder->execute((*i));
			//isValid = aHolder->isValid();
			delete aHolder;
			break;
		}
		default:
		{
			j = substr.size();
			break;		
		}
	}
	i++;
}

//Cmd* A = new Cmd(temp);
//A->execute(temp);



	return 0;
}





/*for (int i = 0; i < uInput.size(); i++)
{
	if (uInput.at(i) != ' ')
	{
		newInput.push_back(uInput.at(i));
		
	}
	if (uInput[i] == ';' || uInput[i] == '#')
 	{
		newInput.erase(newInput.end()-1);
		char* temp = new char[newInput.length()+1];
		temp = strcpy(temp, newInput.c_str());
		substr.push_back(temp);
		newInput.clear();
		newInput.push_back(uInput.at(i));	
	}
	else if ((uInput[i] == '|' && uInput[i+1] == '|') ||(uInput[i] == '&' && uInput[i+1] == '&'))
	{
		newInput.erase(newInput.end()-1);
	//	newInput.erase(newInput.end()-1);
		newInput.push_back(uInput.at(i+1));
		char* temp = new char[newInput.length()+1];
		temp = strcpy(temp, newInput.c_str());
		substr.push_back(temp);
		newInput.clear();
		newInput.push_back(uInput.at(i));
		newInput.push_back(uInput.at(i+1));
//		newInput.erase(newInput.end()-1);
		i++;
	}
}

char* temp = new char[newInput.length()+1];
temp = strcpy(temp, newInput.c_str());
substr.push_back(temp);
newInput.clear();		
	
substr.push_back(NULL);
*/

/*
	Cmd* A = new Cmd("ls");
	Cmd* B = new Cmd("asdf");
	Semicolon* C = new Semicolon(false,A);
	Pound* D = new Pound(false, B);
	Or* E = new Or(false, A);
	if (E->isValid)
	{
		cout << "GOOD " << endl;
	}
	else
	{
		cout << "ERROR" << endl;
	}
*/
