#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    
    vector<int> a(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    vector<int> prefix(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++) {
        prefix[i] = (prefix[i-1] + a[i]) % m;
    }
    
    long long ans = 0;
    map<int, int> count;
    
    // Process the first n elements separately to avoid double counting
    for (int i = 1; i <= n; i++) {
        if (i > n) {
            count[prefix[i - n]]--;
        }
        
        ans += count[prefix[i]];
        count[prefix[i]]++;
    }
    
    // Continue with the remaining elements
    for (int i = n + 1; i <= 2 * n; i++) {
        count[prefix[i - n]]--;
        ans += count[prefix[i]];
        count[prefix[i]]++;
    }
    
    cout << ans;
    return 0;
}