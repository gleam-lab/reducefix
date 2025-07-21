#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n - 1; i++) cin >> b[i];
    
    // Combine the sizes into one vector and sort it
    vector<int> sizes(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++) sizes.push_back(b[i]);
    sort(sizes.begin(), sizes.end(), greater<int>());

    // Find the minimum x that can be used to place all toys in boxes
    int x = 1;
    while (true) {
        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (sizes[i] < x) {
                possible = false;
                break;
            }
        }
        if (possible) break;
        x++;
    }

    // If x is larger than the largest toy, it's impossible to place all toys
    if (x > a[0]) {
        cout << -1 << endl;
    } else {
        cout << x << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}