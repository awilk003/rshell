#ifndef _TEST_H_
#define _TEST_H_

#include "cmdline.hpp"

class Test : public Cmdline
{
public:
	Test();
	bool execute(string path);
};

#endif
