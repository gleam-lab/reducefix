#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (auto &tt : a) cin >> tt;
    for (auto &tt : b) cin >> tt;
    
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    
    int x = -1;
    int i = 0, j = 0;
    while (i < n && j < n - 1) {
        if (a[i] <= b[j]) {
            i++;
            j++;
        } else {
            if (x == -1) {
                x = a[i];
                i++;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    if (x == -1) {
        x = a.back(); // All toys fit in existing boxes, so x can be any >= smallest toy
    } else {
        // Check if remaining toys can fit in remaining boxes
        while (i < n) {
            if (x == -1) {
                x = a[i];
                i++;
            } else {
                cout << -1 << endl;
                return;
            }
        }
    }
    
    // Now, verify that all toys can be placed with x included
    multiset<int> boxes(b.begin(), b.end());
    boxes.insert(x);
    
    vector<int> toys(a.begin(), a.end());
    sort(toys.begin(), toys.end(), greater<int>());
    
    bool possible = true;
    for (int toy : toys) {
        auto it = boxes.lower_bound(toy);
        if (it == boxes.end()) {
            possible = false;
            break;
        }
        boxes.erase(it);
    }
    
    if (possible) {
        cout << x << endl;
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