#include<bits/stdc++.h>
using namespace std;
int n, q; // 假设输入是整数类型的变量
int x[200005], p[200005]; // 将变量类型改为整数类型
int sum[100005]; // 可以考虑使用数组来存储和，以避免使用临时变量

// 处理输入数据并进行计算
void processInput(int* numbers, int size) {
    for (int i = 0; i < size; ++i) { // 遍历每个数字并转换为整数
        cin >> x[i]; // 获取每个数字的值
    }
    // ... 其他逻辑处理 ...
}

int main() {
    cin >> n; // 获取数据点的数量
    processInput(x, n); // 处理输入数据
    int result; // 假设输出为整数类型变量
    // ... 进行计算和输出逻辑 ...
    cout << result << endl; // 输出结果
    return 0;
}