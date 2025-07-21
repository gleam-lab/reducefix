#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, m, ans = 0;
    cin >> n >> m;
    
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    unordered_map<ll, int> prefix_sum_count;
    prefix_sum_count[0] = 1;
    ll current_sum = 0;
    
    for(int i = 0; i < n; ++i) {
        current_sum += a[i];
        current_sum %= m;
        
        // Number of subarrays ending at i with sum divisible by m
        ans += prefix_sum_count[current_sum];
        prefix_sum_count[current_sum]++;
    }
    
    cout << ans << endl;
    return 0;
}