#include <stdio.h>

struct Process {
    int pid; // Process ID
    int arrivalTime; // Arrival Time
    int priority; // Priority
    int burstTime; // Burst Time
    int completionTime; // Completion Time
    int waitingTime; // Waiting Time
    int responseTime; // Response Time
    int turnAroundTime; // Turn Around Time
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter arrival time, priority, and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrivalTime, &processes[i].priority, &processes[i].burstTime);
    }

    // Sort the processes by arrival time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].arrivalTime > processes[j + 1].arrivalTime) {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    int currentTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        int highestPriority = -1;
        int selectedProcess = -1;

        for (int j = i; j < n && processes[j].arrivalTime <= currentTime; j++) {
            if (processes[j].priority > highestPriority) {
                highestPriority = processes[j].priority;
                selectedProcess = j;
            }
        }

        if (selectedProcess == -1) {
            continue; // No process available to execute
        }

        struct Process *currentProcess = &processes[selectedProcess];
        currentProcess->completionTime = currentTime + currentProcess->burstTime;
        currentProcess->turnAroundTime = currentProcess->completionTime - currentProcess->arrivalTime;
        currentProcess->waitingTime = currentProcess->turnAroundTime - currentProcess->burstTime;
        currentProcess->responseTime = currentTime - currentProcess->arrivalTime;

        currentTime = currentProcess->completionTime;

        // Mark the process as completed
        swap(&processes[i], &processes[selectedProcess]);
    }

    // Calculate and display the results
    double avgWaitingTime = 0;
    double avgTurnAroundTime = 0;

    printf("\nProcess\tArrival Time\tPriority\tBurst Time\tCompletion Time\tWaiting Time\tResponse Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        struct Process *p = &processes[i];
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p->pid, p->arrivalTime, p->priority, p->burstTime, p->completionTime, p->waitingTime, p->responseTime, p->turnAroundTime);

        avgWaitingTime += p->waitingTime;
        avgTurnAroundTime += p->turnAroundTime;
    }

    avgWaitingTime /= n;
    avgTurnAroundTime /= n;

    printf("\nAverage Waiting Time: %.2lf\n", avgWaitingTime);
    printf("Average Turnaround Time: %.2lf\n", avgTurnAroundTime);

    return 0;
}
