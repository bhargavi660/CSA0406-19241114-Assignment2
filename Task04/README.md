# Task 04 – Inter-Process Communication (IPC)

## 1. Pipe Communication

Implemented inter-process communication using an unnamed pipe. The parent process sends six temperature readings to the child process. The child reads the values and calculates the average and maximum.

**Output:**
```text
analyser: 6 readings, average 35.5, max 41
reader: done
```

## 2. Shared Memory Communication

Implemented shared memory using `shm_open()` and `mmap()`. The parent writes six readings into shared memory, and the child accesses the same memory to calculate the average and maximum.

**Output:**
```text
reader: shared memory updated
analyser: 6 readings, average 35.5, max 41
```

## 3. Pipe EOF Explanation

The parent must close the write end of the pipe using `close(fd[1])` after sending all data. This signals EOF to the child process. The child's `read()` returns 0, indicating that no more data is available.

If the parent does not close the write end, the child continues waiting because the pipe still has an open writer.

## 4. Pipe vs Shared Memory

- **Pipe:** Data passes through the kernel using read and write operations. Data is copied between the processes and the kernel.
- **Shared Memory:** Both processes access the same memory region. It avoids repeated message copying between processes.
- **Synchronization:** Shared memory requires synchronization to prevent one process from reading data before the other has finished writing. Pipes provide synchronization through their read/write behaviour and EOF.

## 5. Performance Measurements

The following measurements were obtained by running the benchmark program.

| Transfer Size | Pipe Time (seconds) | Shared Memory Time (seconds) |
|---|---:|---:|
| 1 MB | 0.001720 | 0.000924 |
| 10 MB | 0.018211 | 0.009122 |
| 100 MB | 0.079112 | 0.075020 |

## 
