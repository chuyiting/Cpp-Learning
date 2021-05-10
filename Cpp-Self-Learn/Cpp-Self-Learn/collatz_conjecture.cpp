//
//  collatz_conjecture.cpp
//  Cpp-Self-Learn
//
//  Created by Eddy Chu on 2021/5/10.
//

#include <stdio.h>
#include <iostream>

bool isOdd(long long x)
{
    return x % 2 != 0;
}

int collatz_conjecture()
{
    long long n = 0;
    using std::cin;
    using std::cout;
    
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        if (n % 2 != 0)  n = n * 3 + 1;
        else  n /= 2;
        cout << n << " ";
    }
    cout << "\n";
    
    return 0;
}
