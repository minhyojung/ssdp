#include "helper.h"

/*
#define MAKE_SINGLETON(classname)			\
private:									\
	classname() {}							\
public:										\
	static classname& get_instance()		\
	{										\
	static classname instance;				\
		return instance;					\
	}										\
public:										\
	classname(classname&) = delete;			\
	void operator=(classname&) = delete;	
	*/

class Cursor
{
	MAKE_SINGLETON(Cursor)
};

int main()
{
	Cursor& c = Cursor::get_instance();
}
