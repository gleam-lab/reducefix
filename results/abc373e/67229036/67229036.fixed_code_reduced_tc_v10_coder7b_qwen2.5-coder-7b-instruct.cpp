#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
typedef long long ll;

int n, m, k;
vector<ll> A;
vector<ll> B, C;

bool check(int i, ll x) {
    // Calculate the new total votes for candidate i after receiving x additional votes
    ll new_votes_i = A[i] + x;
    
    // Find the position of the candidate with new_votes_i using binary search
    auto pos = lower_bound(B.begin(), B.end(), new_votes_i) - B.begin();
    
    // Check if the candidate can still secure their victory
    if (pos >= n - m) return false;
    
    // Calculate the required additional votes for candidate i
    ll required_additional_votes = (new_votes_i + 1) * (n - m - pos) - (C[pos] - C[n - m - 1] - max(new_votes_i, B[n - m]));
    
    // Return true if the calculated additional votes are within the remaining votes
    return required_additional_votes <= k - (A[i] + x);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    
    cin >> n >> m >> k;
    A.resize(n + 1);
    B.resize(n + 1);
    C.resize(n + 1);
    
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
        k -= A[i];
        B[i] = A[i];
    }
    
    sort(B.begin(), B.end());
    partial_sum(B.begin(), B.end(), C.begin());
    
    vector<int> result(n + 1, -1);
    
    for (int i = 1; i <= n; ++i) {
        if (check(i, 0)) {
            result[i] = 0;
            continue;
        }
        
        ll left = 0, right = k + 1;
        while (left < right) {
            ll mid = left + (right - left) / 2;
            if (check(i, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        
        if (left <= k) {
            result[i] = left;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}