#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
ll n, m, sum;
ll a[2*N], prefix[2*N];
unordered_map<ll, ll> cnt;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];  // Duplicate array for circular property
    }
    
    // Precompute prefix sums
    for(int i = 1; i < 2 * n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
    }
    
    // We'll count how many times each mod value appears in prefix sums
    cnt[0] = 1;  // Important for subarrays starting from index 0
    
    for(int i = 1; i < 2 * n; i++) {
        sum += cnt[prefix[i]];
        if (i < n) {
            // Only count prefix sums within original array length
            cnt[prefix[i]]++;
        }
    }
    
    cout << sum;
    return 0;
}