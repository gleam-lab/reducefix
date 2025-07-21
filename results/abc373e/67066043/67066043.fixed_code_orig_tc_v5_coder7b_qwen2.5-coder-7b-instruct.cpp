#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort candidates based on their current votes in descending order
    vector<pair<ll, int>> sortedCandidates;
    for(int i = 0; i < n; ++i) {
        sortedCandidates.push_back({a[i], i});
    }
    sort(sortedCandidates.rbegin(), sortedCandidates.rend());

    vector<ll> prefixSum(n + 1, 0);
    for(int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + sortedCandidates[i].first;
    }

    vector<ll> ans(n, -1);
    for(int i = 0; i < n; ++i) {
        int targetRank = n - i - 1;
        int neededVotes = prefixSum[targetRank] + k / (n - targetRank) + (k % (n - targetRank) != 0);

        if(neededVotes <= sortedCandidates[i].first) {
            ans[sortedCandidates[i].second] = 0;
        } else {
            ans[sortedCandidates[i].second] = neededVotes - sortedCandidates[i].first;
        }
    }

    for(ll x : ans) {
        cout << x << " ";
    }
    return 0;
}