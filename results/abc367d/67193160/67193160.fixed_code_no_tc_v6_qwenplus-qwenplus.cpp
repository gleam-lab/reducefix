#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m;
long long a[2*N], prefix_sum[2*N];
map<int, int> freq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[n + i] = a[i];  // Duplicate array for circular subarrays
    }

    // Precompute prefix sums modulo m
    for(int i = 1; i < 2*n; ++i) {
        prefix_sum[i] = (prefix_sum[i-1] + a[i]) % m;
    }

    long long total = 0;
    freq[0] = 1;  // To count subarrays starting from index 0

    for(int i = 1; i < 2*n; ++i) {
        // Remove the contribution of the elements outside the window of size n
        if(i > n) {
            freq[prefix_sum[i - n]]--;
        }
        
        // Count valid subarrays ending at i
        total += freq[prefix_sum[i]];
        
        // Add current prefix to frequency map
        if(i < n) {
            freq[prefix_sum[i]]++;
        }
    }

    cout << total << "\n";
    return 0;
}