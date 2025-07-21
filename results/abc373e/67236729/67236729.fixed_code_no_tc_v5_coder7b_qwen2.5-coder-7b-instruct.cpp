#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 200010;
ll a[MAXN];

bool can_win(int n, int m, ll k, int i, ll x) {
    ll remaining_votes = k - accumulate(a + 1, a + n + 1, 0LL);
    if (remaining_votes < 0) return false;
    
    // Calculate the current votes needed for candidate i to win
    ll needed_votes = a[i] + x + 1 - m;
    if (needed_votes <= 0) return true;
    
    // Sort the votes excluding candidate i
    sort(a + 1, a + i);
    sort(a + i + 1, a + n + 1);
    
    // Calculate the sum of the smallest (m-1) votes
    ll sum_smallest_m_minus_1 = accumulate(a + 1, a + m, 0LL);
    
    // Check if the remaining votes are enough to exceed the sum of the smallest (m-1) votes
    return remaining_votes >= needed_votes - sum_smallest_m_minus_1;
}

int main() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    vector<ll> results(n);
    
    for (int i = 1; i <= n; ++i) {
        ll left = 0, right = k;
        while (left <= right) {
            ll mid = (left + right) / 2;
            if (can_win(n, m, k, i, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        results[i - 1] = left;
    }
    
    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    
    return 0;
}