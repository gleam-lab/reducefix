#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end());
        
        int max_a = a[k - 1];
        int sum_b = 0;
        for (int i = 0; i < k; ++i) sum_b += b[i];
        
        cout << max_a * sum_b << "\n";
    }

    return 0;
}