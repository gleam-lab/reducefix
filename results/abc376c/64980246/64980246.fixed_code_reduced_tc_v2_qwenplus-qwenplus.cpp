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

    // We'll use binary search on the answer
    int left = 0, right = n - 1;
    int ans = -1;

    // Sort A in ascending order and B in ascending order too
    // Try to match the smallest possible box to the smallest toy that can fit in it
    // If we find that we need an extra box at any point, that's our candidate

    // Let's try a different approach: two pointers
    int i = 0, j = 0;
    int extra_box_needed = false;
    int min_x = -1;

    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            if (min_x == -1) {
                min_x = a[i];
            } else {
                // We already needed an extra box and now need another one
                cout << -1 << endl;
                return;
            }
            i++;
        }
    }

    // If there's one toy left unassigned, it must go to the extra box
    if (i < n) {
        if (min_x == -1) {
            min_x = a.back();  // The largest toy not matched directly
        } else {
            cout << -1 << endl;
            return;
        }
    }

    cout << min_x << endl;
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