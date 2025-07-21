#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> h(n);
    ll t = 0;
    rep(i, n)
    {
        cin >> h[i];
    }
    while (true)
    {
        bool flag = false;
        rep(i, n)
        {
            if (h[i] > 0)
            {
                flag = true;
                t++;
                if (t % 3 == 0)
                {
                    h[i] -= 3;
                }
                else
                {
                    h[i]--;
                }
            }
        }
        if (!flag)
        {
            break;
        }
    }
    cout << t << endl;
}