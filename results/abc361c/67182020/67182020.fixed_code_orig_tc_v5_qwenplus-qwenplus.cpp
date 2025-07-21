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

    // We will consider the minimum possible value of max(B) - min(B)
    // where B is a subsequence of A with exactly N-K elements.
    //
    // The idea is:
    // - For each window of size (N-K), we need to track min and max
    // - Use sliding window with a data structure that allows O(1) or O(logN) operations

    deque<int> minDq, maxDq;
    long long result = numeric_limits<long long>::max();

    for (int i = 0; i < N; ++i) {
        // Maintain deque for min and max in window of size (N-K)
        while (!minDq.empty() && minDq.front() < i - (N-K)) minDq.pop_front();
        while (!maxDq.empty() && maxDq.front() < i - (N-K)) maxDq.pop_front();

        // Remove elements not useful for current window
        while (!minDq.empty() && A[minDq.back()] >= A[i]) minDq.pop_back();
        while (!maxDq.empty() && A[maxDq.back()] <= A[i]) maxDq.pop_back();

        minDq.push_back(i);
        maxDq.push_back(i);

        if (i >= (N-K)-1) {
            result = min(result, (long long)(A[maxDq.front()] - A[minDq.front()]));
        }
    }

    cout << result << endl;
}