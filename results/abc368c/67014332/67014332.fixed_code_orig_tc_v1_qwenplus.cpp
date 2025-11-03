#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    
    ll T = 0;
    int front = 0;
    
    while (front < n) {
        T++;
        // Attack the frontmost enemy with health > 0
        if (T % 3 == 0) {
            h[front] -= 3;
        } else {
            h[front] -= 1;
        }
        
        // If current enemy's health drops to 0 or below, move to next
        if (h[front] <= 0) {
            front++;
        }
    }
    
    cout << T << endl;
    return 0;
}