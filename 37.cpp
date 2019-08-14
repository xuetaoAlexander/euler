/*************************************************************************
	> File Name: 37.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月09日 星期五 19时10分14秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#define max_n 1000000 
using namespace std;

int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {1,1};

void init() {
    for (int i = 2; i <= max_n; ++i) {
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; ++j) {
            if (i * prime[j] > max_n) break;
            is_prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }

    return;
}

int is_val(int x) {
    int digit = floor(log10(x)) + 1;
    int flag = 0;
    for (int i = digit - 1; i > 0; --i) {
        if (!is_prime[x % (int)pow(10, i)] && !is_prime[x / (int)pow(10, digit - i)]) flag++ ;
    }
    if (flag == digit - 1) return 1;
    return 0;
}

int main() {
    init();
    int sum = 0;
    for (int i = 1; i <= max_n; ++i) {
        if (!is_prime[i] && is_val(i)) {
            if (i > 7) {
                printf("i = %d\n", i);
                sum += i;
            }
        }
    }
    printf("%d\n", sum);

    return 0;
}
