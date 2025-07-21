#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m,k,sum,cnt,a[N],b[N],c[N];
bool check(int x)
{
    int needed = a[x] + (n - m) * (x + 1) - c[x - 1];
    if (needed <= k) return true;
    return false;
}
int findMinVotes(int x)
{
    int low = 0, high = k + 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (check(mid))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
signed main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m >> k;
    sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    vector<int> indices(n + 1);
    for (int i = 1; i <= n; i++)
    {
        indices[a[i]] = i;
    }
    sort(indices.begin() + 1, indices.begin() + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        int current_index = indices[i];
        c[i] = c[i - 1] + a[current_index];
    }
    for (int i = 1; i <= n; i++)
    {
        int votes_needed = findMinVotes(i);
        if (votes_needed > k - sum)
            cout << -1 << " ";
        else
            cout << votes_needed - a[i] << " ";
    }
    return 0;
}