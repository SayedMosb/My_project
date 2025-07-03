#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cout << "enter the number of processes: ";
    cin >> n;
    int process_id[n], burst_time[n], waiting_time[n];
    for (int i = 0; i < n; i++) {
        process_id[i] = i + 1; 
        cout << "enter burst time for process " << i + 1 << ": ";
        cin >> burst_time[i];
    }



    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (burst_time[j] > burst_time[j + 1]) {
                swap(burst_time[j], burst_time[j + 1]);
                swap(process_id[j], process_id[j + 1]);
            }
        }
    }


    waiting_time[0] = 0; 
    int total_waiting_time = 0;

    for (int i = 1; i < n; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
        total_waiting_time += waiting_time[i];
    }
    cout << "\nprocess\tBurst Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << process_id[i] << "\t\t" << burst_time[i] << "\t\t" << waiting_time[i] << endl;
    }
    float avg_waiting_time = (float)total_waiting_time / n;
    cout << "\nAverage Waiting Time: " << avg_waiting_time << endl;

    return 0;
}
