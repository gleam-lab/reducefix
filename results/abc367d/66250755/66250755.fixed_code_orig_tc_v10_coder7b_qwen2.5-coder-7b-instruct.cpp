#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }
    
    vector<int> prefix_sum(2 * n + 1);
    vector<int> count(m, 0);
    
    long long result = 0;
    for(int i = 0; i < 2 * n; ++i) {
        prefix_sum[i + 1] = (prefix_sum[i] + a[i % n]) % m;
        
        if(i >= n) {
            result += count[(prefix_sum[i + 1] - prefix_sum[i - n + 1] + m) % m];
            result %= MOD;
        }
        
        count[prefix_sum[i + 1]]++;
    }
    
    cout << result << endl;
    return 0;
}