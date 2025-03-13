#include <bits/stdc++.h>
using namespace std;

void fcfs(vector<pair<int, int>> &v, int n) {
    sort(v.begin(), v.end());
    vector<int> ct(n), tat(n), wt(n);
    int time = 0;
    for (int i = 0; i < n; i++) {
        int arrival = v[i].first;
        int burst = v[i].second;
        if (time < arrival) {
            time = arrival;
        }
        time += burst;
        ct[i] = time;
        tat[i] = ct[i] - arrival;
        wt[i] = tat[i] - burst;
    }
    double avg_tat = accumulate(tat.begin(), tat.end(), 0.0) / n;
    double avg_wt = accumulate(wt.begin(), wt.end(), 0.0) / n;
    cout << "Average Turn Around Time (TAT): " << avg_tat << endl;
    cout << "Average Waiting Time (WT): " << avg_wt << endl;
}

int main() {
    int n = 5;
    vector<pair<int, int>> v;
    v = {{0, 4}, {1, 3}, {2, 1}, {3, 5}, {4, 2}};
    fcfs(v, n);
    return 0;
}
