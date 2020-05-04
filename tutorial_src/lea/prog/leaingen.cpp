#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

#include "oi.h"

using namespace std;

const string id = "lea";

oi::Random RG(0xC0FFEE);

const int maxN = 2e5;

int randomUIntInRange(int a, int b) {
    unsigned res = RG.randUInt();
    return res % (b - a + 1) + a;
}

struct Test {
    int n;
    vector<pair<int, int>> edges;
    
    Test(int _n) : n(_n) {}
    
    void print(int no, char *letter) {
        assert('a' <= *letter && *letter <= 'z');
        string name = id + to_string(no) + *letter + ".in";
        cerr << "Printing to file: " << name << "\n";
        ofstream outFile(name);
        outFile << n << "\n";
        for (auto edge : edges) {
            outFile << edge.first << " " << edge.second << "\n";
        }
        outFile.close();
        (*letter)++;
    }
};

// Shuffles vertices indexes and edges order
void shuffle(Test *test) {
    RG.randomShuffle(test->edges.begin(), test->edges.end());
    for (int i = 0; i < test->n - 1; i++) {
        if (randomUIntInRange(0, 1)) {
            swap(test->edges[i].first, test->edges[i].second);
        }
    }
    
    vector<int> mapping;
    for (int i = 0; i <= test->n; i++) {
        mapping.push_back(i);
    }
    RG.randomShuffle(mapping.begin() + 1, mapping.end());
    
    for (int i = 0; i < test->n - 1; i++) {
        test->edges[i] = make_pair(mapping[test->edges[i].first], mapping[test->edges[i].second]);
    }
}

// Shuffles nodes indexes until vertex 1 has degree equal to one or not.
// Works only when about half of vertices are leaves,
// otherwise shuffling might take really long.
Test forceRootDegree(Test test, bool forceToOne) {
    while (true) {
        int rootDegree = 0;
        for (int i = 0; i < test.n - 1; i++) {
            if (test.edges[i].first == 1 || test.edges[i].second == 1) {
                rootDegree++;
            }
        }
        if (rootDegree == 1 && forceToOne)
            break;
        if (rootDegree > 1 && !forceToOne)
            break;
        shuffle(&test);
    }
    return test;
}

// Path and star tests have a probability close to 1
// that root has/has not the degree we want.
// We trust it, worst case scenario inwer will inform us we are wrong.

Test path(int _n, bool rootDegreeIsOne) {
    Test result = Test(_n);
    for (int i = 2; i <= result.n; i++) {
        result.edges.push_back({i-1, i});
    }

    if (!rootDegreeIsOne)
        shuffle(&result);

    return result;
}

Test star(int _n, bool rootDegreeIsOne) {
    Test result = Test(_n);
    for (int i = 2; i <= result.n; i++) {
        result.edges.push_back({1, i});
    }

    if (rootDegreeIsOne)
        shuffle(&result);

    return result;
}

// Binary tree and random tests have a probability close to 0.5
// that the root has/has not the degree we want.
// Therefor we can safely shuffle indexes till we get the value we want.

Test binaryTree(int _n) {
    Test result = Test(_n);
    for (int i = 2; i <= result.n; i++) {
        result.edges.push_back({i/2, i});
    }

    shuffle(&result);
    return result;
}

Test random(int _n) {
    Test result = Test(_n);
    for (int i = 2; i <= result.n; i++) {
        result.edges.push_back(make_pair(randomUIntInRange(1, i-1), i));
    }

    shuffle(&result);
    return result;
}

int main() {
    
    { // Test group 1.
        int group = 1;
        char c = 'a';
        RG.setSeed(1);
        random(100).print(group, &c);
        random(92).print(group, &c);
        path(100, false).print(group, &c);
        star(100, true).print(group, &c);
        binaryTree(100).print(group, &c);
    }
    
    { // Test group 2.
        int group = 2;
        char c = 'a';
        // przypilnować by root nie był liściem
        RG.setSeed(2);
        forceRootDegree(random(maxN), false).print(group, &c);
        forceRootDegree(random(maxN - 1337), false).print(group, &c);
        path(maxN, false).print(group, &c);
        star(maxN, false).print(group, &c);
        forceRootDegree(binaryTree(maxN), false).print(group, &c);
    }
    
    { // Test group 3.
        int group = 3;
        char c = 'a';
        RG.setSeed(3);
        random(maxN).print(group, &c);
        random(maxN-1337).print(group, &c);
        forceRootDegree(random(maxN), true).print(group, &c);
        path(maxN, true).print(group, &c);
        star(maxN, true).print(group, &c);
        binaryTree(maxN).print(group, &c);
    }
    
}


