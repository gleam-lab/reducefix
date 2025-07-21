#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];

        // Sort arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // Calculate the result
        long long res = 0;
        for (int i = 0; i < k; ++i) {
            res += static_cast<long long>(a[n - 1 - i]) * b[i];
        }

        cout << res << '\n';
    }

    return 0;
}