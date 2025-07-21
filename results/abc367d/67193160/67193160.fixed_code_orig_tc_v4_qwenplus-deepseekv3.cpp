#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m, a[2*N];
long long prefix[2*N];
int freq[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    prefix[0] = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    
    long long res = 0;
    freq[0] = 1;
    
    for (int i = 1; i <= 2 * n; ++i) {
        if (i > n) {
            long long prev_mod = prefix[i - n] % m;
            if (prev_mod < 0) prev_mod += m;
            freq[prev_mod]--;
        }
        
        long long current_mod = prefix[i] % m;
        if (current_mod < 0) current_mod += m;
        res += freq[current_mod];
        
        if (i <= n) {
            freq[current_mod]++;
        }
    }
    
    cout << res << endl;
    return 0;
}