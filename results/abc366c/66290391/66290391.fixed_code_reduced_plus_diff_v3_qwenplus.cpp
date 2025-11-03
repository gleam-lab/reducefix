#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int q;
    cin >> q;
    map<int, int> freq;
    rep(i, q)
    {
        int type, x;
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            freq[x]++;
        }
        else if (type == 2)
        {
            cin >> x;
            freq[x]--;
            if (freq[x] == 0)
                freq.erase(x);
        }
        else if (type == 3)
        {
            cout << freq.size() << endl;
        }
    }
}