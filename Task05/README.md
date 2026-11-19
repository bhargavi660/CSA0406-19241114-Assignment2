# Task 05 – Synchronisation: Critical Sections, Semaphores and Monitors

## 1. Introduction

This task explores synchronisation techniques used in operating systems to prevent race conditions when multiple threads access shared resources. A railway ticket booking system is used as an example.

## 2. Critical Section Problem

A critical section is a part of a program where shared data is accessed or modified.

A correct solution must satisfy three requirements:

- **Mutual Exclusion:** Only one process or thread can access the critical section at a time.
- **Progress:** If no process is inside the critical section, selecting the next process should not be delayed unnecessarily.
- **Bounded Waiting:** Every waiting process must get a chance to enter the critical section within a limited number of turns.

## 3. Peterson's Solution

Peterson's solution is a software-based synchronisation method for two processes or threads.

It uses:
- `flag[2]` to indicate whether a thread wants to enter the critical section.
- `turn` to decide which thread gets priority.

The implementation uses C11 atomic variables to coordinate two threads and protect a shared counter.

**Compilation:**
```bash
gcc -std=c11 -Wall -Wextra peterson.c -o peterson -pthread
```

**Output:**
```text
Final counter: 200000
Expected counter: 200000
```

## 4. Semaphores and Bounded Buffer

A semaphore is a synchronisation variable used to control access to shared resources.

The bounded-buffer problem involves producers adding items to a fixed-size buffer and consumers removing them. Synchronisation prevents incorrect access to the shared buffer.

**Compilation:**
```bash
gcc -std=c11 -Wall -Wextra bounded_buffer.c -o bounded_buffer -pthread
```

**Output:**
```text
items consumed: 20, sum = 210 (expected 210)
```

## 5. Locking Strategies and Performance Benchmark

The railway ticket booking benchmark compares three mutex locking strategies:

- **Global Lock:** One mutex protects the entire seat array.
- **Per-Train Lock:** Each train has a separate mutex.
- **Per-Coach Lock:** Each coach has a separate mutex, allowing more independent operations.

The benchmark uses 8 threads, with 100,000 booking attempts per thread.

**Compilation:**
```bash
gcc -std=c11 -Wall -Wextra locking_benchmark.c -o locking_benchmark -pthread
```

**Measured Output:**
```text
Railway Ticket Booking Locking Benchmark
Threads: 8, booking attempts per thread: 100000

Global Lock: 0.0825 seconds, 9697008 booking attempts/second
Per-Train Lock: 0.0748 seconds, 10700448 booking attempts/second
Per-Coach Lock: 0.0608 seconds, 13165627 booking attempts/second
```

The per-coach locking strategy achieved the highest throughput in this particular run because it allows threads working on different coaches to operate with less lock contention.

## 6. Result

Peterson's solution and the bounded-buffer program executed successfully. The locking benchmark demonstrated the performance differences between global, per-train and per-coach locking strategies.

The results show that finer-grained locking can improve concurrency and throughput for this railway booking simulation.

## 7. Conclusion

This task demonstrates critical sections, Peterson's solution, bounded-buffer synchronisation and mutex locking strategies. These techniques help protect shared resources and improve concurrent program execution.
