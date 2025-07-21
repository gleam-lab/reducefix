#include<bits/stdc++.h>
using namespace std;
int n,q;
int sum[200005]; //假设数组大小足够存储所有整数

int main(){
    cin >> n; // 读入序列长度
    for(int i = 0; i < n; i++){ // 读入每个整数序列
        int x; // 读取每个整数
        cin >> x; // 读入每个整数序列的元素
        // 在这里应该添加相应的处理逻辑来修复整数之间的匹配问题
        // 例如：可以通过某种方式修复缺失的数字或进行其他处理
        // ...
    }
    // 处理完序列后进行输出
    cout << sum[q] - sum[q-1] << endl; // 这里假设 q 表示序列中的位置，从 1 开始计数
}