#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;

int n, m, k;
int A[N], B[N];

bool canElect(int idx, int X) {
    vector<int> votes(A, A + n); // Make a copy of current votes
    votes[idx] += X; // Candidate idx gets X additional votes

    // Count how many candidates have strictly more than candidate idx
    int stronger = 0;
    for (int i = 0; i < n; ++i) {
        if (i == idx) continue;
        if (votes[i] > votes[idx]) {
            stronger++;
        }
    }

    return stronger < m;
}

// Binary search to find the minimum X to guarantee win
int minVotesToWin(int idx) {
    int low = 0;
    int high = k + 1;
    int answer = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canElect(idx, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    // Check for each candidate
    for (int i = 0; i < n; ++i) {
        cout << minVotesToWin(i) << " ";
    }

    return 0;
}