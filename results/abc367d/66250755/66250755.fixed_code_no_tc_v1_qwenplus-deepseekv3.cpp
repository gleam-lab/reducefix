#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2*n + 1), w(2*n + 1, 0);
    vector<int> t(m, 0);
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    t[0] = 1;  // empty prefix sum
    long long an = 0;
    
    for(int i = 1; i <= 2*n; i++) {
        w[i] = (w[i-1] + a[i]) % m;
        
        if(i > n) {
            t[w[i - n]]--;
        }
        
        if(i >= n) {
            an += t[w[i]];
        }
        
        t[w[i]]++;
    }
    
    cout << an;
    return 0;
}