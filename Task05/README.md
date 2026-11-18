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
