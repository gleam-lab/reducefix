#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long T = 0;
    long long total_health = 0;
    
    for (int i = 0; i < n; i++) {
        long long health;
        cin >> health;
        total_health += health;
    }
    
    // Calculate the number of full 3-damage attacks we can perform
    long long k = total_health / 3;
    long long r = total_health % 3;
    
    // We can use k operations of 3 damage each, and then we need to finish with r + 1 operations
    T = k + r + 1;
    
    cout << T << endl;
    return 0;
}