#include <bits/stdc++.h>
using namespace std;


int main(){
   double a, b, c, d, cou;
   int N;
   cin >> N;
   a = 0;
   b = 0;
   cou = 0;
   for(int i = 0; i < N; i++){
     cin >> c >> d;
     cou += sqrt((a-c)*(a-c) + (b-d)*(b-d));
     a = c;
     b = d;
   }
   cou += sqrt(a*a + b*b);
   cout << cou << endl;
 }  
 
  


