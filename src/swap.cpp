#include "swap.h"
#include "consts.h"
#include "quicklist.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int** bittran;
ull** newpos;

void set_bit(ull& x, const int bitpos, const ull bitval)
{
	x = x | ((bitval) << bitpos);
}

ull get_bit(const ull x, const int bitpos)
{
	return (x >> bitpos) & 1ll;
}

void make_bittran()
{
	int i, ii, j, k;

	bittran = new int*[nf];
	for (i=0;i<nf;i++)
		bittran[i] = new int[n];

	newpos = new ull*[nf];
	for (i=0;i<nf;i++)
		newpos[i] = new ull[1<<n];

	for (i=0;i<nf;i++)
	{
		quicklist xx(n);
		ii = i;
		for (j=n;j>0;j--)
		{
			k = ii % j;
			ii = ii / j;
			bittran[i][n-j] = xx.next(k);
			//cout << bittran[i][n-j];
		}
		//cout << endl;
	}

	for (i=0;i<nf;i++)
	{
		for (j=0;j<(1<<n);j++)
		{
			ull rr = 0ll;

			for (k=0; k<n; k++)
			{
			   ull bit = get_bit(j,k);
			   set_bit(rr,bittran[i][k],bit);
			}
			newpos[i][j] = rr;
			//std::cout << i << "\t" << j <<"\t" << newpos[i][j] << endl;
		}
	}

}

ull transform(const ull x, const int tnum)
{
	ull res = 0LL;
	int i;
	for (i=0; i< (1 << n); i++)
	{
		set_bit(res, (int)newpos[tnum][i], get_bit(x,i));
	}
	return res;
}
