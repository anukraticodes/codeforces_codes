#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

// Union-Find class
class UnionFind {
private:
    vector<int> parent, rank, setSize;
    int numSets;

public:
    UnionFind(int N) {
        numSets = N;
        parent.resize(N);
        rank.resize(N, 0);
        setSize.resize(N, 1);
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }

    int findSet(int i) {
        if (parent[i] == i) return i;
        return parent[i] = findSet(parent[i]); // Path compression
    }

    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) {
            parent[y] = x;
            setSize[x] += setSize[y];
        } else {
            parent[x] = y;
            setSize[y] += setSize[x];
            if (rank[x] == rank[y]) rank[y]++;
        }
        numSets--;
    }

    int sizeOfSet(int i) {
        return setSize[findSet(i)];
    }

    int numDisjointSets() {
        return numSets;
    }
};

// Fast input handling
class FastIO {
public:
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
};

// Main function
int main() {
    FastIO io;
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;

        vector<int> first(n), second(n), third(n);
        for (int i = 0; i < n; i++) {
            cin >> first[i];
            first[i]--; // 0-based indexing
        }
        for (int i = 0; i < n; i++) {
            cin >> second[i];
            second[i]--; // 0-based indexing
        }
        for (int i = 0; i < n; i++) {
            cin >> third[i];
            third[i]--; // 0-based indexing
        }

        UnionFind uf(n);
        for (int i = 0; i < n; i++) {
            uf.unionSet(first[i], second[i]);
        }

        unordered_set<int> set;
        for (int i = 0; i < n; i++) {
            set.insert(uf.findSet(i));
        }

        for (int i = 0; i < n; i++) {
            if (third[i] != -1) {
                set.erase(uf.findSet(third[i]));
            }
        }

        int pow = 0;
        for (int x : set) {
            if (uf.sizeOfSet(x) > 1) {
                pow++;
            }
        }

        int ans = 1;
        for (int i = 0; i < pow; i++) {
            ans = (2LL * ans) % MOD;
        }

        cout << ans << "\n";
    }

    return 0;
}
