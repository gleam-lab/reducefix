#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000;
int n;
int x;
int a[N], b[N], p[N], q[N];

int c[N];
bool check(int mid)
{
    bool feasible = true;
    for(int i = 1; i <= n; i++)
    {
        int cost1 = mid / a[i] * p[i];
        int cost2 = mid % a[i] * q[i];
        int remaining = mid - (mid / a[i]) * a[i];
        
        int cost3 = remaining / b[i] * q[i];
        int cost4 = remaining % b[i] * p[i];
        
        c[i] = cost1 + cost2 + cost3 + cost4;
        
        if (c[i] > x)
        {
            feasible = false;
            break;
        }
    }
    
    return feasible;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> p[i] >> b[i] >> q[i];
    }
    int l = 1, r = 1e18;
    while(l < r)
    {
        int mid = l + (r - l) / 2;
        if(check(mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << l;
    return 0;
}