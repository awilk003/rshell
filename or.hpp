#include "cmdline.hpp"

class Or : public Cmdline
{
	public:
		Or(bool Left, Cmdline* Right);
		bool execute();
		bool isValid();
	protected:
		bool Lchild;
		Cmdline* Rchild;
};