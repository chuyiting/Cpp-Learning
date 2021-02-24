//
//  permutation.cpp
//  Algorithm
//
//  Created by Eddy Chu on 2021/2/22.
//

#include "permutation.hpp"
#include <algorithm>


template<class BidirIt>
bool my_next_permutation(BidirIt first, BidirIt last) {
    if (first == last) return false;
    BidirIt i = last;
    if (--i == first) return false;
    
    while (true) {
        BidirIt j = i--; // move i for each iteration
        if (*i < *j) { // ascending
            BidirIt k = last;
            while(*--k < *i) {;}
            std::iter_swap(i, k); // swap with minimum number that is bigger than i
            std::reverse(j, last); // reset the rest
            return true;
        }
        if (i == first) { // all descending => reset
            std::reverse(first, last);
            return false;
        }
    }
}
