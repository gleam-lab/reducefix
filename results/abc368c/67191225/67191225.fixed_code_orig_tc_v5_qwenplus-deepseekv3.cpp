#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (int i = 0; i < N; ++i) {
        ll h = H[i];
        // Calculate the number of full triple attacks (1,1,3)
        ll full_cycles = h / 5;
        T += full_cycles * 3;
        h %= 5;
        
        // Handle remaining hits
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h -= 3;
            } else {
                h -= 1;
            }
        }
    }
    cout << T << endl;
    return 0;
}