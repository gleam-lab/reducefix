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

    // We'll use a multiset to efficiently find matching boxes for toys
    multiset<int> box_sizes;
    int j = 0; // Pointer for B

    // Try to assign boxes to toys from smallest to largest
    for (int i = 0; i < n; ++i) {
        // Add all boxes smaller than current toy to the set
        while (j < n-1 && b[j] < a[i]) {
            box_sizes.insert(b[j]);
            j++;
        }
        
        // If we have a box that can fit this toy, use it
        if (!box_sizes.empty()) {
            box_sizes.erase(box_sizes.begin()); // Use the smallest available box
        } else {
            // No box can fit this toy, so we need to buy one
            cout << a[i] << endl;
            return;
        }
    }

    // If we've successfully matched all toys with boxes, no need to buy one
    cout << -1 << endl;
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