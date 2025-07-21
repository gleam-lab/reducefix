#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph = vector<vector<int>>;

// ... (other code remains the same) ...

int main(){
    int N;
    cin >> N;
    vector<ll> P(N+1, 0); // Initialize P with 0's to calculate prefix sum correctly
    for (int i = 1; i <= N; ++i) {
        ll p;
        cin >> p;
        P[i] = P[i-1] + p; // Corrected prefix sum calculation
    }
    // ... (rest of the code remains the same) ...
}