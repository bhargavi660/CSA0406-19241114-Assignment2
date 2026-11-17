# Task 01 – Processes and Process States

## 1. Aim

To study process creation, process states, Process Control Blocks (PCB), and process management in an online examination server using Linux system calls and commands.

## 2. Process State Diagram

A process moves through five main states during its execution:

- **New:** The process is being created.
- **Ready:** The process is waiting for CPU allocation.
- **Running:** The process is currently executing.
- **Waiting:** The process is waiting for an event or I/O operation.
- **Terminated:** The process has completed execution.

### Process State Transitions

- New → Ready: Process is admitted by the operating system.
- Ready → Running: CPU is allocated to the process.
- Running → Ready: Process is interrupted or its time slice expires.
- Running → Waiting: Process waits for I/O or another event.
- Waiting → Ready: The required event or I/O operation completes.
- Running → Terminated: Process finishes execution.

## 3. Process Control Block (PCB)

