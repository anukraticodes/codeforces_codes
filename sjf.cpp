#include <bits/stdc++.h>
using namespace std;

void sjf(vector<pair<int, int>> &v, int n) {
    sort(v.begin(), v.end());
    vector<int> ct(n), tat(n), wt(n);
    vector<bool> completed(n, false);
    int time = 0, completed_count = 0;

    while (completed_count < n) {
        int idx = -1;
        int min_burst_time = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (!completed[i] && v[i].first <= time && v[i].second < min_burst_time) {
                min_burst_time = v[i].second;
                idx = i;
            }
        }
        if (idx != -1) {
            time += v[idx].second;
            ct[idx] = time;
            completed[idx] = true;
            completed_count++;
        } else {
            time++;
        }
    }

    double total_tat = 0, total_wt = 0;
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - v[i].first;
        wt[i] = tat[i] - v[i].second;
        total_tat += tat[i];
        total_wt += wt[i];
    }

    cout << "Average Turn Around Time (TAT): " << total_tat / n << endl;
    cout << "Average Waiting Time (WT): " << total_wt / n << endl;
}

int main() {
    int n = 5;
    vector<pair<int, int>> v;
    v = {{0, 4}, {1, 3}, {2, 1}, {3, 5}, {4, 2}};
    sjf(v, n);
    return 0;
}
