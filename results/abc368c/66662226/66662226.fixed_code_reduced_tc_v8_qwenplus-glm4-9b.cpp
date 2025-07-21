#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    ll ans = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    for (int i = 0; i < N; ++i) {
        while (H[i] > 0) {
            if (ans % 3 == 0 && H[i] >= 3) {
                H[i] -= 3;
            } else {
                H[i]--;
            }
            ans++;
        }
    }
    
    cout << ans << endl;
}