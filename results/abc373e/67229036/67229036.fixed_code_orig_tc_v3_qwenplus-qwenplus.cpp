#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int A[N], sorted_A[N];

bool canElect(int idx, int X) {
    // Copy the current votes to a temporary array
    int temp[N];
    for (int i = 0; i < n; ++i) temp[i] = A[i];
    temp[idx] += X;

    // Sort in descending order
    sort(temp, temp + n, greater<int>());
    
    // Candidate at position m has the m-th most votes
    return temp[m - 1] < temp[idx];
}

int minVotesToWin(int idx) {
    if (canElect(idx, 0)) return 0;

    int lo = 0, hi = k - A[idx] + 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (canElect(idx, mid)) hi = mid;
        else lo = mid + 1;
    }

    return (lo <= k - A[idx]) ? lo : -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        k -= A[i];
    }

    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = minVotesToWin(i);
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}