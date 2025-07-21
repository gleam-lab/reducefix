#include <iostream>
#include <vector>

using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    
    ll total attacks = 0;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        totalattacks += (3 * h[i] + 2) / 3;
    }
    
    cout << totalattacks << endl;
    return 0;
}