#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

// Function to find the minimum possible value of the given expression
ll solve(int N, int K, vector<ll>& A, vector<ll>& B) {
    // Sort array A based on its elements
    vector<pair<ll, int>> sortedA(N);
    for (int i = 0; i < N; ++i) {
        sortedA[i] = {A[i], i};
    }
    sort(sortedA.begin(), sortedA.end());

    // Create an array B' where B'[i] is B[index of sortedA[i]]
    vector<ll> Bprime(N);
    for (int i = 0; i < N; ++i) {
        Bprime[i] = B[sortedA[i].second];
    }

    // Initialize variables
    ll maxA = 0, sumB = 0, ans = LLONG_MAX;
    
    // Iterate through the sorted array A
    for (int i = 0; i < N; ++i) {
        maxA = max(maxA, sortedA[i].first);
        sumB += Bprime[i];
        
        // Maintain a window of size K-1
        if (i >= K - 1) {
            sumB -= Bprime[i - K + 1];
            ans = min(ans, maxA * sumB);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        vector<ll> A(N), B(N);
        for (int i = 0; i < N; ++i) cin >> A[i];
        for (int i = 0; i < N; ++i) cin >> B[i];
        
        // Call the solve function for each test case
        cout << solve(N, K, A, B) << '\n';
    }
    return 0;
}