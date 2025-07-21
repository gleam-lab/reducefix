#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define ll long long

struct Element {
    ll a, b, idx;
};

bool compareA(const Element &a, const Element &b) {
    return a.a > b.a;
}

bool compareB(const Element &a, const Element &b) {
    return a.b > b.b;
}

ll solve(int n, int k, vector<ll> A, vector<ll> B) {
    vector<Element> AB(n);
    for (int i = 0; i < n; ++i) {
        AB[i] = {A[i], B[i], i};
    }
    
    // Sort by A in descending order
    sort(AB.begin(), AB.end(), compareA);
    
    // Calculate prefix sums of B
    vector<ll> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + AB[i].b;
    }
    
    // Sliding window to find the minimum expression value
    ll result = LLONG_MAX;
    for (int i = 0; i <= n - k; ++i) {
        ll maxA = AB[i].a;
        ll sumB = prefixSum[i + k] - prefixSum[i];
        result = min(result, maxA * sumB);
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
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
        
        cout << solve(n, k, A, B) << '\n';
    }
    
    return 0;
}