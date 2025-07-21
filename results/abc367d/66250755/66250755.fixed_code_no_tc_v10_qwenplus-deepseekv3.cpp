#include<bits/stdc++.h>
using namespace std;
const int MAX = 4e5 + 5;
int n, m, a[MAX], w[MAX], t[MAX];
long long an;  // Changed to long long to prevent overflow

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];  // Create circular array
    }
    
    w[0] = 0;
    for(int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i - 1] + a[i]) % m;
    }
    
    memset(t, 0, sizeof(t));
    t[0] = 1;  // Initial prefix sum of 0
    
    for(int i = 1; i <= 2 * n; i++) {
        if(i > n) {
            t[w[i - n]]--;  // Remove the prefix sum that's sliding out of window
        }
        if(i >= n) {
            an += t[w[i]];  // Count matching prefix sums
        }
        t[w[i]]++;  // Add current prefix sum to count
    }
    
    cout << an << endl;
    return 0;
}