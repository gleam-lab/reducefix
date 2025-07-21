#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

void Solve() {
    int Q;
    cin >> Q;
    
    unordered_map<int, int> freq; // Tracks how many times each number is present
    set<int> uniqueCount;         // Set to track unique numbers in the bag
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int x;
            cin >> x;
            freq[x]++;
            uniqueCount.insert(x);
        } 
        else if (type == 2) {
            int x;
            cin >> x;
            freq[x]--;
            if (freq[x] == 0) {
                uniqueCount.erase(x);
            }
        } 
        else { // type == 3
            cout << uniqueCount.size() << "\n";
        }
    }
}

int main() {
    fastIO();
    Solve();
    return 0;
}