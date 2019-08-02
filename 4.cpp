/*************************************************************************
	> File Name: 4.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月02日 星期五 14时30分26秒
 ************************************************************************/

#include<iostream>
using namespace std;

 
int is_val(int x, int base) {
    int sum = 0, temp = x;
    while (x) {
        sum += sum * base + x % base;
        x /= base;
    }
    return sum == temp;
}

int main() {
    int ans = 0;
    for (int a = 100; a < 1000; a++) {
        for (int b = ans / a + 1; b <= a; ++b) {
            if (is_val(a * b, 10) && ans < a * b) ans = a * b;
        }
    }

    return 0;
}
