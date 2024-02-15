#include <iostream>
#include <string>
#include <algorithm>
#include<cstring>
unsigned long long modexp(unsigned long long x, unsigned long long y, unsigned long long N)
{
  if (y == 0) return 1;
  unsigned long long z = modexp(x, y / 2, N);
  if (y % 2 == 0)
    return (z*z) % N;
  else
    return ((x % N) *((z*z) % N)) % N;
}
int main()
{
unsigned long long a,b,c,k,l;
std::cin >> a >> b >> c;

std::cout << l << std::endl;
//2183717137951795
//ao9quu923uc32m90u023    
}
