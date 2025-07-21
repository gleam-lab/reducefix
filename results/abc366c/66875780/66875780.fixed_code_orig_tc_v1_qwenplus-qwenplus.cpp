#include <iostream>
#include <unordered_map>

using namespace std;

void Solve() {
    long long Q;
    cin >> Q;
    
    unordered_map<long long, long long> freq;
    long long distinctCount = 0;

    while (Q--) {
        long long type;
        cin >> type;

        if (type == 1) {
            long long x;
            cin >> x;
            if (freq[x] == 0) {
                ++distinctCount;
            }
            ++freq[x];
        } 
        else if (type == 2) {
            long long x;
            cin >> x;
            --freq[x];
            if (freq[x] == 0) {
                --distinctCount;
            }
        } 
        else if (type == 3) {
            cout << distinctCount << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Solve();

    return 0;
}