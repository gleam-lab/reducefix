#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long ans = 0;
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int start = 0; start < n; start++) {
        long long sum = 0;
        for (int len = 1; len < n; len++) {
            int idx = (start + len) % n;
            sum += arr[idx];
            if (sum % m == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}