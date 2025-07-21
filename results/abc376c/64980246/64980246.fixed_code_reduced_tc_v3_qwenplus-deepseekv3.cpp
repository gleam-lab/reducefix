#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a)
        cin >> tt;
    for (auto &tt : b)
        cin >> tt;
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    vector<int> unmatched_toys;
    int i = 0, j = 0;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            unmatched_toys.push_back(a[i]);
            i++;
        }
    }
    while (i < n) {
        unmatched_toys.push_back(a[i]);
        i++;
    }
    
    if (unmatched_toys.empty()) {
        // All toys matched, but we still need to buy a box.
        // The new box can be of size 1 (or any size), but since we need to place one toy in it.
        // The minimum x is the smallest toy size, or any toy can be placed in a box of size >= toy's size.
        // However, since we have N-1 boxes and N toys, one toy must go into the new box.
        // So x must be at least the smallest toy's size, but since all other toys are matched,
        // the smallest x is the smallest toy's size.
        // But in sorted descending order, the smallest toy is a.back().
        cout << a.back() << endl;
    } else if (unmatched_toys.size() == 1) {
        cout << unmatched_toys[0] << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}