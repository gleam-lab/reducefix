#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, m, sum, cnt, a[N], d[N];
unordered_map<int, int> freq;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    freq[0] = 1;
    long long total = 0;
    
    for (int i = 1; i < 2 * n; i++) {
        if (i > n) {
            int prev_mod = d[i - n] % m;
            freq[prev_mod]--;
        }
        
        d[i] = d[i - 1] + a[i];
        int current_mod = d[i] % m;
        total += freq[current_mod];
        
        if (i < n) {
            freq[current_mod]++;
        }
    }
    
    cout << total << "\n";
    return 0;
}