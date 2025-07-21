#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(vector<ll>& a, int n, int m, ll k, ll x) {
    vector<bool> won(n, false);
    priority_queue<pair<ll, int>> pq;
    
    // Initialize priority queue with current vote counts
    for (int i = 0; i < n; ++i) {
        pq.push({a[i], i});
    }
    
    while (!pq.empty()) {
        auto [votes, id] = pq.top(); pq.pop();
        
        // Calculate the maximum votes the current candidate can get after adding x votes
        ll max_votes = votes + x;
        
        // Count how many candidates have more votes than the current candidate
        int count = 0;
        while (!pq.empty() && pq.top().first > max_votes) {
            pq.pop();
            count++;
        }
        
        // Check if the current candidate can still win
        if (count < m) {
            won[id] = true;
        } else {
            break;
        }
    }
    
    // Verify if all candidates who need to win have won
    for (int i = 0; i < n; ++i) {
        if (won[i] && !a[i]) return false;
    }
    
    return true;
}

vector<ll> minVotesToWin(int n, int m, ll k, vector<ll>& a) {
    vector<ll> result(n, -1);
    
    // Sort candidates based on their initial votes
    vector<pair<ll, int>> sortedCandidates;
    for (int i = 0; i < n; ++i) {
        sortedCandidates.emplace_back(a[i], i);
    }
    sort(sortedCandidates.begin(), sortedCandidates.end());
    
    // Iterate through candidates and calculate the minimum votes needed
    for (int i = 0; i < n; ++i) {
        ll lo = 0, hi = k;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            if (check(a, n, m, k, mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (lo <= k) {
            result[sortedCandidates[i].second] = lo;
        }
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> result = minVotesToWin(n, m, k, a);

    for (ll val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}