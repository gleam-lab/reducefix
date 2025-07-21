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
    set<int> s;
    int q;
    cin >> q;

    while(q--){
        int n;
        cin >> n;
        if(n==1){
            int x;
            cin >> x;
            s.insert(x);
        }else if(n==2){
            int x;
            cin >> x;
            s.erase(s.find(x));
        }else{
            cout << s.size() << endl;
        }
    }
    return 0;
}