
//https://youtu.be/gM5uNcgn2NQ?si=KNUgJH0_yYXUJLdf&t=376
//Yeah not sure what I was expecting here. The results are almost the same as Matt's.
//For some reason our % primes are slightly different? But I'm not interested enough to find out why

#include <iostream>
#include <math.h>
//#include <unordered_set>
#include <string>
using namespace std;

unsigned int cab(int n, int c = 41)
{
    return n * n - n + c;
};

bool isPrime(unsigned int n/*, unordered_set<int> &primes*/)
{
    if (n == 1)
        return false;
    //if (primes.find(n) != primes.end())
    //    return true;
    
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    //primes.insert(n);
    return true;
};

int main()
{
    int amt;
    cin >> amt;
    //unordered_set<int> primes = {}; //Seems to be slightly slower with the set? At least when going up to 5000. Might be better at much higher numbers
    float pp = 0;
    for (int i = 1; i <= amt; i++){
        for (int j = 0; j < i; j++)
            if (isPrime(cab(j, i)/*, primes*/))
                pp += 1;
        pp = pp/i;
        if (pp >= 0.5f)
            cout << i << " : " << pp << endl;     
        pp = 0;   
        }
        
}