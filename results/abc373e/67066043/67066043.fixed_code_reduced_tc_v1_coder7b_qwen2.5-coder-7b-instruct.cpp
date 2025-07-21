#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

    // Calculate the total votes needed for a candidate to win
    vector<ll> needed(n);
    for(int i = 0; i < n; ++i) {
        needed[i] = (n - m) * a[i] + (m - 1);
    }

    // Sort the candidates based on the needed votes
    vector<pair<ll, int>> sorted_needed;
    for(int i = 0; i < n; ++i) {
        sorted_needed.emplace_back(needed[i], i);
    }
    sort(sorted_needed.begin(), sorted_needed.end());

    // Binary search to find the minimum additional votes needed for each candidate
    vector<ll> result(n, -1);
    for(int i = 0; i < n; ++i) {
        ll target = sorted_needed[i].first;
        ll left = 0, right = k + 1;
        while(left < right) {
            ll mid = left + (right - left) / 2;
            ll count = 0;
            for(int j = 0; j < n; ++j) {
                if(a[j] + mid > target) {
                    count += min(mid, target - a[j]);
                }
            }
            if(count > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        result[sorted_needed[i].second] = left;
    }

    // Special case: if a candidate already has enough votes, set the result to 0
    for(int i = 0; i < n; ++i) {
        if(result[i] == 0 || (a[i] + result[i]) >= needed[i]) {
            result[i] = 0;
        }
    }

    // Output the results
    for(ll x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}