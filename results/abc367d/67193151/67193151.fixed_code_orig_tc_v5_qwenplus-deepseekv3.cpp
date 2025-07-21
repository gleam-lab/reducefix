#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m;
long long a[N], prefix[N];
map<long long, int> freq;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i]; // Handle circular array by doubling it
    }
    
    prefix[0] = 0;
    freq[0] = 1; // Initialize with prefix[0] mod m = 0
    long long res = 0;
    
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
        if (prefix[i] < 0) prefix[i] += m; // Ensure modulo is non-negative
        
        if (i > n) {
            // Remove the prefix[i - n] mod m from the frequency map
            long long prev_mod = prefix[i - n] % m;
            if (prev_mod < 0) prev_mod += m;
            freq[prev_mod]--;
        }
        
        res += freq[prefix[i]];
        if (i < n) {
            // Only add to frequency map if within the first n elements
            freq[prefix[i]]++;
        }
    }
    
    cout << res << endl;
    return 0;
}