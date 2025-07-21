#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<long long> A(N + 1);
    for (int i = 0; i < N; ++i) {
        cin >> A[i + 1];
    }
    
    map<long long, vector<int>> index;
    for (int i = 0; i < N; ++i) {
        index[A[i]].push_back(i + 1);
    }
    
    for (int j = 0; j < Q; ++j) {
        long long b;
        int k_j;
        cin >> b >> k_j;
        
        if (index.lower_bound(b) == index.end()) {
            cout << 0 << endl; // No point in A is within distance b from B_j
            continue;
        }
        
        auto it = index.lower_bound(b);
        auto it_prev = prev(it);
        
        // We need to find the k_j-th smallest distance from A to B_j
        int count = 0;
        while (it != index.end()) {
            if (count + it->second.size() >= k_j) {
                cout << abs(it->first - b) << endl;
                break;
            }
            count += it->second.size();
            ++it;
        }
    }
    
    return 0;
}