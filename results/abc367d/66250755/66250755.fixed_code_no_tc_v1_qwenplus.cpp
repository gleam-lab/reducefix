#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(2 * n + 1);
    vector<int> t(m, 0);
    long long an = 0;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    vector<int> w(2 * n + 1, 0);
    
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i-1] + a[i]) % m;
        
        // For the first n elements, we don't have complete subarrays of length n yet
        if (i > n) {
            t[w[i - n]]--;
        }
        
        // Count how many times we've seen the same prefix sum
        an += t[w[i]];
        t[w[i]]++;
    }
    
    cout << an;
    return 0;
}