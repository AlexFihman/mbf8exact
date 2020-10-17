#include <cassert>
#include "quicklist.h"

quicklist::quicklist(int aSize)
{
	size = aSize;
	assert(aSize > 0);
	arr = new int[aSize];
	for (int i = 0; i<size;i++)
	{
		arr[i] = i;
	}
}

quicklist::~quicklist()
{
	delete[] arr;
}

int quicklist::next(int pos)
{
	assert(pos>=0);
	assert(pos<size);
	int retval = arr[pos];
	int i;
	for (i=pos;i<size-1;i++)
		arr[i] = arr[i+1];
	size--;
	return retval;
}
