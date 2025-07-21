#include <bits/stdc++.h>
using namespace std;

int main()
{
  unordered_map<int, int> countMap;
  int Q;
  cin >> Q;
  
  for (int i = 0; i < Q; i++)
  {
    int type;
    cin >> type;

    if (type == 1)
    {
      int x;
      cin >> x;
      if (countMap[x] == 0)
      {
        countMap[x] = 1;
      }
      else
      {
        countMap[x]++;
      }
    }
    else if (type == 2)
    {
      int x;
      cin >> x;
      countMap[x]--;
    }
    else if (type == 3)
    {
      // Count number of keys with positive count
      cout << countMap.size() << endl;
    }
  }

  return 0;
}