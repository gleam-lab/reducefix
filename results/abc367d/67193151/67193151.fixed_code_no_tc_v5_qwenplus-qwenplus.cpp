#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;

int n, m;
ll sum, a[2*N], prefix[N*2];
map<int, int> freq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    
    // Read array and duplicate it for circular handling
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    // Compute prefix sums modulo m
    prefix[0] = 0;
    for(int i = 1; i < 2*n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
    }

    // Count subarrays with divisible sum using prefix mod counts
    freq[0] = 1;
    for(int i = 1; i < 2*n; i++) {
        // Remove the contribution of the prefix that is out of window
        if(i > n) {
            freq[prefix[i - n]]--;
        }
        
        // Add number of valid previous prefixes
        sum += freq[prefix[i]];
        
        // Add current prefix to frequency map
        if(i < n) {
            freq[prefix[i]]++;
        }
    }

    cout << sum;
    return 0;
}