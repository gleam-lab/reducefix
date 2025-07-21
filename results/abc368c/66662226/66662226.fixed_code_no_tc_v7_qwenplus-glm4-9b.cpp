#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long h[n];
    long long ans = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        // Calculate the number of full 3 attacks needed
        ans += h[i] / 3;
        // Calculate the remainder health after full 3 attacks
        h[i] %= 3;

        // If there's a remainder, we need to attack with 1 or 2 more attacks
        if (h[i] > 0) {
            ans += 1 + h[i]; // 1 attack for any remainder and up to 2 more if needed
        }
    }
    
    cout << ans << endl;
    return 0;
}