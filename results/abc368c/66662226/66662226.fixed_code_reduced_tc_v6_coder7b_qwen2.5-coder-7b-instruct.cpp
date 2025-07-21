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
    ll ans = 0;
    while (true)
    {
        bool any_alive = false;
        rep(i, n)
        {
            if (h[i] > 0)
            {
                any_alive = true;
                if ((ans + 1) % 3 == 0)
                {
                    h[i] -= 3;
                }
                else
                {
                    h[i]--;
                }
            }
        }
        ans++;
        if (!any_alive)
        {
            break;
        }
    }
    cout << ans - 1 << endl;
}