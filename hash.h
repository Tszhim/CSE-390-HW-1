#ifndef HASH_H
#define HASH_H

#include <utility> 
using namespace std;

/* 
    Hashing function for use in house class. 
    https://stackoverflow.com/questions/682438/hash-function-providing-unique-uint-from-an-integer-coordinate-pair
*/
struct pair_hash
{
    size_t operator() (const pair<int, int>& p) const 
    {
        return (p.first * 0x1f1f1f1f) ^ p.second;
    }
};

#endif