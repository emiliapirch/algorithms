#include <bits/stdc++.h>
using namespace std;

constexpr int LIM = 1e6 + 10;
int arr[LIM];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i=0; i<n; i++)
        cin >> arr[i];

    sort(arr, &arr[n-1]);

    int l = 1, r = n, m, x = 3;

    while (l < r) {
        m = (l + r) / 2;

        if (x > arr[m])
            l = m + 1;

        else
            r = m;
    }

    if (arr[r] == x) cout << "exists\n";
    else cout << "does not exist\n";
}
