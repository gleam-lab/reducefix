#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n-1);
    for(ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(ll i = 0; i < n-1; i++)
    {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    vector<ll> unmatched;
    ll i = 0, j = 0;
    while(i < n && j < n-1)
    {
        if(a[i] <= b[j])
        {
            i++;
            j++;
        }
        else
        {
            unmatched.push_back(a[i]);
            i++;
        }
    }
    while(i < n)
    {
        unmatched.push_back(a[i]);
        i++;
    }
    
    if(unmatched.size() > 1)
    {
        cout << -1 << endl;
    }
    else if(unmatched.size() == 1)
    {
        cout << unmatched[0] << endl;
    }
    else
    {
        // All toys are matched, but we still need to buy a new box.
        // The new box can be any size (since we don't need to place any toy in it),
        // but the problem might require x to be at least 1 (or smallest possible).
        // However, the problem states that he purchases one box of size x, so the minimal x is the smallest possible.
        // But since no toys are left, the box can be of any size, but to minimize, x can be 1.
        cout << 1 << endl;
    }
}

int main()
{
    solve();
    return 0;
}