#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

#define rep(i, a, b) for(ll i = (a); i < (b); ++i)
#define per(i, a, b) for(ll i = (b)-1; i >= (a); --i)
#define sortv(v) sort((v).begin(), (v).end())
#define sortd(v) sort((v).rbegin(), (v).rend())

void solve() {
    ll n, k;
    cin >> n >> k;
    vector<pll> ab(n);
    for (ll i = 0; i < n; ++i) cin >> ab[i].first;
    for (ll i = 0; i < n; ++i) cin >> ab[i].second;

    // Sort by A_i in ascending order
    sort(ab.begin(), ab.end());

    multiset<ll> min_heap;
    ll sum_b = 0;
    
    // Initialize with the first K elements based on minimum B_i values
    priority_queue<ll> max_heap;  // To maintain the K largest B_i's
    
    // First select K elements with smallest B_i to minimize sum*B
    // Wait, actually we want to maintain the K elements with largest B_i
    // Because when A increases, we can potentially get better combinations

    // Let's try another approach:
    // We'll keep track of K elements where A is small and B is large
    // We sort all items by A increasing
    // Start with first K items, keep track of sum of B and max A
    // Then for each next item i (from K to N-1):
    // - try to replace the smallest B in current set with this new item
    // - if replacement improves result, update

    // Correct approach:
    // Sort by A increasing
    // Maintain a max-heap of B values of size K
    // This ensures that sum of B is as large as possible for given A

    // So here's the fix:

    // Use a min-heap to maintain top K smallest B values
    // This allows us to efficiently remove the smallest when full

    multiset<ll, greater<>> top_k_b;
    multiset<ll> rest_b;

    // First take K elements with largest B values from first K+1 elements
    // Actually, let's start with first K elements and build from there

    // Final working approach:
    // Sort pairs by A increasing
    // Use a min-heap to maintain the K elements with largest B values seen so far
    // As we iterate through elements, we keep track of maximum A and sum of B's
    // The optimal solution is found among these combinations

    // Correct algorithm:
    // 1. Sort the array by A increasing
    // 2. Keep a min-heap of size K storing B values
    // 3. For each element from K to N-1:
    //    a. Add current B to heap
    //    b. If heap size > K, remove smallest B
    //    c. Compute A * sum(B) and update answer

    priority_queue<ll, vector<ll>, greater<>> min_heap;
    ll sum = 0;
    
    for (ll i = 0; i < n; ++i) {
        if (min_heap.size() < k) {
            min_heap.push(ab[i].second);
            sum += ab[i].second;
        } else {
            if (ab[i].second > min_heap.top()) {
                sum -= min_heap.top();
                min_heap.pop();
                min_heap.push(ab[i].second);
                sum += ab[i].second;
            }
        }
        
        if (i >= k - 1) {
            ll current_max_a = ab[i].first;
            ll current_score = current_max_a * sum;
            static ll ans;
            if (i == k - 1) {
                ans = current_score;
            } else {
                ans = min(ans, current_score);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}