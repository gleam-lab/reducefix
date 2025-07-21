#include<bits/stdc++.h>
using namespace std;
int n, m, a[400005], t[1000005], an, w[400005];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= m;
        a[i + n] = a[i];
    }
    
    // Initialize the t array to keep track of counts
    for (int i = 0; i < m; i++) {
        t[i] = 0;
    }
    
    // Calculate the prefix sums of a and update the count array
    for (int i = 1; i <= 2 * n; i++) {
        w[i] = (w[i - 1] + a[i % n]) % m;
        t[w[i]]++;
    }
    
    // Calculate the answer by summing up the counts of each w[i]
    for (int i = 0; i < m; i++) {
        an += t[i] * (t[i] - 1) / 2; // Each pair contributes to the answer
    }
    
    cout << an;
    return 0;
}