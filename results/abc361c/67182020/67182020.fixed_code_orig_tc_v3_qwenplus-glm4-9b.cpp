#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
using ll = long long;

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Use min-heap and max-heap to get the min and max efficiently
    priority_queue<int, vector<int>, greater<int>> min_heap;
    priority_queue<int> max_heap;

    // Push all elements into the heaps
    for (int i = 0; i < N; ++i) {
        min_heap.push(A[i]);
        max_heap.push(A[i]);
    }

    // Remove K elements from the heaps
    for (int i = 0; i < K; ++i) {
        min_heap.pop();
        max_heap.pop();
    }

    // The result is the difference between the max and min
    cout << max_heap.top() - min_heap.top() << endl;
}

int main() {
    cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    solve();
    return 0;
}