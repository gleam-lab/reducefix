#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 5;

int n, m;
ll sum;
int a[2*N], prefix_mod[2*N];
map<int, int> freq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    
    // Read array and duplicate it for circular handling
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    // Precompute prefix sums modulo m
    for(int i = 1; i <= 2*n; i++) {
        prefix_mod[i] = (prefix_mod[i-1] + a[i]) % m;
    }

    // We want to count number of pairs (i,j) such that 
    // (prefix[j] - prefix[i]) % m == 0 => prefix[j] % m == prefix[i] % m

    // Start with prefix[0] = 0
    freq[0] = 1;
    
    for(int i = 1; i <= 2*n; i++) {
        // Exclude elements outside the current window of size <= n
        if(i > n) {
            freq[prefix_mod[i - n]]--;
        }
        
        // Count how many times this mod has been seen before
        sum += freq[prefix_mod[i]];
        
        // Add current prefix mod to frequency map
        freq[prefix_mod[i]]++;
    }

    // Subtract the extra counts from the initial 0
    cout << sum - n << "\n";
    return 0;
}