#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5;
ll a[MAXN], b[MAXN];

int main() {
    ll n;
    cin >> n;
    
    // Read toy sizes
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    
    // Read box sizes
    for(int i = 1; i < n; ++i)
        cin >> b[i];
    
    // Sort toy sizes in descending order
    sort(a + 1, a + n + 1, greater<ll>());
    
    // Sort box sizes in ascending order
    sort(b + 1, b + n);
    
    // Initialize variables
    int j = 0;
    bool possible = true;
    
    // Iterate over toys
    for(int i = 1; i <= n; ++i) {
        // If we run out of boxes before placing all toys
        if(j >= n - 1) {
            possible = false;
            break;
        }
        
        // Find a suitable box for the current toy
        while(j < n - 1 && b[j] < a[i])
            ++j;
        
        // If no suitable box is found
        if(j == n - 1 && b[j] < a[i]) {
            possible = false;
            break;
        }
        
        // Move to the next box
        ++j;
    }
    
    // Output the result
    if(possible)
        cout << "1"; // Any box of size at least max(A_i) will work
    else
        cout << "-1";
    
    return 0;
}