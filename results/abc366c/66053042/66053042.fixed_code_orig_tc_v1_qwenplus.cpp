#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<int, int> m;

  int Q;
  cin >> Q;
  int n = 0;
  for (int i = 0; i < Q; i++)
  {
    int type;
    cin >> type;

    if (type == 1)
    {
      int x;
      cin >> x;

      if (m.find(x) != m.end())
      {
        m[x]++;
      }
      else
      {
        m.emplace(x, 1);
        n++;
      }
    }
    else if (type == 2)
    {
      int x;
      cin >> x;
      m[x]--;
      if (m[x] == 0) {
          m.erase(x);
          n--;
      }
    }
    else if (type == 3)
    {
      cout << n << endl;
    }
  }
}