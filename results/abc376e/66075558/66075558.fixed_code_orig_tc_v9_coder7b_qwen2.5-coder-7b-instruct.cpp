#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

struct Pair {
    ll first, second;
};

bool compare(const Pair &a, const Pair &b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

ll solve(int n, int k, vector<ll> &A, vector<ll> &B) {
    vector<Pair> pairs(n);
    
    // Create pairs of A and B
    for (int i = 0; i < n; ++i) {
        pairs[i] = {A[i], B[i]};
    }
    
    // Sort the pairs based on the criteria
    sort(pairs.begin(), pairs.end(), compare);
    
    // Initialize variables
    ll ans = LLONG_MAX;
    ll current_sum = 0;
    int count = 0;
    
    // Iterate through the sorted pairs
    for (int i = 0; i < n; ++i) {
        current_sum += pairs[i].second;
        count++;
        
        // If we have chosen enough elements, calculate the result
        if (count == k) {
            ans = min(ans, pairs[i].first * current_sum);
            current_sum -= pairs[i-k+1].second;
            count--;
        }
    }
    
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> A(n), B(n);
        for (int i = 0; i < n; ++i) cin >> A[i];
        for (int i = 0; i < n; ++i) cin >> B[i];
        
        cout << solve(n, k, A, B) << '\n';
    }
    
    return 0;
}