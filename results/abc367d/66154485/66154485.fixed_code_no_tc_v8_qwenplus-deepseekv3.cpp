#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Handle circular array by concatenating it with itself
    vector<int> prefix(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; i++) {
        prefix[i+1] = (prefix[i] + arr[i % n]) % m;
    }
    
    long long ans = 0;
    unordered_map<int, int> count;
    count[0] = 1;  // for prefix[0]
    
    for (int i = 1; i <= 2 * n; i++) {
        // We only count subarrays of length <=n
        if (i > n) {
            int old_prefix = prefix[i - n];
            count[old_prefix]--;
            if (count[old_prefix] == 0) {
                count.erase(old_prefix);
            }
        }
        ans += count[prefix[i]];
        count[prefix[i]]++;
    }
    
    cout << ans;
    return 0;
}