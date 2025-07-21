#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    
    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }
    
    int t = 0;
    vector<int> changes(n, 0);
    
    for (int i = n - 1; i >= 0; i--) {
        if (health[i] % 3 == 0) {
            changes[i] = t;
        } else {
            int needed = health[i] / 3;
            changes[i] = t + needed * 3 + (health[i] % 3 == 1 ? 1 : 0);
        }
        
        if (i < n - 1 && changes[i + 1] % 3 != 0) {
            changes[i] += 1;
            t = changes[i];
        } else {
            t = changes[i];
        }
    }
    
    cout << t << endl;
    return 0;
}