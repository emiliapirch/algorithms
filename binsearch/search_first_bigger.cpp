#include <bits/stdc++.h>
using namespace std;

int arr[1000];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> x;

    int l = 1, r = n, m;

    while (l < r) {
        cout << "l: " << l << " r: " << r << endl;
        m = (l + r) / 2;

        if (arr[m - 1] <= x)
            l = m + 1;
        else 
            r = m;
    }

    cout << arr[l - 1] << endl;
}

