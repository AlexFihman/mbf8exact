#ifndef MBF6_H
#define MBF6_H

#include <iostream>
 
using namespace std;

typedef unsigned long long ull;

struct ull2{ull x0; ull x1;};
 
extern ull* x0;
extern ull* x1;
extern ull* x2;
extern ull* x3;
extern ull* x4;
extern ull* x5;
extern ull* x6;

const int d0 = 2;
const int d1 = 3;
const int d2 = 6;
const int d3 = 20;
const int d4 = 168;
const int d5 = 7581;
const int d6 = 7828354;

const int fact6 = 720;
 
extern bool cmpx(const ull x1, const ull x2);

extern bool cmp(int i1, int i2, ull* x); 
 
extern void make(int csize, ull* x, ull* xout, int sz);
 
extern void make5();

#endif
