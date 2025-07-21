#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (M == N) {
        for (int i = 0; i < N; ++i) {
            cout << "0 ";
        }
        cout << endl;
        return 0;
    }

    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end(), greater<int>());

    int threshold = sortedA[M - 1];
    int sum_above_threshold = 0;
    int count_above_threshold = 0;
    for (int i = 0; i < N; ++i) {
        if (sortedA[i] > threshold) {
            sum_above_threshold += sortedA[i];
            count_above_threshold++;
        } else if (sortedA[i] == threshold) {
            if (count_above_threshold < M) {
                sum_above_threshold += sortedA[i];
                count_above_threshold++;
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (A[i] >= threshold) {
            cout << "0 ";
        } else {
            int required = threshold - A[i] + 1;
            if (required > K) {
                cout << "-1 ";
            } else {
                cout << required << " ";
            }
        }
    }
    cout << endl;
    return 0;
}