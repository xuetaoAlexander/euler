/*************************************************************************
	> File Name: 24.recursion.dict.cpp
	> Author: XuetaoZhang
	> Mail: yselie06@gmail.com
	> Created Time: 2019年08月26日 星期一 10时12分45秒
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
#define max_n 10

int p[max_n + 5] = {0};
int arr[max_n + 5] = {0};

int cnt = 0;
void perm(int head, int tail) {
    if (head == tail + 1) {
        cnt++;
        if (cnt == 1000000) {
            for (int i = 0; i <= tail; i++) {
                cout << arr[i];
            }
            cout << endl;
        }
    } else {
        for (int i = 0; i <= tail; i++) {
            if (p[i] == 0) {
                arr[head] = i;
                p[i] = 1;
                perm(head + 1 ,tail);
                p[i] = 0;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    perm(0, n);
    return 0;
}
