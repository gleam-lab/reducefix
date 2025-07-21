#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<long long> a(2 * n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }

    // Prefix sum mod array
    vector<long long> prefix(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }

    // To count occurrences of each mod value
    vector<int> count_mod(m, 0);
    int result = 0;

    // We use sliding window to maintain only valid positions in the map
    for (int i = n; i >= 1; --i) {
        // When we move left pointer forward, remove outdated right-side values
        if (i + n <= 2 * n) {
            count_mod[prefix[i + n]]--;
        }
        
        // All prefixes that are i or later should be considered
        // So we add current prefix to count
        result += count_mod[prefix[i]];
        count_mod[prefix[i]]++;
    }

    cout << result << endl;
    return 0;
}