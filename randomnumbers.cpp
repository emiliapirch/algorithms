#include <bits/stdc++.h>
using namespace std;

int main() {
    int seed;
    cin >> seed;

    mt19937_64 gen(seed); // !

    int a = gen() % (int)5e4;
    int b = gen() % (int)5e4;

    cout << a << " " << b;
}

