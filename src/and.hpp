#ifndef _AND_HPP
#define _AND_HPP

#include "cmdline.hpp"

class And : public Cmdline
{
	public:
		And(bool Left, Cmdline* Right);
		bool execute(vector<string> cmd);
	//	bool isValid();
	protected:
		bool Lchild;
		Cmdline* Rchild;
};
#endif
