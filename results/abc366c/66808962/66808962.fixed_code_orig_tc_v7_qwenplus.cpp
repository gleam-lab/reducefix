#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<map>
#include<cmath>
#include<math.h>
#include<queue>
#include <iomanip> //setprecisionを使うため
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    map<int,int> m;
    int q;
    cin >> q;

    int ans=0;
    for(int i=0;i<q;i++){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            if(m[x] == 0) { // Check if count is 0 instead of !m.count(x)
                ans++;
            }
            m[x]++;
        }else if(n==2){
            cin >> x;
            m[x]--;
            if(m[x] == 0) ans--;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}