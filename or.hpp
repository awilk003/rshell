#include "cmdline.hpp"

class Or : public Cmdline
{
	public:
		Or(bool Left, Cmdline* Right);
		bool execute(string cmd);
		//bool isValid(bool flag);
	protected:
		bool Lchild;
		Cmdline* Rchild;
};
