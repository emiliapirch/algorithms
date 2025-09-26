#include <bits/stdc++.h>
using namespace std;

// podanie maksymalnej liczby w przedziale od a do b

// odpowiedz na zapytania tak jak sumy prefiksowe tylko tez z mozliwoscia aktualiacji
// zlozonosc log(n)
// drzewo binarne
// algorytmy od lisci

constexpr int base = 1 << 17; // ilosc lisci
int tree[2 * base];

void update(int v, int x) { 
    v += base;
    tree[v] = x;

    v/=2; // ojciec

    while(v) {
        tree[v] = max(tree[2*v], tree[2*v+1]);
        v/=2;
    }
}

int query(int a, int b) { 
    a += base -1; // przedzial otwarty
    b += base +1;

    int res = 0;
    
    // dopoki nie maja tego samego ojca 
    while (a/2 != b/2) {
        // if(!(a&1))

        if (a%2 == 0) 
            res = max(res, tree[a+1]);
        if (b%2 != 0) 
            res = max(res, tree[b-1]);

        a/=2; 
        b/=2;
    }
    return res;
}


int main() {
    int q, t, a, b;
    cin >> q;

    // t == 1 : podaj maksimum
    // t == 0 : zmiana wartosci elementu a na wartosc b
    while (q--) {
        cin >> t >> a >> b;
        if (t == 0)  update(a, b);
        else cout << query(a, b) << '\n';
    }
}

