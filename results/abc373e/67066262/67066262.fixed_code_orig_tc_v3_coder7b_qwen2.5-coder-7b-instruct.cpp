#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> minAdditionalVotes(vector<ll>& a, int M, ll K) {
    int n = a.size();
    vector<ll> result(n, -1);

    // Calculate the total votes received so far
    ll totalVotes = accumulate(a.begin(), a.end(), 0LL);

    // Calculate the remaining votes
    ll remainingVotes = K - totalVotes;

    // Create a sorted list of pairs (votes, index)
    vector<pair<ll, int>> candidates;
    for (int i = 0; i < n; ++i) {
        candidates.push_back({a[i], i});
    }

    // Sort candidates based on votes
    sort(candidates.begin(), candidates.end());

    // Iterate through the candidates
    for (int i = 0; i < n; ++i) {
        ll votes = candidates[i].first;
        int idx = candidates[i].second;

        // Calculate the maximum votes another candidate could get
        ll maxVotesOtherCanGet = 0;
        for (int j = 0; j < n; ++j) {
            if (j != idx) {
                maxVotesOtherCanGet = max(maxVotesOtherCanGet, a[j]);
            }
        }

        // Determine the required additional votes
        ll neededVotes = maxVotesOtherCanGet - votes + 1;
        if (neededVotes > 0 && remainingVotes >= neededVotes) {
            result[idx] = neededVotes;
            remainingVotes -= neededVotes;
        } else {
            result[idx] = 0;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_castio(0);
    cin.tie(0);

    int n, M;
    ll K;
    cin >> n >> M >> K;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> result = minAdditionalVotes(a, M, K);

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}