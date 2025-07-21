#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), B(n - 1);
    for (auto &a : A)
        cin >> a;
    for (auto &b : B)
        cin >> b;
    
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    // Check if there is any toy that is smaller than all boxes
    bool valid = false;
    for (int i = 0; i < n && !valid; ++i) {
        valid = true;
        for (int j = 0; j < n - 1 && valid; ++j) {
            if (A[i] > B[j]) {
                valid = false;
                break;
            }
        }
    }

    if (!valid) {
        cout << -1 << endl;
        return;
    }

    // Try to find the minimum size of the box x
    ll x = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        // Check if toy i can be placed in box i (existing ones)
        bool canPlaceInExisting = true;
        for (int j = 0; j < n - 1 && canPlaceInExisting; ++j) {
            if (A[i] > B[j]) {
                canPlaceInExisting = false;
                break;
            }
        }
        if (canPlaceInExisting) {
            x = min(x, A[i]);
        }
    }

    cout << x << endl;
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