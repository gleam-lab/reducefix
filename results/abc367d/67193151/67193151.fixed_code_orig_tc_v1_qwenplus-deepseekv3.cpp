#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int n, m, sum, cnt, a[N], prefix[N], freq[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    long long result = 0;
    prefix[0] = 0;
    freq[0] = 1;
    
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = (prefix[i - 1] + a[i]) % m;
        if (i > n) {
            freq[prefix[i - n]]--;
        }
        result += freq[prefix[i]];
        if (i < n) {
            freq[prefix[i]]++;
        }
    }
    
    cout << result << endl;
    return 0;
}