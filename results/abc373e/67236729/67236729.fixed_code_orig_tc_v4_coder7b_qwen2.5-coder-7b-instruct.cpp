#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Candidate {
    ll votes;
    int index;
};

bool cmp(Candidate a, Candidate b) {
    return a.votes > b.votes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<Candidate> candidates(n);
    for (int i = 0; i < n; ++i) {
        cin >> candidates[i].votes;
        candidates[i].index = i + 1;
    }

    sort(candidates.begin(), candidates.end(), cmp);

    ll total_votes = accumulate(candidates.begin(), candidates.end(), 0LL, [](ll sum, const Candidate& c){return sum + c.votes;});
    if (total_votes <= k) {
        for (int i = 0; i < n; ++i) {
            cout << 0 << " ";
        }
        return 0;
    }

    ll required_votes = k + 1;
    for (int i = 0; i < n; ++i) {
        if (candidates[i].votes >= required_votes) {
            cout << 0 << " ";
        } else {
            ll needed_votes = required_votes - candidates[i].votes;
            if (needed_votes <= k - total_votes + candidates[i].votes) {
                cout << needed_votes << " ";
            } else {
                cout << -1 << " ";
            }
        }
        required_votes += candidates[i].votes;
    }

    return 0;
}