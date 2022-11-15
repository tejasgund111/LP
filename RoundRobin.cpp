// this is for non pre-emptive
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of processes ";
    cin >> n;

    int at[n], bt[n], ct[n], wt[n], tat[n];

    for (int i = 0; i < n; i++)
    {
        at[i] = bt[i] = ct[i] = wt[i] = tat[i] = 0;
    }
    cout << "Enter the arrival time " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "] = ";
        cin >> at[i];
    }

    cout << "Enter the Burst time " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "] = ";
        cin >> bt[i];
    }

    cout << "Enter Completion Time " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P[" << i + 1 << "] = ";
        cin >> ct[i];
    }

    for (int i = 0; i < 4; i++)
    {
        tat[i] = ct[i] - at[i];
        cout << "Turn Around Time for Process " << (i + 1) << " is : " << tat[i];
    }
    int total_tat = tat[0];
    for (int i = 1; i < n; i++)
    {
        total_tat += tat[i];
    }
    int avg_tat = total_tat / n;
    cout << "Total Turn Around Time is : " << total_tat << endl;
    cout << "Average Turn Around Time is " << avg_tat << endl;

    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i];
        cout << "Waiting Time for Process " << i + 1 << " is " << wt[i] << endl;
    }

    int total_wt = wt[0];
    for (int i = 1; i < n; i++)
    {
        total_wt += wt[i];
    }
    int avg_wt = total_wt / n;
    cout << "Total Waiting Time is : " << total_wt << endl;
    cout << "Average Waiting Time is " << avg_wt << endl;
}