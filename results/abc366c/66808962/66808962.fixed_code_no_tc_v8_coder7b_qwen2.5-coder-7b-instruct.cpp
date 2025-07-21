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
    set<int> s; // Using set to automatically handle duplicates and maintain sorted order
    int q;
    cin >> q;

    int ans=0;
    for(int i=0;i<q;i++){
        int n,x;
        cin >> n;

        if(n==1){
            cin >> x;
            s.insert(x); // Inserting element into the set
        }else if(n==2){
            cin >> x;
            s.erase(s.find(x)); // Removing element from the set
        }else{
            cout << s.size() << endl; // Size of the set gives the number of unique elements
        }
    }
    return 0;
}