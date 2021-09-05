/*The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?*/
#include <bits/stdc++.h>
#include <iostream>
#include <list>
using namespace std;

//Sieve of Eratosthenes (creating a list with primes)
list <int> eSieve(int limit)
{
    list <int> primeList;
    bool prime [limit + 1];
    memset (prime, true, sizeof(prime));

    for (int i = 2; i*i <= limit; i++)
    {
        if (prime[i] == true)
        {
            for (int j = i * i; j <= limit; j += i)
            {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i <= limit ; i++)
    {
        if (prime[i])
        {
            primeList.push_front(i);
        }
    }
    return primeList;
}



int NumberOfPrimeFactors(int number, list <int> primeList)
{
    int nod = 0, n = number;
    bool pf;

    for (int x = 0; x <= primeList.size(); x++)
    {
        int prime = primeList.back();
        if (prime * prime > number)
        {
            nod++;
            return nod;
        }

        pf = false;

        while (n % prime == 0)
        {
            pf = true;
            n /= prime;
        }

        if (pf)
        {
            nod++;
        }

        if (n == 1)
        {
            return nod;
        }
        primeList.pop_back();
    }
    return nod;
}


int main()
{
    list <int> primeList = eSieve(20000);
    int counter = 0, i;
    for ( i = 210; counter < 4; i++)
    {
        if(NumberOfPrimeFactors(i, primeList) == 4)
        {
            counter++;
        }
        else
        {
            counter = 0;
        }
    }
    cout << i - 4;
    return 0;
}
