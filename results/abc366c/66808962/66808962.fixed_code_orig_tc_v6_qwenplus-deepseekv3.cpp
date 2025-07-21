#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
#include<map>
#include<cmath>
#include<math.h>
#include<queue>
#include <iomanip>
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
            m[x]++;
            if(m[x] == 1) ans++;
        }else if(n==2){
            cin >> x;
            if(m.count(x)){
                m[x]--;
                if(m[x] == 0) ans--;
            }
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}