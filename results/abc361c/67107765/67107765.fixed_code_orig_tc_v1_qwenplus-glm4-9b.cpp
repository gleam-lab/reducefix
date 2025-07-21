#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> num(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    sort(num.begin(), num.end());
    
    // We need to consider removing exactly K elements, not just half plus one.
    int remove_start = k / 2;
    int remove_end = n - 1 - (k - 1) / 2;
    
    // If after removing K elements only one element remains, the difference is zero.
    if (k < n - 1) {
        int ans = min(num[remove_end] - num[remove_start], num[remove_end - 1] - num[remove_start + 1]);
        cout << ans << endl;
    } else {
        cout << 0 << endl; // Only one element remains after deletion, difference is zero.
    }

    return 0;
}