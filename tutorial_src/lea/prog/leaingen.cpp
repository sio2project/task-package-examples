#include <iostream>
#include <fstream>
#include <algorithm>

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
        // open file id + no + letter + ".in"
        string name = id + to_string(no) + *letter + ".in";
        cerr << "Printing to file: " << name << "\n";
        (*letter)++;
        ofstream outFile(name);
        outFile << n << "\n";
        for (auto edge : edges) {
            outFile << edge.first << " " << edge.second << "\n";
        }
        outFile.close();
        
        // It's a good habbit to set seed after each test,
        // so that one test doesn't depend from previous ones.
        RG.setSeed(no);
    }
};

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

Test path(int _n) {
    Test result = Test(_n);
    for (int i = 2; i <= result.n; i++) {
        result.edges.push_back({i-1, i});
    }
    // korzeń ma st 1
    shuffle(&result);
    // teraz prawie na pewno nie
    return result;
}

Test star(int _n) {
    Test result = Test(_n);
    for (int i = 2; i <= result.n; i++) {
        result.edges.push_back({1, i});
    }
    // korzeń ma st >1
    shuffle(&result);
    // teraz prawie na pewno nie
    return result;
}

Test binaryTree(int _n) {
    Test result = Test(_n);
    for (int i = 2; i <= result.n; i++) {
        result.edges.push_back({i/2, i});
    }
    // korzeń ma 50/50 stopień 1 bądź >1
    shuffle(&result);
    return result;
}

Test random(int _n) {
    Test result = Test(_n);
    for (int i = 2; i <= result.n; i++) {
        result.edges.push_back(make_pair(randomUIntInRange(1, i-1), i));
    }
    // korzeń prawie na pewno ma stopień >1
    shuffle(&result);
    // teraz raczej >1, ale nie mam pojęcia jakie są prawdopodobieństwa
    return result;
}

int main() {
    
    { // Test group 1.
        int group = 1;
        char c = 'a';
        random(100).print(group, &c);
        random(92).print(group, &c);
        path(100).print(group, &c);
        star(100).print(group, &c);
        binaryTree(100).print(group, &c);
    }
    
    { // Test group 2.
        int group = 2;
        char c = 'a';
        // przypilnować by root nie był liściem
        random(maxN).print(group, &c);
        random(maxN - 1337).print(group, &c);
        path(maxN).print(group, &c);
        star(maxN).print(group, &c);
        binaryTree(maxN).print(group, &c);
    }
    
    { // Test group 3.
        int group = 3;
        char c = 'a';
        random(maxN).print(group, &c); // v trzeba przekminić, czy nie lepiej nadawać te set seedy, a jednocześnie jakoś deterministycznie
        random(maxN-1337).print(group, &c); // te dwa testy wyplują inne wartości tylko dlatego, że ich seedy na początku są różne
        path(maxN).print(group, &c);
        star(maxN).print(group, &c);
        binaryTree(maxN).print(group, &c);
    }
    
}


