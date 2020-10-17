#include "mbf6.h"

ull* x0 = new ull[d0];
ull* x1 = new ull[d1];
ull* x2 = new ull[d2];
ull* x3 = new ull[d3];
ull* x4 = new ull[d4];
ull* x5 = new ull[d5];
ull* x6 = new ull[d6];

bool cmpx(const ull x1, const ull x2)
{
	return (x1 & ~x2) == 0;
}

bool cmp(int i1, int i2, ull* x)
{
  return (x[i1] & ~x[i2])==0;
}

void make(int csize, ull* x, ull* xout, int sz)
{
  int i,j;
  int cnt = 0;
  for (i=0;i<csize;i++)
  for (j=i;j<csize;j++)
  if (cmp(i,j,x))
  {
     ull tmp = (x[i] << sz) | x[j];
     xout[cnt] = tmp;
     cnt++;
  }
  cout << "size " << sz << " is: " << cnt << endl;
}

void make5()
{
  x0[0] = 0;
  x0[1] = 1;
  make(2, x0, x1, 1);
  make(3, x1, x2, 2);
  make(6, x2, x3, 4);
  make(20, x3, x4, 8);
  make(168, x4, x5, 16);
  make(7581, x5, x6, 32);  
}
