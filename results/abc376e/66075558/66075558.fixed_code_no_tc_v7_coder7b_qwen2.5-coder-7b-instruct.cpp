#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

struct Element {
    int val, idx;
};

bool compareByValue(const Element &a, const Element &b) {
    return a.val < b.val;
}

ll solve(int n, int k, vector<int> &A, vector<int> &B) {
    vector<Element> elements(n);
    
    // Create a list of elements with their indices
    for (int i = 0; i < n; ++i) {
        elements[i] = {A[i], i};
    }
    
    // Sort elements based on the value of A
    sort(elements.begin(), elements.end(), compareByValue);
    
    // Calculate the prefix sums of B
    vector<ll> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + B[elements[i - 1].idx];
    }
    
    ll minCost = LLONG_MAX;
    
    // Iterate through all possible subsets of size K
    for (int i = 0; i <= n - k; ++i) {
        ll maxA = elements[i + k - 1].val;
        ll sumB = prefixSum[i + k] - prefixSum[i];
        minCost = min(minCost, maxA * sumB);
    }
    
    return minCost;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> A(n), B(n);
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