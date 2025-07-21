#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int left = 0, right = 0;
    int x = -1;
    
    while (left < n && right < n - 1)
    {
        if (a[left] <= b[right])
        {
            ++left;
            ++right;
        }
        else
        {
            if (x == -1)
                x = a[left];
            else
            {
                cout << -1 << endl;
                return;
            }
            ++left;
        }
    }
    
    // If we still have toys left, they must go to the new box
    while (left < n)
    {
        if (x == -1)
            x = a[left];
        else
        {
            cout << -1 << endl;
            return;
        }
        ++left;
    }

    cout << x << endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}