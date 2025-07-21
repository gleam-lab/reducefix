#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;
int A[MAXN];

bool can_win(int N, int M, int K, int A[], int i, int X) {
    int max_votes = 0;
    for (int j = 1; j <= N; ++j) {
        if (j == i) {
            max_votes = max(max_votes, A[j] + X);
        } else {
            max_votes = max(max_votes, A[j]);
        }
    }
    
    int num_cands_more_votes = 0;
    for (int j = 1; j <= N; ++j) {
        if (j != i && max_votes > A[j]) {
            ++num_cands_more_votes;
        }
    }
    
    return num_cands_more_votes < M;
}

int binary_search(int N, int M, int K, int A[]) {
    int left = 0, right = K;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (can_win(N, M, K, A, 1, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    vector<int> results(N);
    for (int i = 1; i <= N; ++i) {
        results[i-1] = binary_search(N, M, K, A);
        // Adjust A[i] to reflect the current vote count including the minimum required votes for candidate i
        A[i] += results[i-1];
    }
    
    for (int i = 0; i < N; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
    
    return 0;
}