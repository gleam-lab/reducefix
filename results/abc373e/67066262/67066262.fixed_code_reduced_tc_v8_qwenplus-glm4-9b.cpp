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
    }
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
        return a[i] > a[j];
    });
    
    // Calculate the maximum votes any candidate can get to win
    ll max_votes_needed = a[ord[n - m]] + m;
    
    vector<ll> prefix(n + 1, 0);
    vector<ll> remaining_votes(k - n, 0);
    
    // Calculate the prefix sum of the sorted array and remaining votes
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = a[ord[i]] + prefix[i];
        remaining_votes[i] = k - prefix[i + 1];
    }
    
    vector<ll> ans(n, 0);
    
    // Calculate the minimum additional votes needed for each candidate to win
    for (int i = 0; i < n; i++) {
        ll votes_needed = max_votes_needed - a[ord[i]];
        
        // Binary search to find the minimum additional votes needed
        int low = 0, high = n;
        while (low < high) {
            int mid = (low + high) / 2;
            if (prefix[mid] <= prefix[i]) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        // Check if the candidate can win with the calculated votes
        if (prefix[low] == prefix[i] + votes_needed && remaining_votes[low] >= votes_needed) {
            ans[ord[i]] = votes_needed;
        } else {
            ans[ord[i]] = -1;
        }
    }
    
    // Output the results
    for (ll vote : ans) {
        cout << vote << ' ';
    }
    cout << '\n';
}