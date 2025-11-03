#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    
    ll T = 0;
    int current = 0;
    
    while (current < n) {
        T++;
        if (a[current] > 0) {
            if (T % 3 == 0) {
                a[current] -= 3;
            } else {
                a[current] -= 1;
            }
        }
        
        // Move to next enemy if current one is dead
        while (current < n && a[current] <= 0) {
            current++;
        }
    }
    
    cout << T << endl;
}