#include<bits/stdc++.h>
using namespace std;
int n, q, x[200005], p[200005];
long long sum[200005]; // Use long long to avoid overflow

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x[i];
    }
    sum[0] = 0; // Initialize sum[0] to 0
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i]; // Cumulative sum
    }
    cin >> q;
    while(q--){
        int L, R;
        cin >> L >> R;
        int c = lower_bound(x + 1, x + n + 1, L) - x; // Use lower_bound to find the first element >= L
        int d = upper_bound(x + 1, x + n + 1, R) - x; // Use upper_bound to find the first element > R
        if (c > n || d > n || c > d) {
            cout << 0 << endl; // Handle edge cases where no valid range is found
        } else {
            cout << sum[d - 1] - sum[c - 1] << endl; // Output the difference of cumulative sums
        }
    }
    return 0;
}