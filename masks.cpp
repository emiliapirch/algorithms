#include <bits/stdc++.h>
using namespace std;

constexpr int LIM = 21;
int t[LIM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, sum1, sum2;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < (1 << n); i++) {
        sum1 = sum2 = 0; 

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) 
                sum1 += t[j];
            else 
                sum2 += t[j];
        }

        if (sum1 == sum2) {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
}

