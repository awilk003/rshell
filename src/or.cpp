#include "or.hpp"

Or::Or(bool Left, Cmdline* Right)
{
	Lchild = Left;
	Rchild = Right;	
}

//calls execute on Cmdline* Right and returns a bool value indicating whether the command was executed or not
bool Or::execute(vector<string> cmd)
{
	if (!Lchild)
	{
		//debugging statement
		//cout  << "HIT IF " << endl;
		return Rchild->execute(cmd);
	}
	else
	{
		//cout << "HIT ELSE" << endl;
		return true;
	}
} 

