#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pair<ll, int>>
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()

const ll INF = 1e18;

// Binary search helper function
int countPointsWithinDistance(const vll &prefixSum, const vi &sortedA, ll b, ll d) {
    // Find rightmost a_i <= b + d
    int up = upper_bound(all(sortedA), b + d) - sortedA.begin();
    // Find leftmost a_i >= b - d
    int lo = lower_bound(all(sortedA), b - d) - sortedA.begin();
    return up - lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    
    vi A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    sort(A.begin(), A.end());
    
    // Prefix sum of values is not needed, we only need to count elements in ranges
    
    vector<pair<ll, int>> queries;
    for (int i = 0; i < Q; ++i) {
        ll b;
        int k;
        cin >> b >> k;
        queries.emplace_back(b, k);
    }
    
    for (auto &[b, k] : queries) {
        ll l = 0, r = 2e14; // Safe upper bound given input constraints
        ll answer = INF;
        
        while (l <= r) {
            ll mid = (l + r) / 2;
            int cnt = countPointsWithinDistance({}, A, b, mid);
            
            if (cnt >= k) {
                answer = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        cout << answer << "\n";
    }
}