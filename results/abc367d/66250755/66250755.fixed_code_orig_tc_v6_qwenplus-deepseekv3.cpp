#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    vector<ll> prefix(2 * n + 1, 0);
    map<ll, ll> freq;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
    }
    
    ll result = 0;
    freq[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        ll current = prefix[i];
        result += freq[current];
        freq[current]++;
    }
    
    freq.clear();
    freq[prefix[n]] = 1;
    
    for (int i = n + 1; i <= 2 * n; ++i) {
        ll current = prefix[i];
        result += freq[current];
        freq[current]++;
        ll to_remove = prefix[i - n];
        freq[to_remove]--;
        if (freq[to_remove] == 0) {
            freq.erase(to_remove);
        }
    }
    
    cout << result << "\n";
    return 0;
}