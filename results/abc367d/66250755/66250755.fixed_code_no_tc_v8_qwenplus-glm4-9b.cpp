#include<bits/stdc++.h>
using namespace std;
const int N = 400005;

int n, m, a[N], t[N], an = 0, w[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    for (int i = 1; i < 2 * n; ++i) {
        w[i] = (w[i - 1] + a[i]) % m;
        
        if (i >= n) {
            an += t[w[i]];
        }
        
        if (i >= n) {
            t[w[i]]++;
            if (i > n) {
                t[w[i - n]]--;
            }
        }
    }
    
    cout << an;
    return 0;
}