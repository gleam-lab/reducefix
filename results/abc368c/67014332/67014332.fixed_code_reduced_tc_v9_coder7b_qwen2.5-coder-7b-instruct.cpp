#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> health(n);
    for(int i = 0; i < n; ++i) {
        cin >> health[i];
    }

    long long t = 0;
    for(int i = 0; i < n;) {
        int j = i;
        // Find the first enemy with positive health
        while(j < n && health[j] <= 0) {
            ++j;
        }
        if(j == n) break; // No more enemies with positive health

        int minHealth = INT_MAX;
        // Find the minimum health among the remaining enemies
        for(; j < n; ++j) {
            minHealth = min(minHealth, health[j]);
        }

        // Calculate how many turns we need to deal with this minimum health
        t += ceil((double)minHealth / 3);

        // Decrease the health of all remaining enemies
        for(j = i; j < n; ++j) {
            if(health[j] > 0) {
                health[j] -= minHealth;
            }
        }

        // Move to the next group of enemies
        i = j;
    }

    cout << t << endl;
    return 0;
}