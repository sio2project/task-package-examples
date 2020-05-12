#include <iostream>
using namespace std;

const int maxN = 2e5;
int degree[maxN + 7];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }

    int leaves = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1)
            leaves++;
    }
    cout << leaves << "\n";
}
