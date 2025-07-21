#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,k,sum,cnt,a[N],b[N],d[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // Extend array a to have size 2n by mirroring it
    for(int i = 0; i < n; i++) {
        a[i + n] = a[i];
    }

    // Initialize the count array
    fill(b, b + m, 0);

    // Compute the prefix sum-like array
    for(int i = 0; i < 2 * n; i++) {
        d[i] = d[i - 1] + a[i]; // Using prefix sum logic with initial value 0
    }

    // Compute the final sum based on some logic (not specified)
    for(int i = 0; i < 2 * n; i++) {
        int mod_value = d[i] % m;
        sum += b[mod_value];
        b[mod_value]--;
    }

    cout << sum << endl;
    return 0;
}