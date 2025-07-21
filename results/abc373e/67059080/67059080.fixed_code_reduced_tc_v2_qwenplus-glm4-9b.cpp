#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int N, M, K;
ll A[200005];

bool cmp(const pair<ll, int>& a, const pair<ll, int>& b) {
    return a.first < b.first;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<pair<ll, int>> newA(N);
    for (int i = 0; i < N; ++i) {
        newA[i] = {A[i], i + 1};
    }
    sort(newA.begin(), newA.end(), cmp);

    vector<ll> prefix(N);
    prefix[0] = newA[0].first;
    for (int i = 1; i < N; ++i) {
        prefix[i] = prefix[i - 1] + newA[i].first;
    }

    vector<ll> result(N);
    ll remainingVotes = K - prefix[N - 1];
    ll votesNeeded = 0;

    for (int i = 0; i < N; ++i) {
        if (N - i - 1 < M) {
            votesNeeded = prefix[N - 1] - prefix[i] + newA[i].first;
            if (votesNeeded <= remainingVotes) {
                result[newA[i].second - 1] = 0;
            } else {
                result[newA[i].second - 1] = votesNeeded - remainingVotes;
            }
        } else {
            if (newA[i].first < remainingVotes) {
                result[newA[i].second - 1] = 0;
            } else {
                votesNeeded = remainingVotes;
                result[newA[i].second - 1] = votesNeeded;
            }
        }
        remainingVotes -= votesNeeded;
    }

    for (ll res : result) {
        cout << res << ' ';
    }
    cout << '\n';

    return 0;
}