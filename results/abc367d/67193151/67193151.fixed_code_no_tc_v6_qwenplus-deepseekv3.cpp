#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N];
long long prefix[2*N];
int cnt[N];

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        a[i+n] = a[i];  // Make circular by doubling the array
    }

    // Compute prefix sums
    prefix[0] = 0;
    for(int i=1; i<=2*n; i++) {
        prefix[i] = prefix[i-1] + a[i];
    }

    long long result = 0;
    cnt[0] = 1;  // Initial count for prefix[0] mod m = 0

    // Sliding window of size n
    for(int i=1; i<=2*n; i++) {
        if(i > n) {
            // Remove the element that's sliding out of the window
            long long prev_mod = prefix[i-n] % m;
            if(prev_mod < 0) prev_mod += m;
            cnt[prev_mod]--;
        }

        long long current_mod = prefix[i] % m;
        if(current_mod < 0) current_mod += m;
        result += cnt[current_mod];
        cnt[current_mod]++;
    }

    cout << result;
    return 0;
}