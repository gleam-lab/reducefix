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
    set<int> s; // Use set instead of map for better performance
    int q;
    cin >> q;

    for(int i=0;i<q;i++){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            s.insert(x); // Insert the ball directly into the set
        }else if(n==2){
            cin >> x;
            s.erase(s.find(x)); // Erase the ball from the set
        }else{
            cout << s.size() << endl; // The size of the set represents the number of unique integers
        }
    }

    return 0;
}