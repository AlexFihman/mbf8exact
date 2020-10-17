//============================================================================
// Name        : mbf8exact.cpp
// Author      : Alex Fihman
// Version     :
// Copyright   : (C)2020
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>

#include "swap.h"
#include "mbf6.h"

typedef __int128 int128_t;
typedef unsigned __int128 uint128_t;

int print_uint128(uint128_t n) {
  if (n == 0)  return printf("0\n");

  char str[40] = {0}; // log10(1 << 128) + '\0'
  char *s = str + sizeof(str) - 1; // start at the end
  while (n != 0) {
    if (s == str) return -1; // never happens

    *--s = "0123456789"[n % 10]; // save last digit
    n /= 10;                     // drop it
  }
  return printf("%s\n", s);
}

int find(ull f) {
	int start = 0;
	if (x6[start] == f)
		return start;
	int end = d6-1;
	if (x6[end] == f)
		return end;

	int mid = (start + end) / 2;
	while (x6[mid] != f) {
		if (x6[mid] <f)
			start = mid;
		else
			end = mid;
		mid = (start + end) / 2;
	}
	return mid;
}

int main() {
	make5();
	make_bittran();


	int* symMinFuncs = new int[16353];
	int* symMinFuncs_syms = new int[16353];
	int* minf = new int[d6];

	for (int n=0;n<d6;n++) {
		minf[n] = -1;
	}

	int cnt = 0;

	for (int n=0;n<d6;n++) {
		ull xt = x6[n];
		int syms = 1;
		bool isSym = true;
		for (int i=1;i<fact6;i++) {
			ull xtr = transform(xt,i);
			if (xtr < xt) {
				isSym = false;
				break;
			}
			if (xtr == xt)
				syms++;
		}
		if (isSym) {
			std::cout << n << "\t" << syms << std::endl;
			symMinFuncs[cnt] = n;
			symMinFuncs_syms[cnt] = fact6 / syms;
			minf[n] = cnt;
			cnt++;
		}
	}

	std::cout << cnt << std::endl;

	for (int fn=0;fn<16353;fn++) {
		std::cout << fn << std::endl;
		ull fxn = x6[symMinFuncs[fn]];

		minf[symMinFuncs[fn]] = fn;
		for (int i=1;i<fact6;i++) {
			ull fxn_t = transform(fxn,i);
			int fno = find(fxn_t);
			minf[fno] = fn;
		}
	}

	int* nfh = new int[16353];
	int* nfl = new int[16353];

	for (int fn=0;fn<16353;fn++){
		nfh[fn] = 0;
		nfl[fn] = 0;
	}

	for (int fn=0;fn<16353;fn++) {
		ull fxn = x6[symMinFuncs[fn]];
		for (int i=0;i<d6;i++) {
			ull fi = x6[i];
			if ((fxn & fi) == fi) nfh[fn]++;
			if ((fxn | fi) == fi) nfl[fn]++;
		}
		std::cout << fn << std::endl;
	}

	std::cout << "done nfh/nfl" << std::endl;


	uint128_t s = 0;
	for (int f1 = 0; f1 < 16353; f1++) {
		std::cout << f1 << std::endl;
		ull fn1 = x6[symMinFuncs[f1]];
		for (int f2=0;f2<d6;f2++){
			ull fn2 = x6[f2];
			ull f_or = fn1 | fn2;
			int fn_or = find(f_or);
			ull f_and = fn1 & fn2;
			int fn_and = find(f_and);
			int min_or = minf[fn_or];
			int min_and = minf[fn_and];
			uint64_t v = symMinFuncs_syms[f1];
			v *= nfh[min_and];
			v *= nfl[min_or];
			s += v;
		}
		print_uint128(s);
		std::cout << std::endl;
	}

	print_uint128(s);

	return 0;
}
