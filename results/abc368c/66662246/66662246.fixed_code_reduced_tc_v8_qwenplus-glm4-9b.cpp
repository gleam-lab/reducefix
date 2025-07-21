#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> health(n);
    for (int i = 0; i < n; ++i) {
        cin >> health[i];
    }
    
    long long total_turns = 0;
    
    for (int h : health) {
        while (h > 0) {
            if (total_turns % 3 == 0) {
                h = max(h - 3, 0);
            } else {
                h = max(h - 1, 0);
            }
            total_turns++;
        }
    }
    
    cout << total_turns << endl;
    return 0;
}