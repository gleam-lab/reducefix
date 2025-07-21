#include<bits/stdc++.h>
using namespace std;
int n, m, a[400005], w[400005], an;
unordered_map<int, int> t;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    w[0] = 0;
    t[0] = 1;
    
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i - 1] + a[i]) % m;
        
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