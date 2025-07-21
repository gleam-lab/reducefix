#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    ll ans = 0;
    int t = 0;
    bool changed = true;
    while (changed)
    {
        changed = false;
        t++;
        rep(i, n)
        {
            if (a[i] > 0)
            {
                changed = true;
                if (t % 3 == 0)
                {
                    a[i] -= 3;
                }
                else
                {
                    a[i]--;
                }
            }
        }
        if (changed)
        {
            ans++;
        }
    }
    cout << ans << endl;
}