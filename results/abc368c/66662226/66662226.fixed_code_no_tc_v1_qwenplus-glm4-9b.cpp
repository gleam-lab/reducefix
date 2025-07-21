#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    long long t = 0;
    
    // Read health values
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    // Process each enemy
    for (int i = 0; i < n; ) {
        if (h[i] == 0) {
            // Skip enemies with zero or negative health
            i++;
            continue;
        }
        
        // Calculate the number of full attacks needed to reduce health to zero or below
        if (t % 3 == 0) {
            // If t is a multiple of 3, we can attack in multiples of 3
            t += h[i] / 3;
            h[i] %= 3;
        }
        
        // If t is not a multiple of 3, we can only attack in increments of 1 or 2
        if (h[i] > 0) {
            if (h[i] == 1 || h[i] % 3 == 1) {
                t += 1;
                h[i]--;
            } else if (h[i] % 3 == 2) {
                t += 2;
                h[i] -= 2;
            }
        }

        // If this enemy still has positive health, move to the next one
        if (h[i] > 0) {
            i++;
        }
    }

    // Output the final value of t
    cout << t << endl;
}