#include <iostream>
#include <vector>
#include <algorithm>

int main ()
{
  int myints[] = {32,71,12,45,26,80,53,33};
    std::vector<int> myvector (myints, myints+8);

   std::sort (myvector.begin(), myvector.end());

  return 0;
}