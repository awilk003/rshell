#ifndef SEMI_HPP
#define SEMI_HPP
#include "cmdline.hpp"

class Semicolon : public Cmdline
{
	public:
		Semicolon(bool Left, Cmdline* Right);
		bool execute(vector<string> cmd);
	protected:
		bool Lchild;
		Cmdline* Rchild;
};

#endif
