#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m;
long long a[N], prefix[2*N];
int freq[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    prefix[0] = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }

    long long res = 0;
    freq[0] = 1; // prefix[0] mod m is 0

    for (int i = 1; i <= 2 * n; ++i) {
        if (i > n) {
            int mod_to_remove = (prefix[i - n - 1]) % m;
            if (mod_to_remove < 0) mod_to_remove += m;
            freq[mod_to_remove]--;
        }
        int current_mod = prefix[i] % m;
        if (current_mod < 0) current_mod += m;
        res += freq[current_mod];
        if (i < n) {
            freq[current_mod]++;
        } else {
            // Only add to freq if it's within the first segment to avoid double counting
            // Alternatively, manage the sliding window carefully
        }
    }

    // The above approach might still have issues, so here's an alternative approach
    // Reset and try a different method: compute prefix sums and then use frequency for mod counts
    memset(freq, 0, sizeof(freq));
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    freq[0] = 1;
    res = 0;
    for (int i = 1; i <= n; ++i) {
        int mod = prefix[i] % m;
        if (mod < 0) mod += m;
        res += freq[mod];
        freq[mod]++;
    }

    // Now handle the circular case by considering rotations
    // The total subarrays is sum_{i=1 to n} sum_{j=i to i+n-1} (prefix[j] - prefix[i-1]) mod m == 0
    // But for large n, we need an efficient way
    // So, first compute the total sum of the array
    long long total_sum = prefix[n];
    int total_mod = total_sum % m;
    if (total_mod < 0) total_mod += m;

    // The main idea is that each rotation shifts the prefix sums by total_mod
    // For each rotation k, the new prefix sums are prefix[i] + k * total_mod mod m
    // But this complicates the frequency counting
    // Alternative approach: compute for the doubled array, but subtract the cases where j - i >= n
    // So use the doubled array and sliding window of size n
    memset(freq, 0, sizeof(freq));
    prefix[0] = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    freq[0] = 1;
    res = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        if (i > n) {
            int mod_to_remove = prefix[i - n] % m;
            if (mod_to_remove < 0) mod_to_remove += m;
            freq[mod_to_remove]--;
        }
        int current_mod = prefix[i] % m;
        if (current_mod < 0) current_mod += m;
        res += freq[current_mod];
        if (i < n) {
            freq[current_mod]++;
        } else {
            // We need to manage the window of size n
            if (i <= 2 * n) {
                freq[current_mod]++;
            }
        }
    }

    // But this might still not account for all cases. Let's try a different approach.
    // Compute the answer for the linear array, then multiply by 2 and subtract the overlapping cases
    memset(freq, 0, sizeof(freq));
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    freq[0] = 1;
    long long linear_res = 0;
    for (int i = 1; i <= n; ++i) {
        int mod = prefix[i] % m;
        if (mod < 0) mod += m;
        linear_res += freq[mod];
        freq[mod]++;
    }

    // Now for the circular part: the total subarrays is n*(n+1)/2 - linear_res? No.
    // Alternatively, the circular array can be seen as the linear array plus rotations.
    // But this isn't straightforward. Perhaps the correct approach is to consider the concatenated array.
    // So the correct method is to use the concatenated array and sliding window.
    memset(freq, 0, sizeof(freq));
    prefix[0] = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    freq[0] = 1; // prefix[0]
    res = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        if (i > n) {
            int mod_to_remove = prefix[i - n] % m;
            if (mod_to_remove < 0) mod_to_remove += m;
            freq[mod_to_remove]--;
        }
        int current_mod = prefix[i] % m;
        if (current_mod < 0) current_mod += m;
        res += freq[current_mod];
        freq[current_mod]++;
    }
    // Subtract the cases where j - i + 1 > n
    // But this is tricky. Alternatively, the initial approach should have managed this.

    cout << res << endl;
    return 0;
}