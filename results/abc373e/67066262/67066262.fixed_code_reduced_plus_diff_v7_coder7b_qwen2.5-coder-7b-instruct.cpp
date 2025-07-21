#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool can_win(const vector<ll>& votes, const vector<int>& order, int x, int m) {
    int n = votes.size();
    vector<ll> remaining_votes(votes);
    
    // Distribute additional votes to the target candidate
    remaining_votes[order[0]] += x;
    
    // Sort remaining candidates based on their vote counts
    vector<pair<int, int>> sorted_candidates;
    for (int i = 1; i < n; ++i) {
        sorted_candidates.push_back({remaining_votes[i], i});
    }
    sort(sorted_candidates.rbegin(), sorted_candidates.rend());
    
    // Check if the target candidate can still win after sorting
    for (int i = 0; i < n; ++i) {
        if (i < m - 1 && sorted_candidates[i].first > sorted_candidates[i + 1].first) {
            return false;
        }
    }
    return true;
}

vector<int> min_additional_votes(int n, int m, int k, vector<ll>& votes) {
    vector<int> result(n, -1);
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    
    // Binary search for the minimum number of additional votes needed
    int low = 0, high = k;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (can_win(votes, order, mid, m)) {
            result[order[0]] = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    // Adjust the results for other candidates
    for (int i = 1; i < n; ++i) {
        if (result[order[0]] != -1) {
            if (votes[order[0]] + result[order[0]] > votes[order[i]]) {
                result[order[i]] = 0;
            } else {
                result[order[i]] = -1;
            }
        } else {
            result[order[i]] = -1;
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
    vector<ll> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }
    
    vector<int> result = min_additional_votes(n, m, k, votes);
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}