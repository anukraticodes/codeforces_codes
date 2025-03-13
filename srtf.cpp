#include <bits/stdc++.h>
using namespace std;

void SRTF(vector<int> &arrival, vector<int> &burst) {
    int n = arrival.size();
    vector<int> remaining = burst, completion(n, 0), turnaround(n, 0), waiting(n, 0);
    int completed = 0, time = 0, shortest = -1;
    int minRemaining =INT_MAX;

    vector<bool> isCompleted(n, false);

    while (completed < n) {
        shortest = -1;
        minRemaining =INT_MAX;

        for (int i = 0; i < n; i++) {
            if (arrival[i] <= time && !isCompleted[i] && remaining[i] < minRemaining) {
                minRemaining = remaining[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        remaining[shortest]--;

        if (remaining[shortest] == 0) {
            completion[shortest] = time + 1;
            turnaround[shortest] = completion[shortest] - arrival[shortest];
            waiting[shortest] = turnaround[shortest] - burst[shortest];
            isCompleted[shortest] = true;
            completed++;
        }

        time++;
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
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> arrival(n), burst(n);

    cout << "Enter arrival times: ";
    for (int i = 0; i < n; i++) cin >> arrival[i];

    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++) cin >> burst[i];

    SRTF(arrival, burst);

    return 0;
}
