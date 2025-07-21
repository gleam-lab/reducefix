#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m, a[2 * N];
long long sum = 0;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    unordered_map<int, int> mod_count;
    mod_count[0] = 1;
    long long prefix = 0;
    
    for (int i = 0; i < 2 * n; ++i) {
        prefix += a[i];
        int mod = (prefix % m + m) % m;
        if (i >= n) {
            int old_mod = (prefix - a[i - n]) % m;
            old_mod = (old_mod + m) % m;
            mod_count[old_mod]--;
        }
        sum += mod_count[mod];
        if (i < n) {
            mod_count[mod]++;
        }
    }
    
    cout << sum;
    return 0;
}