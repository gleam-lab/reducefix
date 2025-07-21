#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n)
    {
        cin >> h[i];
    }
    ll t = 0;
    while (true)
    {
        bool any_alive = false;
        rep(i, n)
        {
            if (h[i] > 0)
            {
                any_alive = true;
                break;
            }
        }
        if (!any_alive)
        {
            break;
        }
        t++;
        for (auto &x : h)
        {
            if (x > 0)
            {
                if ((t - 1) % 3 == 2)
                {
                    x -= 3;
                }
                else
                {
                    x--;
                }
            }
        }
    }
    cout << t << endl;
}