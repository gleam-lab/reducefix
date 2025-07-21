#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    long long t = 0;
    for(int i = 0; i < n; ++i) {
        if(h[i] > 0) {
            t += h[i] / 3 + (h[i] % 3 != 0); // Calculate number of attacks needed
        }
    }

    cout << t << endl;
    return 0;
}