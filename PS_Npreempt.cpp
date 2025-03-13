#include <bits/stdc++.h>
using namespace std;

void PS(vector<int> &arrival, vector<int> &burst, vector<int> &priority) {
    int n = arrival.size();
    vector<int> completion(n, 0), turnaround(n, 0), waiting(n, 0);

    vector<int> indices(n);
    for (int i = 0; i < n; i++) indices[i] = i;

    sort(indices.begin(), indices.end(), [&](int a, int b) {
        if (priority[a] == priority[b]) return arrival[a] < arrival[b];
        return priority[a] < priority[b];
    });

    int time = 0;
    for (int i = 0; i < n; i++) {
        int index = indices[i];
        if (time < arrival[index]) time = arrival[index];

        completion[index] = time + burst[index];
        turnaround[index] = completion[index] - arrival[index];
        waiting[index] = turnaround[index] - burst[index];

        time = completion[index];
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

    vector<int> arrival(n), burst(n), priority(n);

    cout << "Enter arrival times: ";
    for (int i = 0; i < n; i++) cin >> arrival[i];

    cout << "Enter burst times: ";
    for (int i = 0; i < n; i++) cin >> burst[i];

    cout << "Enter priority values (lower value = higher priority): ";
    for (int i = 0; i < n; i++) cin >> priority[i];

    PS(arrival, burst, priority);

    return 0;
}
