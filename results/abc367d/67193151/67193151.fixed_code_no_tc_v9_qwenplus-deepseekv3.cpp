#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n, m, a[2*N], prefix[2*N];
int cnt[N]; // To store counts of remainders

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i+n] = a[i]; // Create circular array
    }

    prefix[0] = 0;
    cnt[0] = 1; // Initialize with prefix[0] mod m = 0
    long long res = 0;

    for(int i = 1; i <= 2*n; i++) {
        prefix[i] = prefix[i-1] + a[i];
        prefix[i] %= m;
        if(i > n) {
            // Remove the contribution from the element that's now out of window
            cnt[prefix[i - n] % m]--;
        }
        res += cnt[prefix[i] % m];
        if(i <= n) {
            // Only add to count for first n elements
            cnt[prefix[i] % m]++;
        }
    }

    cout << res;
    return 0;
}