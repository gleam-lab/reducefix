#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, M;
ll K;

// Function to determine if a candidate can win with x additional votes
bool canWin(int i, ll x, const vector<ll>& A, int M) {
    ll curVotes = A[i] + x;
    int count = 0;
    
    // Count how many candidates have more votes than the current candidate after adding x votes
    for (int j = 0; j < N; ++j) {
        if (j != i && A[j] > curVotes) {
            ++count;
        }
    }
    
    // Check if the count is less than M
    return count < M;
}

int main() {
    cin >> N >> M >> K;

    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> result(N, -1);

    // Iterate over each candidate
    for (int i = 0; i < N; ++i) {
        if (canWin(i, 0, A, M)) {
            result[i] = 0;
            continue;
        }

        // Binary search to find the minimum number of additional votes needed
        ll left = 0, right = K;
        while (left < right) {
            ll mid = left + (right - left) / 2;
            if (canWin(i, mid, A, M)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        if (canWin(i, left, A, M)) {
            result[i] = left;
        }
    }

    // Output the results
    for (int i = 0; i < N; ++i) {
        cout << result[i] << ' ';
    }
    cout << endl;

    return 0;
}