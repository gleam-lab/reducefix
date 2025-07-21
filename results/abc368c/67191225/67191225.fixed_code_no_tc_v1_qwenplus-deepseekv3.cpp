#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    ll T = 0;
    for (int i = 0; i < N; i++) {
        // The attacks on enemy i consist of cycles of 3 attacks (1, 1, 3)
        // The total damage per 3 attacks is 5
        ll full_cycles = H[i] / 5;
        T += full_cycles * 3;
        ll remaining_health = H[i] % 5;
        
        if (remaining_health > 0) {
            // The remaining health is 1 to 4
            // The attacks are 1, 1, 3, but we start at T mod 3
            // We need to find the minimal T' such that the sum of damages (considering T mod 3) >= remaining_health
            // Simulate the remaining attacks
            while (remaining_health > 0) {
                T++;
                if (T % 3 == 0) {
                    remaining_health -= 3;
                } else {
                    remaining_health -= 1;
                }
            }
        }
    }
    cout << T << endl;
    return 0;
}