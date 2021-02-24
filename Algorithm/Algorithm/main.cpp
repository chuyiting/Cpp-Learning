//
//  main.cpp
//  Algorithm
//
//  Created by Eddy Chu on 2021/2/22.
//

#include <iostream>
#include <vector>
#include "permutation.hpp"
#include "permutation.cpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> arr{1, 2, 3, 4};
    do {
        for (auto const& i: arr) {
                std::cout << i << " ";
        }
        std::cout << '\n';
        
    } while(my_next_permutation(arr.begin(), arr.end()));
    return 0;
}
