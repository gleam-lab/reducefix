#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD  = 1000000007;
constexpr int inf = 2000000000;
constexpr ll INF = 9200000000000000000;

int main(){
    map<int, int> freq; // frequency count of each number
    int q;
    cin >> q;
    
    while(q--){
        int x;
        cin >> x;
        
        if(x == 1){
            int t;
            cin >> t;
            freq[t]++;
        }
        else if(x == 2){
            int t;
            cin >> t;
            freq[t]--;
            if(freq[t] == 0){
                freq.erase(t);
            }
        }
        else if(x == 3){
            cout << freq.size() << "\n";
        }
    }
}