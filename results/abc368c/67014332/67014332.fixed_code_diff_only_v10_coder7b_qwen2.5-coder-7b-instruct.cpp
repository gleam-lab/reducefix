#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    
    // Read health values
    for(int i = 0; i < n; ++i)
        cin >> health[i];
    
    int t = 0;
    
    // Process each enemy
    for(int i = 0; i < n; ++i) {
        while(health[i] > 0) {
            ++t;
            // Decrease health based on whether t is divisible by 3
            health[i] -= (t % 3 == 0) ? 3 : 1;
        }
    }
    
    // Print the total number of turns taken
    cout << t << endl;
    return 0;
}