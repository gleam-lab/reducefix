#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    vector<int> w(2 * n + 1, 0);
    unordered_map<int, int> t;
    
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    w[0] = 0;
    for(int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i - 1] + a[i]) % m;
    }
    
    int an = 0;
    t[0] = 1;  // To account for prefix sums
    
    for(int i = 1; i <= 2 * n; i++) {
        if(i > n) {
            int prev = w[i - n - 1];
            t[prev]--;
            if(t[prev] == 0) t.erase(prev);
        }
        an += t[w[i]];
        t[w[i]]++;
    }
    
    cout << an;
    return 0;
}