#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define INF 1e18

const int MAXN = 2e5 + 5;

ll N, M, K;
vector<ll> A(MAXN);

bool canWin(vector<ll>& votes, vector<ll>& prefixSum, int idx, ll x) {
    int needed = 0;
    for (int i = 0; i < idx; ++i) {
        if (votes[i] > votes[idx]) {
            needed += max((votes[i] + x + 1) - (votes[idx] + x), 0LL);
        }
    }
    return needed <= M;
}

void binarySearch(vector<ll>& votes, vector<ll>& prefixSum, int idx) {
    ll left = 0, right = K - accumulate(votes.begin(), votes.end(), 0LL);
    while (left < right) {
        ll mid = (left + right) / 2;
        if (canWin(votes, prefixSum, idx, mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << (canWin(votes, prefixSum, idx, left) ? left : -1) << " ";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<ll> prefixSum(N + 1);
    for (int i = 0; i < N; ++i) {
        prefixSum[i + 1] = prefixSum[i] + A[i];
    }

    sort(A.begin(), A.end());

    for (int i = 0; i < N; ++i) {
        binarySearch(A, prefixSum, i);
    }

    return 0;
}