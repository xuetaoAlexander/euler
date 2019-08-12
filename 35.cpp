/*************************************************************************
	> File Name: 35.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月12日 星期一 10时15分46秒
 ************************************************************************/

#include<iostream>
#include<cmath>
using namespace std;
#define max_n 1000000
int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; ++i) {
        if (!prime[i]) is_prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (i * is_prime[j] > max_n) break;
            prime[i * is_prime[j]] = 1;
            if (i % is_prime[j] == 0) break;
        }
    }
}

int is_val(int x) {
    int digits = floor(log10(x)) + 1;
    int tmp = x;
    for (int i = 0; i < digits; ++i) {
        tmp = (tmp % 10) * (int) pow(10, digits - 1) + tmp / 10;
        if (prime[tmp]) return 0;
    }

    return 1;
}

int main() {
    init();
    int cnt = 0;
    for (int i = 1; i <= prime[0]; ++i) {
        if (is_val(is_prime[i])) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
