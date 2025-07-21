#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int N, Q;
vector<long long> A;
vector<pair<long long, int>> queries[MAXN];

long long answer[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> Q;
    A.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    
    for (int j = 0; j < Q; ++j) {
        long long b;
        int k;
        cin >> b >> k;
        queries[j] = {make_pair(b, k)};
    }

    // For each query, find the k-th closest A to b
    for (int j = 0; j < Q; ++j) {
        long long b = queries[j].first;
        int k = queries[j].second;

        // Create a list of distances from b to all A
        vector<long long> dists(N);
        for (int i = 0; i < N; ++i) {
            dists[i] = abs(A[i] - b);
        }

        // Sort distances and return the k-th smallest
        nth_element(dists.begin(), dists.begin() + k - 1, dists.end());
        answer[j] = dists[k - 1];
    }

    for (int j = 0; j < Q; ++j) {
        cout << answer[j] << '\n';
    }

    return 0;
}