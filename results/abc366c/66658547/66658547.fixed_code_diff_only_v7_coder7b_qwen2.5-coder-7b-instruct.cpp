#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD  = 1000000007;
constexpr int inf = 2000000000;
constexpr ll INF = 9200000000000000000;
int main(){
    unordered_set<int> uset; // Using unordered_set for faster insert and erase operations
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if(x == 1){
            int t; cin >> t;
            uset.insert(t); // Inserting element into the unordered_set
        } else if(x == 2){
            int t; cin >> t;
            uset.erase(t); // Erasing element from the unordered_set
        } else {
            cout << uset.size() << "\n"; // Printing the size of the unordered_set
        }
    }
    return 0;
}