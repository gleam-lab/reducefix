#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD  = 1000000007;
constexpr int inf = 2000000000;
constexpr ll INF = 9200000000000000000;

int main(){
    unordered_set<int> uset; // Changed from set to unordered_set for faster access times
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        if(x == 1){
            int t; cin >> t;
            uset.insert(t); // Insert operation remains the same
        } else if(x == 2){
            int t; cin >> t;
            uset.erase(t); // Erase operation remains the same
        } else if(x == 3){
            cout << uset.size() << "\n"; // Size operation remains the same
        }
    }
}