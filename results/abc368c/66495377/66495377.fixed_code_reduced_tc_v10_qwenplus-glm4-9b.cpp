#include <iostream>
using namespace std;
using ll = long long;

int main() {
    int n;
    ll t = 0;
    cin >> n;
    vector<ll> h(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        // Calculate the minimum number of attacks required to defeat this enemy
        t += (h[i] + 2) / 3;
    }

    cout << t << endl;
    return 0;
}