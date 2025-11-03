#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }

    vector<int> prefix(2 * n + 1, 0);
    map<int, int> count;
    count[0] = 1; // empty prefix has sum 0

    long long ans = 0;
    for (int i = 1; i < 2 * n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
        
        // Remove prefixes that are more than n elements away
        if (i > n) {
            int old_prefix = (prefix[i-n-1]) % m;
            count[old_prefix]--;
            if (count[old_prefix] == 0) {
                count.erase(old_prefix);
            }
        }
        
        // Count how many previous prefixes have same value (within last n positions)
        ans += count[prefix[i]];
        count[prefix[i]]++;
    }

    cout << ans << endl;
    return 0;
}