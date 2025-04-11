#include <iostream>
#include <set>
#include <map>

using namespace std;

class CFG {
private:
    map<char, set<char>> firstSet, followSet;

public:
    CFG() {
        computeFirst();
        computeFollow();
    }

    void computeFirst() {
        firstSet['S'] = {'a', 'b', '(', 'c'};
        firstSet['A'] = {'a', '#'}; // '#' represents ε (epsilon)
        firstSet['B'] = {'b', '#'};
        firstSet['C'] = {'(', 'c'};
        firstSet['D'] = {'a', '('};
    }

    void computeFollow() {
        followSet['S'] = {')', '$'};
        followSet['A'] = {'b', '(', ')', '$'};
        followSet['B'] = {'c', ')', '$'};
        followSet['C'] = {')', '$'};
        followSet['D'] = {')', '$'};
    }

    void printSet(const string &name, map<char, set<char>> &sets) {
        for (const auto &entry : sets) {
            cout << name << "(" << entry.first << ") = { ";
            for (char ch : entry.second) {
                if (ch == '#')
                    cout << "ε "; // Print epsilon properly
                else
                    cout << ch << " ";
            }
            cout << "}\n";
        }
    }

    void displayResults() {
        printSet("First", firstSet);
        printSet("Follow", followSet);
    }
};

int main() {
    CFG cfg;
    cfg.displayResults();
    return 0;
}
