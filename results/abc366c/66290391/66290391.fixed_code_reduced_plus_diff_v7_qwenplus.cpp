#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int q;
    cin >> q;
    map<int, int> ballCount;
    rep(i, q)
    {
        int type, x;
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            ballCount[x]++;
        }
        else if (type == 2)
        {
            cin >> x;
            ballCount[x]--;
            if (ballCount[x] == 0)
            {
                ballCount.erase(x);
            }
        }
        else if (type == 3)
        {
            cout << ballCount.size() << endl;
        }
    }
}