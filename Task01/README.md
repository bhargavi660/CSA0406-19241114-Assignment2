# Task 01 – Processes and Process States

## 1. Aim

To study process creation, process states, Process Control Blocks (PCB), and process management in an online examination server.

## 2. Process State Diagram

A process moves through five main states:

- New
- Ready
- Running
- Waiting
- Terminated

## 3. Process Control Block (PCB)

A Process Control Block is a data structure maintained by the operating system to store information about a process.

Important PCB fields include:

- Process ID (PID)
- Process State
- Program Counter
- CPU Registers
- CPU Scheduling Information
- Memory Management Information
- I/O Status Information

## 4. Fork System Call

A C program using the `fork()` system call will be implemented to create child processes.

## 5. Process Inspection

The `ps` command and `/proc` filesystem will be used to observe process IDs, parent process IDs and process states.

## 6. Performance Evaluation

The performance of a process-per-student design will be evaluated based on context-switch overhead, memory usage and I/O waiting.

## 7. Design Decision

The following approaches will be compared:

- One process per student
- One thread per student
- Fixed-size worker pool

## 8. Conclusion

The experiment will demonstrate process creation and process inspection in Linux. The results will help identify a suitable process-management design for an online examination server.

# Task 01 – Processes and Process States

## 1. Aim

To understand process creation, process states, Process Control Blocks (PCB), and process management using Linux system calls.

## 2. Process State Diagram

A process moves through five main states during execution.

```text
        +------+
        | NEW  |
        +------+
            |
            v
        +-------+
        | READY |
        +-------+
            |
            v
        +---------+
        | RUNNING |
        +---------+
         /       \
        v         v
   +---------+  +------------+
   | WAITING |  | TERMINATED |
   +---------+  +------------+
        |
        | I/O completed
        v
      READY
```

## 3. Process Control Block (PCB)

A Process Control Block is a data structure maintained by the operating system to store information about a process.

Important PCB fields:

- Process ID (PID)
- Process State
- Program Counter
- CPU Registers
- CPU Scheduling Information
- Memory Management Information
- I/O Status Information

The operating system uses the PCB to manage processes and perform context switching.

## 4. Fork System Call Implementation

The C program `process.c` uses the `fork()` system call to create three child processes.

Each child displays its PID and parent PID, sleeps for 120 seconds, and then terminates.

### Compilation

```bash
gcc process.c -o process
```

### Execution

```bash
./process
```

### Process Inspection Using ps

```bash
ps -o pid,ppid,state,comm -p 721,722,723,724
```

The output showed one parent process and three child processes.

- Parent PID: 721
- Child PIDs: 722, 723, 724
- All children had PPID 721.
- State S indicated sleeping processes.

### Process Inspection Using /proc

```bash
cat /proc/722/status | head -15
```

The output confirmed:

- PID: 722
- PPID: 721
- State: S (sleeping)

The `/proc` filesystem provides information about active processes.

## 5. Evaluation of Process-Based Design

Creating a separate process for every student provides isolation. However, thousands of processes increase memory usage and process-management overhead.

Each process has its own virtual address space and PCB. Process context switching generally involves more overhead than thread context switching within the same process.

### Comparison of Approaches

| Approach | Advantages | Disadvantages |
|---|---|---|
| One process per student | Strong isolation | Higher memory usage and overhead |
| One thread per student | Lower resource overhead | A process-wide failure can affect all sessions |
| Fixed worker pool | Reuses a limited number of workers | Requires task scheduling and coordination |

## 6. Recommended Design

A fixed-size worker pool is suitable for the online examination server.

It handles student requests using a controlled number of worker processes or threads instead of creating a separate process for every student.

This reduces resource overhead and helps manage many simultaneous student sessions.

Critical services can be separated into independent processes when stronger isolation is required.

## 7. Conclusion

The `fork()` demonstration shows how a parent process creates child processes.

The `ps` command and `/proc` filesystem help inspect process IDs, parent IDs, and process states.

A fixed-size worker pool provides a practical balance between resource usage, performance, and reliability.

