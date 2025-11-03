#include<bits/stdc++.h>
using namespace std;

int n, m;
long long a[400005], w[400005];
map<long long, int> t;
long long an;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    w[0] = 0;
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i - 1] + a[i]) % m;
    }
    
    t.clear();
    t[0] = 1;
    
    for (int i = 1; i <= 2 * n; i++) {
        if (i > n) {
            t[w[i - n]]--;
        }
        
        if (i >= n) {
            an += t[w[i]];
        }
        
        t[w[i]]++;
    }
    
    cout << an;
    return 0;
}