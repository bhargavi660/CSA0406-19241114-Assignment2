# Task 02 – CPU Scheduling

## 1. Aim

To study and compare different CPU scheduling algorithms and understand their effect on waiting time, turnaround time, response time, and CPU utilization.

## 2. Scheduling Algorithms

The following CPU scheduling algorithms are studied:

- First Come First Served (FCFS)
- Shortest Job First (SJF)
- Shortest Remaining Time First (SRTF)
- Priority Scheduling
- Round Robin (RR)

## 3. Round Robin Implementation

A Round Robin scheduling program was implemented using C.

**Process Details:**

| Process | Arrival Time | Burst Time |
|---|---:|---:|
| P1 | 0 | 8 |
| P2 | 1 | 4 |
| P3 | 2 | 9 |
| P4 | 3 | 5 |

The program was compiled and executed using GCC in Ubuntu Linux.

**Compilation Command:**
```bash
gcc round_robin.c -o round_robin
```

**Execution Command:**
```bash
./round_robin
```

## 4. Performance Evaluation

The program was tested with four different time quantum values.

| Time Quantum | Average Turnaround Time | Average Waiting Time |
|---:|---:|---:|
| 1 | 19.00 | 12.50 |
| 3 | 20.00 | 13.50 |
| 5 | 17.50 | 11.00 |
| 20 | 15.25 | 8.75 |

### Observations

- Quantum 1 provides frequent CPU switching between processes.
- Quantum 3 gives balanced execution among processes.
- Quantum 5 provides a lower average waiting time than quantum 1 and 3.
- Quantum 20 behaves similarly to FCFS because the quantum is large enough for each process to finish in one turn.

### Conclusion from Testing

For the given process set, quantum 20 produces the lowest average waiting time of 8.75 and average turnaround time of 15.25. However, a large quantum reduces responsiveness for newly arriving short processes. Therefore, the time quantum should be selected based on the system's response-time requirements.
## 5. FCFS (First Come First Served) Scheduling

FCFS is a non-preemptive CPU scheduling algorithm in which the process that arrives first gets executed first.

### Gantt Chart

```text
0        8       12        21       26
|   P1   |  P2   |   P3    |   P4   |
```

### Calculation Results

| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time | Response Time |
|---|---:|---:|---:|---:|---:|---:|
| P1 | 0 | 8 | 8 | 8 | 0 | 0 |
| P2 | 1 | 4 | 12 | 11 | 7 | 7 |
| P3 | 2 | 9 | 21 | 19 | 10 | 10 |
| P4 | 3 | 5 | 26 | 23 | 18 | 18 |

### Average Times

- Average Turnaround Time = 15.25
- Average Waiting Time = 8.75
- Average Response Time = 8.75

### Observation

FCFS executes processes in arrival order. It is simple to implement, but shorter processes may wait for longer processes to finish. This can increase waiting time for short jobs.


## 6. SJF (Shortest Job First) Scheduling

SJF is a non-preemptive CPU scheduling algorithm. The process with the shortest burst time among the available processes is executed first.

### Gantt Chart

```text
0        8       12      17        26
|   P1   |  P2   |  P4   |    P3    |
```

### Calculation Results

| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time | Response Time |
|---|---:|---:|---:|---:|---:|---:|
| P1 | 0 | 8 | 8 | 8 | 0 | 0 |
| P2 | 1 | 4 | 12 | 11 | 7 | 7 |
| P3 | 2 | 9 | 26 | 24 | 15 | 15 |
| P4 | 3 | 5 | 17 | 14 | 9 | 9 |

### Average Times

- Average Turnaround Time = 14.25
- Average Waiting Time = 7.75
- Average Response Time = 7.75

### Observation

SJF gives preference to shorter processes, reducing the average waiting time compared with FCFS. However, longer processes may wait for

## 7. SRTF (Shortest Remaining Time First) Scheduling

SRTF is a preemptive CPU scheduling algorithm. The process with the shortest remaining burst time gets the CPU. If a new process arrives with a shorter remaining time, the current process is interrupted.

### Gantt Chart

```text
0   1       5       10       17        26
|P1 |  P2   |  P4   |   P1   |    P3    |
```

### Calculation Results

| Process | Arrival Time | Burst Time | Completion Time | Turnaround Time | Waiting Time | Response Time |
|---|---:|---:|---:|---:|---:|---:|
| P1 | 0 | 8 | 17 | 17 | 9 | 0 |
| P2 | 1 | 4 | 5 | 4 | 0 | 0 |
| P3 | 2 | 9 | 26 | 24 | 15 | 15 |
| P4 | 3 | 5 | 10 | 7 | 2 | 2 |

### Average Times

- Average Turnaround Time = 13.00
- Average Waiting Time = 6.50
- Average Response Time = 4.25

### Observation

SRTF can reduce waiting time for short processes by allowing preemption. However, frequent process switching can increase context-switching overhead, and long processes may experience starvation.
## 8. Priority Scheduling

Priority Scheduling is a CPU scheduling algorithm in which the process with the highest priority is executed first. In this example, lower priority numbers indicate higher priority. The priority values are assumed because they are not specified in the assignment.

### Priority Values

| Process | Arrival Time | Burst Time | Priority |
|---|---:|---:|---:|
| P1 | 0 | 8 | 2 |
| P2 | 1 | 4 | 1 |
| P3 | 2 | 9 | 4 |
| P4 | 3 | 5 | 3 |

### Gantt Chart

```text
0        8       12      17        26
|   P1   |  P2   |  P4   |    P3    |
```

### Calculation Results

| Process | Completion Time | Turnaround Time | Waiting Time | Response Time |
|---|---:|---:|---:|---:|
| P1 | 8 | 8 | 0 | 0 |
| P2 | 12 | 11 | 7 | 7 |
| P3 | 26 | 24 | 15 | 15 |
| P4 | 17 | 14 | 9 | 9 |

### Average Times

- Average Turnaround Time = 14.25
- Average Waiting Time = 7.75
- Average Response Time = 7.75

### Observation

Priority Scheduling executes higher-priority processes before lower-priority processes. It is useful when some jobs are more important than others. However, low-priority processes may experience starvation if high-priority jobs keep arriving.

## 9. Starvation, Ageing and MLFQ

### Starvation

Starvation occurs when a process waits for a very long time because other processes keep getting CPU time before it.

- In SJF, long processes may starve when shorter processes continuously arrive.
- In Priority Scheduling, low-priority processes may starve when high-priority processes keep arriving.

### Ageing

Ageing is a technique used to prevent starvation. The priority of a waiting process is gradually increased over time so that it eventually gets CPU time.

### Multilevel Feedback Queue (MLFQ)

MLFQ is a CPU scheduling algorithm that uses multiple queues with different priority levels.

- New processes enter the highest-priority queue.
- Short jobs receive CPU time quickly using a small time quantum.
- Processes that use their full time quantum can move to lower-priority queues.
- Processes waiting too long can be moved to higher-priority queues using priority boosting.

### Advantages of MLFQ

- Provides quick response to short and interactive jobs.
- Allows longer jobs to execute without permanently blocking shorter jobs.
- Adapts to different types of workloads.
- Priority boosting helps reduce starvation.

### Observation

MLFQ is suitable for systems that handle both short and long jobs because it balances responsiveness and CPU utilization. However, choosing the correct queue levels and time quantum requires careful configuration.
## 10. Comparison and Final Recommendation

### Scheduling Algorithm Comparison

| Algorithm | Average Waiting Time | Average Turnaround Time | Main Advantage | Limitation |
|---|---:|---:|---|---|
| FCFS | 8.75 | 15.25 | Simple and easy to implement | Short jobs may wait behind long jobs |
| SJF | 7.75 | 14.25 | Reduces average waiting time | Long jobs may starve |
| SRTF | 6.50 | 13.00 | Gives preference to processes with shorter remaining time | More context switching |
| Priority | 7.75 | 14.25 | Important jobs execute first | Low-priority jobs may starve |
| Round Robin (q=3) | 13.50 | 20.00 | Fair CPU time sharing | More switching with small quantum |

### Effect of Round Robin Time Quantum

The following results were obtained by testing different

## 10. Conclusion

The Round Robin scheduling algorithm was successfully implemented and tested with different time quantum values. The experiment demonstrates how the time quantum affects waiting time, turnaround time, and process switching.

Further analysis of FCFS, SJF, SRTF, Priority Scheduling, starvation, ageing, and Multilevel Feedback Queue (MLFQ) is included in this task.
