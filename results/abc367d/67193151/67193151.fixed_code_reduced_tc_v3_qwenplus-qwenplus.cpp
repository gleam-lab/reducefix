#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m;
long long sum; // Use long long to avoid overflow
int a[2 * N], prefix_mod[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[n + i] = a[i]; // Duplicate array for circular handling
    }

    // Initialize count with prefix sum mod m == 0 at index -1 (before start)
    cnt[0] = 1;

    long long curr_sum = 0;
    for (int i = 0; i < 2 * n; ++i) {
        curr_sum += a[i];
        int mod = ((curr_sum % m) + m) % m; // Ensure non-negative mod

        // Count how many times this mod has occurred before
        sum += cnt[mod];
        
        // Increment the count if we're in the first n elements
        if (i < n) {
            cnt[mod]++;
        } else {
            // Remove the contribution of the element that's now out of window
            int remove_mod = ((prefix_mod[i - n] % m) + m) % m;
            cnt[remove_mod]--;
        }
        
        prefix_mod[i] = curr_sum;
    }

    cout << sum << '\n';
    return 0;
}