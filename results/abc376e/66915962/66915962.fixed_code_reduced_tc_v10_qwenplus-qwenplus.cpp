#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, int>;
constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, k, n) for (ll i = k; i < (ll)(n); i++)
#define OUT(x) cout << #x << ":" << x << endl

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    rep(qi, t){
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> items(n);
        rep(i, n) {
            cin >> items[i].first;
        }
        rep(i, n) {
            cin >> items[i].second;
        }

        // Sort by A_i in ascending order
        sort(items.begin(), items.end());

        ll sumB = 0;
        multiset<int> activeBs;

        // Initialize with first K elements
        rep(i, k) {
            sumB += items[i].second;
            activeBs.insert(items[i].second);
        }

        ll ans = (ll)items[k-1].first * sumB;

        // Process remaining elements
        rep2(i, k, n) {
            // Remove the largest B from the current set
            auto maxIt = prev(activeBs.end());
            sumB -= *maxIt;
            activeBs.erase(maxIt);

            // Add new element
            sumB += items[i].second;
            activeBs.insert(items[i].second);

            // Update answer with current A_i and sum of B's
            ans = min(ans, (ll)items[i].first * sumB);
        }

        cout << ans << '\n';
    }

    return 0;
}