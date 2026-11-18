# Task 05 – Synchronisation: Critical Sections, Semaphores and Monitors

## 1. Introduction
This task explores synchronisation techniques used in operating systems to prevent race conditions when multiple threads access shared resources. The example is a railway ticket booking system where multiple agents book seats simultaneously.

## 2. Critical Section Problem
A critical section is a part of a program where shared data is accessed or modified.

A correct solution must satisfy three requirements:

- **Mutual Exclusion:** Only one process or thread can access the critical section at a time.
- **Progress:** If no process is inside the critical section, the selection of the next process should not be delayed unnecessarily.
- **Bounded Waiting:** Every waiting process must get a chance to enter the critical section within a limited number of turns.

## 3. Peterson's Solution
Peterson's solution is a software-based synchronisation method for two processes.

It uses:
- `flag[2]` to indicate whether a process wants to enter the critical section.
- `turn` to decide which process gets priority.

It satisfies mutual exclusion, progress and bounded waiting under its assumptions. However, modern processors and compilers may reorder memory operations, so the original implementation is not reliably safe without suitable memory-ordering guarantees.

## 4. Semaphores
A semaphore is a synchronisation variable used to control access
 shared resources.

- **Binary Semaphore:** Has values 0 and 1. It can be used to protect a critical section.
- **Counting Semaphore:** Maintains a count of available instances of a resource.

Main operations:
- `wait()` decreases the semaphore value or blocks the thread if the resource is unavailable.
- `signal()` increases the semaphore value and may wake a waiting thread.

## 5. Classical Synchronisation Problems

### Producer–Consumer
The producer adds items to a shared buffer, and the consumer removes them. Semaphores named `empty` and `full` track available and occupied slots. A mutex protects the buffer.

### Readers–Writers
Multiple readers can access shared data simultaneously, but a writer requires exclusive access. Locks and semaphores coordinate access.

### Dining Philosophers
Each philosopher needs two shared forks to eat. Semaphore-based solutions must prevent deadlock and starvation.

## 6. Monitors
A monitor is a high-level synchronisation construct that combines shared data and operations in one protected unit.

Condition variables allow threads to wait until a required condition becomes true and signal other waiting threads. Monitors make synchronisation easier to organise and maintain.

## 7. Bounded-Buffer Implementation
The C program uses:
- A buffer of size 5.
- A producer and a consumer thread.
- An `empty` semaphore to track free slots.
- A `full` semaphore to track available items.
- A mutex to protect shared buffer access.

**Output:**
```text
items consumed: 20, sum = 210 (expected 210)
```

## 8. Testing and Performance Evaluation

### Peterson's Solution Test

```text
Final counter: 200000
Expected counter: 200000
```

### Locking Performance Benchmark

The benchmark was executed using 8 threads, with 100,000 booking attempts per thread.

| Locking Strategy | Execution Time (seconds) | Attempts/second |
|---|---:|---:|
| Global Lock | 0.0974 | 8,214,002 |
| Per-Train Lock | 0.0518 | 15,429,494 |
| Per-Coach Lock | 0.0321 | 24,886,516 |

### Performance Analysis
- Global locking had the longest execution time because all threads shared one lock.
- Per-train locking improved performance by allowing operations on different trains to proceed independently.
- Per-coach locking achieved the shortest execution time and highest throughput in this test.

**Result:** Per-coach locking performed best in this benchmark.

## 9. Conclusion
The bounded-buffer program and Peterson's solution compiled and executed successfully. The benchmark demonstrated that finer-grained locking can improve concurrency and performance. Synchronisation techniques help prevent race conditions and protect shared resources.
## 10. Program Testing Results

### Bounded-Buffer Test

Compiled and executed `bounded_buffer.c` using GCC and pthreads.

**Output:**
```text
items consumed: 20, sum = 210 (expected 210)
```

The consumer successfully consumed all 20 items, and the calculated sum matched the expected value.

### Peterson's Solution Test

Compiled and executed `peterson.c` using two threads.

**Output:**
```text
Final counter: 200000
Expected counter: 200000
```

The final counter matched the expected value.

### Locking Performance Benchmark

The benchmark was executed using 8 threads, with 100,000 booking attempts per thread.

| Locking Strategy | Execution Time (seconds) | Attempts/second |
|---|---:|---:|
| Global Lock | 0.0974 | 8,214,002 |
| Per-Train Lock | 0.0518 | 15,429,494 |
| Per-Coach Lock | 0.0321 | 24,886,516 |

### Performance Analysis

- Global locking had the longest execution time because all threads shared one lock.
- Per-train locking improved performance by allowing operations on different trains to proceed independently.
- Per-coach locking achieved the shortest execution time and highest throughput in this test.

**Conclusion:** Per-coach locking performed best in this benchmark because it allowed greater concurrency while protecting individual coaches.

## 11. Overall Conclusion

The bounded-buffer program, Peterson's solution and railway locking benchmark compiled and executed successfully. The results demonstrate the importance of synchronisation for protecting shared resources and improving concurrent program performance.
