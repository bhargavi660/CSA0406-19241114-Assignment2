# Task 06 – Deadlock Handling and Banker's Algorithm

## 1. Introduction
A deadlock occurs when two or more processes wait indefinitely for resources held by one another. Deadlock handling is an important responsibility of an operating system.

## 2. Necessary Conditions for Deadlock

Four conditions must hold simultaneously for a deadlock to occur:

1. **Mutual Exclusion:** A resource can be used by only one process at a time.
2. **Hold and Wait:** A process holds one resource while waiting for another.
3. **No Preemption:** Resources cannot be forcibly taken away from a process.
4. **Circular Wait:** A circular chain exists in which each process waits for a resource held by the next process.

## 3. Resource Allocation Graph
A Resource Allocation Graph represents processes and resources.

- Circles represent processes.
- Squares represent resources.
- A request
