#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        k -= a[i];
    }

    // Sort candidates based on current votes
    vector<pair<ll, int>> candidates(n);
    for(int i = 0; i < n; i++)
        candidates[i] = {a[i], i};
    
    sort(candidates.rbegin(), candidates.rend());

    // Calculate prefix sum of sorted votes
    vector<ll> prefix_sum(n + 1);
    for(int i = 0; i < n; i++)
        prefix_sum[i + 1] = prefix_sum[i] + candidates[i].first;

    vector<ll> result(n, -1);

    for(int i = 0; i < n; i++) {
        ll needed_votes = 0;
        for(int j = 0; j < min(m, n - i); j++) {
            needed_votes += candidates[i + j].first + 1;
        }
        
        if(needed_votes <= k) {
            result[candidates[i].second] = needed_votes - a[candidates[i].second];
        } else {
            result[candidates[i].second] = -1;
        }
    }

    for(auto val : result)
        cout << val << " ";

    return 0;
}