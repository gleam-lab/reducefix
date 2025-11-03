#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
ll a[400005], w[400005];
map<ll, ll> t;
ll an;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    w[0] = 0;
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i - 1] + a[i]) % m;
    }
    
    t.clear();
    an = 0;
    
    // Process the first window of size n
    for (int i = 0; i < n; i++) {
        t[w[i]]++;
    }
    
    // Slide the window from position n to 2*n
    for (int i = n; i <= 2 * n; i++) {
        // Remove the element that's leaving the window
        if (i > n) {
            t[w[i - n - 1]]--;
            if (t[w[i - n - 1]] == 0) {
                t.erase(w[i - n - 1]);
            }
        }
        
        // Count how many previous prefix sums are equal to current one
        an += t[w[i]];
        
        // Add the current prefix sum to the map
        if (i < 2 * n) {
            t[w[i]]++;
        }
    }
    
    cout << an;
    return 0;
}