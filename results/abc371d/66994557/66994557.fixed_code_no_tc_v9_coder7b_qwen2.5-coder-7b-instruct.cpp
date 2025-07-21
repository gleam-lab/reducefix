#include<bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, q, x[MAXN], p[MAXN];
long long sum[MAXN];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        sum[i] = sum[i - 1] + p[i];
    }
    
    cin >> q;
    while (q--) {
        int L, R;
        cin >> L >> R;
        
        // Adjust indices to be zero-based for lower_bound and upper_bound
        auto it_l = lower_bound(x + 1, x + n + 1, L);
        auto it_r = upper_bound(x + 1, x + n + 1, R);
        
        // Calculate the correct range sum
        int l = it_l - x;
        int r = it_r - x;
        
        if (l > 0 && r > 0) {
            cout << sum[r - 1] - sum[l - 2] << endl; // Adjust index to get the correct subarray sum
        } else if (l == 0) {
            cout << sum[r - 1] << endl; // Handle the case when L is less than or equal to the first element
        } else {
            cout << "Invalid query" << endl; // Handle invalid queries where no elements fall within [L, R]
        }
    }
    return 0;
}