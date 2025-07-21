#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m;
long long sum;
int a[N << 1], prefix_mod[N << 1];
map<int, int> mod_count;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    // Compute prefix sums modulo m for the doubled array
    prefix_mod[0] = 0;
    for (int i = 1; i < (n << 1); ++i) {
        prefix_mod[i] = (prefix_mod[i - 1] + a[i]) % m;
    }

    // We'll use a sliding window of size n to count valid subarrays
    mod_count[0] = 1;  // To count subarrays starting from index 0

    for (int i = 1; i < (n << 1); ++i) {
        // When i >= n, remove the count that's now out of the window
        if (i >= n) {
            mod_count[prefix_mod[i - n]]--;
        }
        
        // Count subarrays ending at i with start in [max(1, i-n+1), i]
        sum += mod_count[prefix_mod[i]];
        
        // Add current prefix to map only if it's within first n elements
        if (i < n) {
            mod_count[prefix_mod[i]]++;
        }
    }

    cout << sum << endl;
    return 0;
}