#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    int answer = INT_MAX;
    for (int i = 0; i <= K; ++i) {
        int left = i;
        int right = K - i;
        if (left + right > K) continue;
        if (left > N || right > N) continue;
        int current_min = A[left];
        int current_max = A[N - 1 - right];
        answer = min(answer, current_max - current_min);
    }
    cout << answer << endl;
    return 0;
}