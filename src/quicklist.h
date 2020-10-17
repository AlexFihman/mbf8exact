#ifndef QUICKLIST_H
#define QUICKLIST_H

class quicklist
{
public:
	int size;
	int* arr;
	quicklist(int aSize);
	~quicklist();
	int next(int pos);
};


#endif
