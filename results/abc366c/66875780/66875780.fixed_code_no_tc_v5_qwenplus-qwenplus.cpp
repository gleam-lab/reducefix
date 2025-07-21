#include <iostream>
#include <unordered_map>
using namespace std;

// Fast IO setup
void fastIO() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void Solve() {
    long long Q;
    cin >> Q;
    
    unordered_map<long long, int> countMap;  // Tracks count of each number
    int distinctCount = 0;  // Tracks the current number of distinct integers
    
    while (Q--) {
        int type;
        cin >> type;
        
        if (type == 1) {
            long long x;
            cin >> x;
            if (countMap[x] == 0) {
                distinctCount++;
            }
            countMap[x]++;
        } 
        else if (type == 2) {
            long long x;
            cin >> x;
            countMap[x]--;
            if (countMap[x] == 0) {
                distinctCount--;
            }
        } 
        else {  // type == 3
            cout << distinctCount << "\n";
        }
    }
}

int main() {
    fastIO();
    Solve();
    return 0;
}