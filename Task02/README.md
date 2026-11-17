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



## 6. Conclusion

The Round Robin scheduling algorithm was successfully implemented and tested with different time quantum values. The experiment demonstrates how the time quantum affects waiting time, turnaround time, and process switching.

Further analysis of FCFS, SJF, SRTF, Priority Scheduling, starvation, ageing, and Multilevel Feedback Queue (MLFQ) is included in this task.
