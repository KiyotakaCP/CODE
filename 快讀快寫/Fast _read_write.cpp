#include <bits/stdc++.h>
using namespace std;

const size_t msize = 200000;
char buf[msize], *p1 = buf, *p2 = buf;
inline char getc() {
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, msize, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
    int x = 0, f = 1;
    char ch = getc();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getc();
    }
    while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getc();
    return x * f;
}
void write(int x) {
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}