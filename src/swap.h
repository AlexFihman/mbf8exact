#ifndef SWAP_H
#define SWAP_H

#include <cassert>
#include "consts.h"

extern int** bittran;
extern ull** newpos;
extern void make_bittran();
extern void set_bit(ull& x, const int bitpos, const ull bitval);
extern ull get_bit(const ull x, const int bitpos);
extern ull transform(const ull x, const int tnum);

#endif
