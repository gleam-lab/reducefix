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
    for(int i = 1; i <= n; i++)
    {
        c[i] = LLONG_MAX;
        // Try all possible number of type A potions used
        for(int j = 0; j <= b[i]; j++)
        {
            // Number of monsters needed to kill with A: j
            // Remaining damage needed after using j A potions: mid - j * a[i]
            // Each B potion gives b[i] damage
            // So we need ceil((mid - j*a[i])/b[i]) B potions
            int remaining = mid - j * a[i];
            if (remaining <= 0) {
                c[i] = min(c[i], j * p[i]);
                continue;
            }
            int numB = (remaining + b[i] - 1) / b[i];
            c[i] = min(c[i], j * p[i] + numB * q[i]);
        }

        // Try all possible number of type B potions used
        for(int j = 0; j <= b[i]; j++)
        {
            // Same logic, swapping A and B
            int remaining = mid - j * b[i];
            if (remaining <= 0) {
                c[i] = min(c[i], j * q[i]);
                continue;
            }
            int numA = (remaining + a[i] - 1) / a[i];
            c[i] = min(c[i], j * q[i] + numA * p[i]);
        }
    }

    int totalCost = 0;
    for(int i = 1; i <= n; i++)
    {
        totalCost += c[i];
        if(totalCost > x) return false;
    }
    
    return true;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> x;

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    // Binary search bounds
    int l = 0, r = 1e18;
    int answer = 0;

    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
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