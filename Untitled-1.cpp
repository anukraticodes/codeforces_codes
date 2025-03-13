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


