#include<iostream>
#include<map>
using namespace std;
using ll = long long;

int main(){
    map<int,int> m;
    int q;
    cin >> q;

    for(int i=0;i<q;i++){
        int n, x;
        cin >> n;

        if(n == 1){
            cin >> x;
            m[x]++;
        } else if(n == 2){
            cin >> x;
            m[x]--;
        } else {
            // Count number of distinct integers with count > 0
            int distinct = 0;
            for(auto& p : m){
                if(p.second > 0) distinct++;
            }
            cout << distinct << endl;
        }
    }
    return 0;
}