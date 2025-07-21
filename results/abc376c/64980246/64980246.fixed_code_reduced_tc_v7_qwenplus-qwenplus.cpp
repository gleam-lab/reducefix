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

    multiset<int> boxes;
    int j = 0;
    int x = -1;

    // Try to assign smallest toys to smallest boxes possible
    for (int i = 0; i < n; ++i) {
        // While we have boxes smaller than current toy, move to next box
        while (j < n - 1 && b[j] < a[i]) {
            boxes.insert(b[j]);
            ++j;
        }

        if (j < n - 1) {
            // We can use box b[j]
            ++j;
        } else if (!boxes.empty()) {
            // Use the smallest available box from our set
            boxes.erase(boxes.begin());
        } else {
            // No suitable box found, this toy must be placed in new box
            if (x == -1 || a[i] < x) {
                x = a[i];
            } else {
                // If we already chose a bigger box, we cannot satisfy requirements
                cout << -1 << endl;
                return;
            }
        }
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