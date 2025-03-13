#include <bits/stdc++.h>
using namespace std;

void RR(vector<int> &arrival, vector<int> &burst, int quantum) {
    int n = arrival.size();
    vector<int> remaining = burst, completion(n, 0), turnaround(n, 0), waiting(n, 0);

    queue<int> q;
    int time = 0, completed = 0;
    vector<bool> inQueue(n, false);

    for (int i = 0; i < n; i++) {
        if (arrival[i] == 0) {
            q.push(i);
            inQueue[i] = true;
        }
    }

    while (completed < n) {
        if (q.empty()) {
            time++;
            for (int i = 0; i < n; i++) {
                if (!inQueue[i] && arrival[i] <= time) {
                    q.push(i);
                    inQueue[i] = true;
                }
            }
            continue;
        }

        int index = q.front();
        q.pop();

        int execTime = min(quantum, remaining[index]);
        time += execTime;
        remaining[index] -= execTime;

        for (int i = 0; i < n; i++) {
            if (!inQueue[i] && arrival[i] <= time) {
                q.push(i);
                inQueue[i] = true;
            }
        }

        if (remaining[index] > 0) {
            q.push(index);
        } else {
            completion[index] = time;
            turnaround[index] = completion[index] - arrival[index];
            waiting[index] = turnaround[index] - burst[index];
            completed++;
        }
    }

    double avgTAT = 0, avgWT = 0;
    for (int i = 0; i < n; i++) {
        avgTAT += turnaround[i];
        avgWT += waiting[i];
    }
    avgTAT /= n;
    avgWT /= n;

    cout << fixed << setprecision(2);
    cout << "Average Turnaround Time: " << avgTAT << endl;
    cout << "Average Waiting Time: " << avgWT << endl;
}

int main() {
    int n, quantum;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> arrival(n), burst(n);

    cout << "Enter arrival times: ";
    for (int i = 0; i < n; i++) cin >> arrival[i];

    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++) cin >> burst[i];

    cout << "Enter time quantum: ";
    cin >> quantum;

    RR(arrival, burst, quantum);

    return 0;
}
