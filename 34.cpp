/*************************************************************************
	> File Name: 34.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月02日 星期五 18时07分04秒
 ************************************************************************/

#include<iostream>
#define max_n 2540160 
using namespace std;

int factorial(int i) {
    if (i == 0) {
        return 1;
    }
    return factorial(i - 1) * i;
}
int num[10];

void init() {
    num[0] = 1;
    for (int i = 1; i < 10; i++) {
        num[i] = num[i - 1] * i;
    }
}
int is_val(int i) {
    int temp = i, sum = 0;
    while (i) {
        sum += num[i % 10];
        i /= 10;
    }
    return sum == temp;
}

int main() {
    int sum = 0;
    init();
    for (int i = 3; i < max_n; ++i) {
        if (is_val(i)) sum += i;
    }
    cout << sum << endl;


    return 0;
}
