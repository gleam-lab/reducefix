#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    
    long long totalTurns = 0;
    rep(i, n) {
        int currentHealth = health[i];
        
        // Calculate the number of full 3's and 1's needed
        int fullThrees = currentHealth / 3;
        int remainder = currentHealth % 3;
        
        // If there's a remainder, add 1 more turn because we can't have part of a turn
        if (remainder > 0) fullThrees++;
        
        // Add the full 3's and the possible 1's turn
        totalTurns += fullThrees + remainder;
    }
    
    cout << totalTurns << endl;
    return 0;
}