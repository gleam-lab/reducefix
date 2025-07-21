#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        k -= a[i];
    }

    // Calculate the maximum votes needed for a candidate to win
    vector<ll> max_votes_needed(n);
    for(int i = 0; i < n; ++i) {
        max_votes_needed[i] = a[i] + (k / (n - i)) + (k % (n - i) >= n - i);
    }

    // Calculate the current maximum votes among all candidates
    ll current_max_votes = *max_element(a.begin(), a.end());

    // Determine the minimum additional votes needed for each candidate
    vector<ll> result(n, -1);
    for(int i = 0; i < n; ++i) {
        if(max_votes_needed[i] <= current_max_votes) continue;
        result[i] = max_votes_needed[i] - a[i];
    }

    // Ensure that if a candidate can't win regardless of others' votes, set their result to -1
    for(int i = 0; i < n; ++i) {
        if(result[i] != -1 && result[i] > k) result[i] = -1;
    }

    // Output the results
    for(int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}