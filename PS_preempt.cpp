#include <bits/stdc++.h>
using namespace std;

void PS(vector<int> &arrival, vector<int> &burst, vector<int> &priority) {
    int n = arrival.size();
    vector<int> remaining = burst, completion(n, 0), turnaround(n, 0), waiting(n, 0);
    int time = 0, completed = 0, min_priority = INT_MAX, index = -1;

    while (completed < n) {
        min_priority = INT_MAX;
        index = -1;

        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time && remaining[i] > 0 && priority[i] < min_priority) {
                min_priority = priority[i];
                index = i;
            }
        }

        if (index != -1) {
            remaining[index]--;
            if (remaining[index] == 0) {
                completed++;
                completion[index] = time + 1;
            }
        }
        time++;
    }

    for (int i = 0; i < n; i++) {
        turnaround[i] = completion[i] - arrival[i];
        waiting[i] = turnaround[i] - burst[i];
    }

    double avgTAT = accumulate(turnaround.begin(), turnaround.end(), 0.0) / n;
    double avgWT = accumulate(waiting.begin(), waiting.end(), 0.0) / n;

    cout << fixed << setprecision(2);
    cout << "Average Turnaround Time: " << avgTAT << endl;
    cout << "Average Waiting Time: " << avgWT << endl;
}

int main() {
    int n;
    cin >> n;

    vector<int> arrival(n), burst(n), priority(n);
    for (int i = 0; i < n; i++) cin >> arrival[i];
    for (int i = 0; i < n; i++) cin >> burst[i];
    for (int i = 0; i < n; i++) cin >> priority[i];

    PS(arrival, burst, priority);

    return 0;
}
