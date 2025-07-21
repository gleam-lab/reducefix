#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

struct Element {
    ll val;
    int index;
};

bool cmp(const Element &a, const Element &b) {
    return a.val != b.val ? a.val < b.val : a.index < b.index;
}

ll solve(int n, int k, vector<ll>& A, vector<ll>& B) {
    vector<Element> a(n), b(n);
    
    // Populate elements with their values and indices
    for (int i = 0; i < n; ++i) {
        a[i] = {A[i], i};
        b[i] = {B[i], i};
    }
    
    // Sort elements based on their values
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);
    
    // Find the maximum element in A
    ll maxA = a[k-1].val;
    
    // Calculate the sum of the first K elements in B
    ll sumB = 0;
    for (int i = 0; i < k; ++i) {
        sumB += b[i].val;
    }
    
    // Return the result
    return maxA * sumB;
}

int main() {
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
        
        cout << solve(n, k, A, B) << endl;
    }
    return 0;
}