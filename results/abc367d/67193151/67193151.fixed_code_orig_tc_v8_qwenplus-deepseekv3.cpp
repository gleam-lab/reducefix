#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n * 2);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    vector<int> prefix(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    
    unordered_map<int, int> mod_count;
    mod_count[0] = 1;
    long long result = 0;
    
    for (int i = 1; i <= 2 * n; ++i) {
        int mod = (prefix[i] % m + m) % m;
        if (i > n) {
            int prev_mod = (prefix[i - n] % m + m) % m;
            mod_count[prev_mod]--;
        }
        result += mod_count[mod];
        if (i < n) {
            mod_count[mod]++;
        } else {
            mod_count[mod]++;
        }
    }
    
    cout << result << endl;
    return 0;
}