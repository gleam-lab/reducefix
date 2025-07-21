#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 105;
int n;
int x;
int a[N], b[N], p[N], q[N];

int c[N];
bool check(int mid)
{
    for (int i = 1; i <= n; i++)
    {
        c[i] = LLONG_MAX;
        // Try all possible number of type A attacks from 0 to b[i]
        for (int j = 0; j <= b[i]; j++)
        {
            int damageFromA = j * a[i];
            int remainingHP = max(0LL, mid - damageFromA);
            int neededBAttacks = (remainingHP + b[i] - 1) / b[i]; // ceil division
            int cost = j * p[i] + neededBAttacks * q[i];
            c[i] = min(c[i], cost);
        }
        // Try all possible number of type B attacks from 0 to a[i]
        for (int j = 0; j <= a[i]; j++)
        {
            int damageFromB = j * b[i];
            int remainingHP = max(0LL, mid - damageFromB);
            int neededAAttacks = (remainingHP + a[i] - 1) / a[i]; // ceil division
            int cost = j * q[i] + neededAAttacks * p[i];
            c[i] = min(c[i], cost);
        }
    }

    int totalCost = 0;
    for (int i = 1; i <= n; i++)
    {
        totalCost += c[i];
    }

    return totalCost <= x;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> x;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int l = 0, r = 1e18;
    int answer = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            answer = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << answer;
    return 0;
}