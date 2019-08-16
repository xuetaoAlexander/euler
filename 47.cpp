/*************************************************************************
	> File Name: 47.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月16日 星期五 19时31分05秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define max_n 1000000
int prime[max_n + 5] = {0};

void init() {
    for (int i = 2; i <= max_n; ++i) {
        if (prime[i]) continue;
        for (int j = i; j <= max_n; j += i) {
            prime[j] += 1;
        }
    }
    return;
}

int main() {
    init();
    for (int i = 2; i < max_n; i++) {
        int flag = 1;
        for (int k = 0; k < 4 && flag; k++) {
            flag = (prime[i + k] == 4);
        }
        if (flag) {
            cout << i << endl;
            break;   
        }
    }

    return 0;
}
