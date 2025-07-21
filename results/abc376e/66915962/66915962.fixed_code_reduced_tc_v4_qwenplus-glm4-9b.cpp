#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using VI = vector<int>;
using P = pair<int, ll>; // Using ll for the sum to handle large numbers

constexpr int INF = 1001001001;
constexpr ll LINF = 1001001001001001001ll;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        VI a(n), b(n);
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        // Pair each A_i with B_i and sort by A_i in descending order
        vector<P> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = {a[i], b[i]};
        }
        sort(p.begin(), p.end(), greater<>()); // Sort by A in descending order
        
        ll maxA = p[0].first; // The k-th largest A will be the first element after sorting
        ll sumB = 0;
        
        // Calculate the sum of the k largest B values with the lowest k A values
        for (int i = 0; i < k; i++) {
            sumB += p[i].second;
        }
        
        // The result for this test case is the product of the k-th largest A and the sum of the k largest B values
        cout << maxA * sumB << '\n';
    }
}