#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll solve(int n, int k, vector<ll>& A, vector<ll>& B) {
    vector<pair<ll, ll>> AB(n);
    for (int i = 0; i < n; ++i) {
        AB[i] = {A[i], B[i]};
    }
    
    // Sort by A in descending order
    sort(AB.begin(), AB.end(), [&](auto& a, auto& b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    });
    
    ll min_value = LLONG_MAX;
    ll sum_B = 0;
    
    // Calculate the sum of B for the first K elements
    for (int i = 0; i < k; ++i) {
        sum_B += AB[i].second;
    }
    
    // Initialize the minimum value with the initial product
    min_value = AB[k - 1].first * sum_B;
    
    // Iterate through the remaining elements to find the minimum value
    for (int i = k; i < n; ++i) {
        sum_B += AB[i].second - AB[i - k].second;
        min_value = min(min_value, AB[i].first * sum_B);
    }
    
    return min_value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<ll> A(n), B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        
        ll result = solve(n, k, A, B);
        cout << result << '\n';
    }
    
    return 0;
}