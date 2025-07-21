#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    vector<int> prefix(2 * n + 1, 0);
    for(int i = 0; i < 2 * n; i++) {
        prefix[i + 1] = (prefix[i] + a[i]) % m;
    }
    
    unordered_map<int, int> freq;
    int res = 0;
    
    for(int i = 0; i <= 2 * n; i++) {
        if(i >= n) {
            res += freq[prefix[i]];
            freq[prefix[i - n]]--;
        }
        if(i < n) {
            freq[prefix[i]]++;
        }
    }
    
    cout << res << endl;
    return 0;
}