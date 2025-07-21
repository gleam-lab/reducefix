#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll minCost(int N, int K, vector<ll>& A, vector<ll>& B) {
    // Sort A based on the values and store their indices
    vector<pair<ll, int>> sortedA(N);
    for(int i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());

    // Create a vector to store B values corresponding to sorted A indices
    vector<ll> B_sorted(N);
    for(int i = 0; i < N; ++i) {
        B_sorted[i] = B[sortedA[i].second];
    }

    // Calculate the cost using a sliding window approach
    ll maxA = sortedA[K - 1].first;
    ll sumB = 0;
    for(int i = 0; i < K; ++i) {
        sumB += B_sorted[i];
    }
    ll result = maxA * sumB;

    for(int i = K; i < N; ++i) {
        sumB += B_sorted[i] - B_sorted[i - K];
        maxA = sortedA[i].first;
        result = min(result, maxA * sumB);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T;
    cin >> T;
    while(T--) {
        int N, K;
        cin >> N >> K;
        vector<ll> A(N), B(N);
        for(int i = 0; i < N; ++i) cin >> A[i];
        for(int i = 0; i < N; ++i) cin >> B[i];

        cout << minCost(N, K, A, B) << '\n';
    }

    return 0;
}