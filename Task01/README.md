# Task 01 – Processes and Process States

## 1. Introduction
This task demonstrates process creation and process management in Linux using C. It explores how processes are created, executed, monitored, and terminated.

## 2. Process Creation
A process is a program currently being executed. In Linux, the `fork()` system call creates a new child process from a parent process.

The parent and child processes execute independently.

## 3. Process Control Block (PCB)
A Process Control Block (PCB) is a data structure maintained by the operating system to store information about a process.

It contains:
- Process ID (PID)
- Process state
- Program counter
- CPU registers
- Scheduling information
- Memory management information

## 4. Process States
A process generally moves through the following states:

- **New:** Process is being created.
- **Ready:** Process is waiting for CPU allocation.
- **Running:** Process is currently executing.
- **Waiting:** Process is waiting for an event or resource.
- **Terminated:** Process has completed execution.

## 5. Program Description
The `process.c` program demonstrates process creation using `fork()`. It creates child processes and uses `wait()` to allow the parent process to wait for their completion.

## 6. Compilation and Execution

Compile the program:

```bash
gcc -Wall -Wextra process.c -o process
```

Run the program:

```bash
./process
```

## 7. Output Screenshots
The screenshots in this folder show the program execution and process information obtained during testing.

## 8. Result
The program was successfully compiled and executed in Linux. Process creation and parent-child process management were demonstrated using system calls.

## 9. Conclusion
This task helped demonstrate how Linux creates and manages processes, how parent and child processes interact, and how process execution can be controlled using system calls such as `fork()` and `wait()`.
