#include <bits/stdc++.h>
using namespace std;

constexpr int base = 4;
int tree[base * 2];

void settree(int v = 1) {
    if (tree[v] != 0)
        return;

    settree(v * 2);
    settree(v * 2 + 1);

    tree[v] = tree[2 * v] + tree[2 * v + 1]; 
}

int query(int a, int b) {
    a += base - 1 - 1;
    b += base - 1 + 1;

    int res = 0;

    while (a / 2 != b / 2) {
        if (a % 2 == 0) {
            res += tree[a + 1];
        }

        if (b % 2 != 0) {
            res += tree[b - 1];
        }

        a /= 2;
        b /= 2;
    }

    return res;
}

void update(int v, int x) {
    v += base - 1;
    tree[v] = x;

    while (v != 1) {
        v /= 2;
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }
}


int main() {
    int n, x, a, b;
    char c;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        tree[i + base] = x;
    }

    settree();

    while (1) { 
        cin >> c;

        if (c == 'z') {
            cin >> a >> b;
            update(a, b);

            for (int i = 1; i <= n; i++) {
                cout << tree[i + base - 1] << ' ';
            } 

            cout << endl;
        }

        if (c == 'p') {
            cin >> a >> b;
            cout << query(a, b) << '\n';
        }
    }

}
