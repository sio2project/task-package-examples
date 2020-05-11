#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

#include "oi.h"

using namespace std;

const int maxN = 2e5;

bool visited[maxN + 2];
map<pair<int, int>, int> edgeMap;
vector<int> edge[maxN + 2];

void dfs(int n) {
    visited[n] = true;
    for (auto v : edge[n]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    oi::Scanner input_file(stdin, oi::PL);

    int n = input_file.readInt(1, maxN);
    int rootDegree = 0;
    input_file.readEoln();
    for (int i = 0; i < n - 1; i++) {
        int u = input_file.readInt(1, maxN);
        input_file.readSpace();
        int v = input_file.readInt(1, maxN);
        input_file.readEoln();
        if (u == v)
            input_file.error("Invalid edge - loop");
        if (u > v)
            swap(u, v);
        if (edgeMap[make_pair(u, v)] == 1)
            input_file.error("Invalid edge - repeating edge");
        edgeMap[make_pair(u, v)] = 1;
        edge[u].push_back(v);
        edge[v].push_back(u);
        if (u == 1)
            rootDegree++;
    }
    input_file.readEof();

    dfs(1);
    // Checking if graph is connected.
    // Graph with n vertices and n-1 edges is a tree
    // if and only if it is connected.
    for (int i = 1; i <= n; i++) {
        if (!visited[i])
            input_file.error("Graph is not a tree");
    }

    bool package[3];
    for (int i = 0; i < 3; i++)
        package[i] = false;
    if (n <= 100)
        package[0] = true;
    if (rootDegree != 1)
        package[1] = true;
    package[2] = true;

    printf("OK | ");
    for (int i = 0; i < 3; i++)
        printf("%c", (package[i] ? (char)('0' + i + 1) : '.'));
    printf(" | n=%d\n", n);
    return 0;
}
