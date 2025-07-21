#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, m;
long long a[N * 2], prefix[N * 2];
int freq[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    
    prefix[0] = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        prefix[i] = prefix[i - 1] + a[i - 1];
    }
    
    long long total = 0;
    freq[0] = 1;
    
    for (int i = 1; i <= 2 * n; ++i) {
        if (i > n) {
            long long prev_sum = prefix[i - n] % m;
            if (prev_sum < 0) prev_sum += m;
            freq[prev_sum]--;
        }
        long long current_sum = prefix[i] % m;
        if (current_sum < 0) current_sum += m;
        total += freq[current_sum];
        if (i < n) {
            freq[current_sum]++;
        }
    }
    
    cout << total << "\n";
    return 0;
}