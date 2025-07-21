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

    // We will use two pointers to match toys to boxes
    int i = 0, j = 0;
    int unplaced_toys = n;

    while (i < n && j < n - 1)
    {
        if (a[i] <= b[j])
        {
            ++i;
            ++j;
            --unplaced_toys;
        }
        else
        {
            ++i; // This toy cannot fit in any available box, skip it
        }
    }

    if (unplaced_toys == 0)
    {
        cout << 1 << endl; // A minimal box of size 1 can be added but not used
        return;
    }

    // We need to find the smallest toy that couldn't be placed
    // Reset i and j
    i = 0, j = 0;
    vector<int> unplaced;

    while (i < n && j < n - 1)
    {
        if (a[i] <= b[j])
        {
            ++i;
            ++j;
        }
        else
        {
            unplaced.push_back(a[i]);
            ++i;
        }
    }

    // Any remaining toys are unplaced
    while (i < n)
    {
        unplaced.push_back(a[i]);
        ++i;
    }

    if (unplaced.size() > 1)
    {
        cout << -1 << endl;
        return;
    }

    // The only unplaced toy needs a box of at least its size
    cout << unplaced[0] << endl;
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