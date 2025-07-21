#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

vector<pair<ll, int>> a;

// Function to calculate the minimum additional votes needed
ll minVotesNeeded(int i, ll add) {
    ll remain = K - add;
    ll cur = a[i].first + add;
    ll tar = cur + 1;
    
    int L = 0, R = N - i;
    while (L < R) {
        int MID = (L + R + 1) / 2;
        ll need = tar * MID - (a.back().first - a[a.size() - MID].first);
        if (MID < i) {
            need -= (add + 1);
        }
        if (need > remain) R = MID - 1;
        else L = MID;
    }
    return L - (MID < i);
}

int main() {
    cin >> N >> M >> K;

    for (int i = 0; i < N; ++i) {
        ll votes;
        cin >> votes;
        a.push_back({votes, i});
    }

    sort(a.begin(), a.end());

    vector<ll> ans(N);

    for (int i = 0; i < N; ++i) {
        ll cur = a[i].first + K;
        int idx = lower_bound(a.begin() + i + 1, a.end(), make_pair(cur, INT_MAX)) - a.begin();
        int cnt = N - idx;
        
        if (cnt >= M) {
            ans[i] = -1;
            continue;
        }

        ll l = 0, r = K;
        while (l < r) {
            ll mid = (l + r) / 2;
            cur = a[i].first + mid;
            idx = lower_bound(a.begin() + i + 1, a.end(), make_pair(cur, INT_MAX)) - a.begin();
            ll need = minVotesNeeded(i, mid);
            
            if (need < M) r = mid;
            else l = mid + 1;
        }
        ans[i] = l;
    }

    for (int i = 0; i < N; ++i) {
        cout << ans[i] << ' ';
    }

    return 0;
}