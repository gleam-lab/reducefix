#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5 + 5;

// Function to check if candidate i can win with x additional votes
bool check(vector<ll>& A, vector<ll>& B, vector<ll>& C, int i, ll x, int m, ll k) {
    int n = A.size();
    int z = lower_bound(B.begin() + 1, B.end(), x + A[i] + 1) - B.begin();
    if (z < n - m)
        return false;
    ll votes_needed = (x + A[i] + 1) * (z - n + m) - (C[z] - C[n - m - 1] - max((ll)x, B[n - m]));
    return votes_needed <= k - x;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    vector<ll> A(n + 1), B(n + 1), C(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        k -= A[i];
        B[i] = A[i];
    }
    
    sort(B.begin() + 1, B.end());
    partial_sum(B.begin() + 1, B.end(), C.begin() + 1);
    
    for (int i = 1; i <= n; ++i) {
        ll l = 0, r = k + 1;
        while (l < r) {
            ll mid = l + (r - l) / 2;
            if (check(A, B, C, i, mid, m, k))
                r = mid;
            else
                l = mid + 1;
        }
        if (l <= k)
            cout << l << " ";
        else
            cout << "-1 ";
    }
    
    return 0;
}