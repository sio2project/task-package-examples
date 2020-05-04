#include <iostream>
using namespace std;

const int maxN = 2e5;
pair<int, int> edges[maxN + 7];
bool isLeaf[maxN + 7];

int main() {
    int n;
    cin >> n;
    
    for (int i = 2; i <= n; i++)
        isLeaf[i] = true;
        
    for (int i = 0; i < n - 1; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < i; j++) {
            if (edges[i].first == edges[j].first) {
                isLeaf[edges[i].first] = false;
            }
            if (edges[i].first == edges[j].second) {
                isLeaf[edges[i].first] = false;
            }
            if (edges[i].second == edges[j].first) {
                isLeaf[edges[i].second] = false;
            }
            if (edges[i].second == edges[j].second) {
                isLeaf[edges[i].second] = false;
            }
        }
    }

    int leaves = 0;
    for (int i = 1; i <= n; i++) {
        if (isLeaf[i])
            leaves++;
    }
    cout << leaves << "\n";
}
