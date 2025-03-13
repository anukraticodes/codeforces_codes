#include <bits/stdc++.h>
using namespace std;

struct Operation {
    char type;
    int transaction;
    char dataItem;
};

bool isConflict(const Operation& op1, const Operation& op2) {
    return op1.dataItem == op2.dataItem &&
           op1.transaction != op2.transaction &&
           (op1.type == 'W' || op2.type == 'W');
}

bool hasCycle(int node, vector<bool>& visited, vector<bool>& recStack, unordered_map<int, vector<int>>& graph) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor] && hasCycle(neighbor, visited, recStack, graph))
            return true;
        else if (recStack[neighbor])
            return true;
    }

    recStack[node] = false;
    return false;
}

void topologicalSort(int node, unordered_map<int, vector<int>>& graph, vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            topologicalSort(neighbor, graph, visited, topoStack);
        }
    }

    topoStack.push(node);
}

bool isConflictSerializable(const vector<Operation>& schedule) {
    unordered_map<int, vector<int>> precedenceGraph;
    unordered_set<int> transactions;

    for (int i = 0; i < schedule.size(); ++i) {
        transactions.insert(schedule[i].transaction);
        for (int j = i + 1; j < schedule.size(); ++j) {
            if (isConflict(schedule[i], schedule[j])) {
                precedenceGraph[schedule[i].transaction].push_back(schedule[j].transaction);
            }
        }
    }

    vector<bool> visited(transactions.size() + 1, false);
    vector<bool> recStack(transactions.size() + 1, false);

    for (int transaction : transactions) {
        if (!visited[transaction]) {
            if (hasCycle(transaction, visited, recStack, precedenceGraph)) {
                return false;
            }
        }
    }

    stack<int> topoStack;
    visited.assign(transactions.size() + 1, false);

    for (int transaction : transactions) {
        if (!visited[transaction]) {
            topologicalSort(transaction, precedenceGraph, visited, topoStack);
        }
    }

    cout << "Topological Order of Transactions (Serial Schedule): ";
    while (!topoStack.empty()) {
        cout << topoStack.top() << " ";
        topoStack.pop();
    }
    cout << endl;

    return true;
}

int main() {
    vector<Operation> schedule = {
    {'R', 1, 'A'},
    {'W', 2, 'A'},
    {'R', 1, 'B'},
    {'W', 2, 'B'}
};


    if (isConflictSerializable(schedule)) {
        cout << "The schedule is conflict serializable." << endl;
    } else {
        cout << "The schedule is not conflict serializable." << endl;
    }

    return 0;
}
