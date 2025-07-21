#include<iostream>
#include<map>
using namespace std;

int main(){
    map<int,int> m;
    int q;
    cin >> q;

    int ans = 0;
    for(int i=0; i<q; i++){
        int n, x;
        cin >> n;

        if(n == 1){
            cin >> x;
            if(m[x] == 0) { // If the count was zero before adding, it's a new distinct integer
                ans++;
            }
            m[x]++;
        }else if(n == 2){
            cin >> x;
            m[x]--;
            if(m[x] == 0) { // If the count drops to zero, decrement the distinct count
                ans--;
            }
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}