#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> H(N);
    
    long long ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        // Calculate the full cycles of 3 attacks, each reducing the health by 3
        ans += H[i] / 3;
        // The remaining health after full cycles of 3
        H[i] %= 3;
        
        // If there's any remaining health, calculate additional attacks needed
        if (H[i] > 0) {
            // If T is a multiple of 3, we can add an additional 3 to the answer
            if (ans % 3 > 0) {
                ans += 3;
            } else {
                // Otherwise, we need to add one more attack
                ans += 1;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}