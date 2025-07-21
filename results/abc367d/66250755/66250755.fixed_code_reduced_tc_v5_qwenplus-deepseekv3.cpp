#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    vector<int> w(2 * n + 2);
    unordered_map<int, int> t;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    w[0] = 0;
    int an = 0;
    
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
    
    cout << an << endl;
    return 0;
}