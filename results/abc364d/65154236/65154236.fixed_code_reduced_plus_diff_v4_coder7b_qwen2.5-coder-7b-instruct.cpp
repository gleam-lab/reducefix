#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;

void preprocess() {
    sort(a.begin(), a.end());
}

int find_kth_closest(int x, int k) {
    auto it = lower_bound(a.begin(), a.end(), x);
    int pos = it - a.begin();
    int cnt = 0;
    
    // Count how many points are less than or equal to x
    while (pos > 0 && a[pos - 1] == a[pos]) {
        --pos;
    }
    cnt += pos;
    
    // Check if there are enough points to reach the k-th smallest distance
    if (cnt < k) {
        return -1; // This case should not happen with valid input but added for completeness
    }
    
    // Return the k-th smallest distance
    return a[k - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    preprocess();

    while (q--) {
        int bx, kj;
        cin >> bx >> kj;
        int result = find_kth_closest(bx, kj);
        cout << result << '\n';
    }

    return 0;
}