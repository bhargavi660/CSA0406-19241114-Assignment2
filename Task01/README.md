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

