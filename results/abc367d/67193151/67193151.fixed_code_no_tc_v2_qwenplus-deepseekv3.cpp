#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m, a[N], prefix[N], freq[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }
    
    // Compute prefix sums mod m
    prefix[0] = 0;
    for (int i = 1; i <= n; ++i) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
    }
    
    long long res = 0;
    freq[0] = 1; // To account for subarrays starting at index 0
    
    for (int i = 1; i <= n; ++i) {
        res += freq[prefix[i]];
        freq[prefix[i]]++;
    }
    
    // Handle circular subarrays by considering the array as circular
    // The total sum of the array mod m
    int total_sum = prefix[n];
    if (total_sum == 0) res += n - 1; // All single-element subarrays are already counted
    
    // Reset frequency array for circular handling
    memset(freq, 0, sizeof(freq));
    prefix[0] = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        int idx = i > n ? i - n : i;
        prefix[i] = (prefix[i-1] + a[idx]) % m;
    }
    
    freq[0] = 1;
    long long circular_res = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        if (i > n) {
            freq[prefix[i - n]]--;
        }
        circular_res += freq[prefix[i]];
        if (i <= n) {
            freq[prefix[i]]++;
        }
    }
    
    // The correct answer is the maximum between res and circular_res
    cout << max(res, circular_res) << endl;
    return 0;
}