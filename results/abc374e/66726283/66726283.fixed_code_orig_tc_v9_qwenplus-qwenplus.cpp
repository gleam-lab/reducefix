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
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int min_cost = numeric_limits<int>::max();
        // Try all possible number of type A attacks, rest are type B
        for (int j = 0; j <= b[i]; j++)
        {
            // j A-type attacks, need to cover damage with (mid - j * a[i])
            int remaining_damage = mid - j * a[i];
            if (remaining_damage <= 0)
                remaining_damage = 0;
            int required_b_attacks = (remaining_damage + b[i] - 1) / b[i];
            int cost = j * p[i] + required_b_attacks * q[i];
            min_cost = min(min_cost, cost);
        }
        for (int j = 0; j <= a[i]; j++)
        {
            // j B-type attacks, need to cover damage with (mid - j * b[i])
            int remaining_damage = mid - j * b[i];
            if (remaining_damage <= 0)
                remaining_damage = 0;
            int required_a_attacks = (remaining_damage + a[i] - 1) / a[i];
            int cost = j * q[i] + required_a_attacks * p[i];
            min_cost = min(min_cost, cost);
        }
        ans += min_cost;
        if (ans > x)
            return false;
    }
    return true;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    int l = 0;
    int r = 1e18;
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