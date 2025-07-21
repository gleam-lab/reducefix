#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> prefix_sum;
vector<ll> vote_needed;

ll calculate_votes_needed(ll target, ll total_votes) {
    // Find the position where the target candidate's votes fall within the top M candidates
    auto it = lower_bound(prefix_sum.begin(), prefix_sum.end(), target + 1);
    int pos = it - prefix_sum.begin();
    
    // Calculate the minimum votes needed for the target candidate to win
    if (pos < target + 1 && pos >= target + 1 - min(target + 1, (ll)prefix_sum.size())) {
        return max(0LL, (target + 1 - pos) * (target + 1) - prefix_sum[pos] + total_votes);
    }
    return -1;
}

void process_candidates(vector<int>& votes, int m, int k) {
    int n = votes.size();
    sort(votes.begin(), votes.end());
    
    prefix_sum.resize(n + 1);
    for (int i = 0; i < n; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + votes[i];
    }

    vote_needed.resize(n);
    for (int i = 0; i < n; ++i) {
        vote_needed[i] = calculate_votes_needed(votes[i], k - prefix_sum.back() + prefix_sum[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> votes(n);
    for (int i = 0; i < n; ++i) {
        cin >> votes[i];
    }

    process_candidates(votes, m, k);

    for (int i = 0; i < n; ++i) {
        cout << vote_needed[i] << " ";
    }
    cout << endl;

    return 0;
}