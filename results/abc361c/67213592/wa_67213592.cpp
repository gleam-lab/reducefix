#include <iostream>
#include <unordered_map>
using namespace std;
#include <algorithm> 
#include<bits/stdc++.h>
#include <map> 
#include <set> 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; 
    cin >> n >> k  ;
    vector <int> v(n);
    for (auto& val : v){
        cin >> val ;
    }
    sort(v.begin() , v.end());
    // 1  3 4 5 9 

    int left = 0 ; 
    int right = n-1 ; 
    int best ; 
    while (k--){
        if (v[right] - v[left+1] <  v[right-1] - v[left]){
            left++ ; 
        }
        else{
            right-- ;
        }
    }

    cout << v[right] - v[left] ;}