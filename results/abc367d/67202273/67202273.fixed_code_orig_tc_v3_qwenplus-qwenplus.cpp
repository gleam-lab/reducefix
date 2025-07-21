#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=4e5+10;

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // We'll use prefix sum mod m
    vector<ll> prefix_mod(n + 1, 0);
    for(ll i = 0; i < n; ++i) {
        prefix_mod[i + 1] = (prefix_mod[i] + a[i]) % m;
    }

    // Count frequencies of each mod value
    map<ll, ll> freq;
    freq[0] = 1;  // To count subarrays starting from index 0
    ll result = 0;
    ll[] cnt = new ll[m];  // For frequency counting

    // Initialize with the first prefix sum mod
    cnt[prefix_mod[0]]++;

    for (ll i = 1; i <= n; i++) {
        // We want to find number of previous prefixes such that
        // (current_prefix - previous_prefix) % m == 0
        // Which means current_prefix % m == previous_prefix % m
        result += cnt[prefix_mod[i]]++;
    }

    cout << result << endl;
    return 0;
}