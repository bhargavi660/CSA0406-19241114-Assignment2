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
| 1 MB | 0.003856 | 0.001357 |
| 10 MB | 0.082827 | 0.008844 |
| 100 MB | 0.190944 | 0.102151 |

## 6. Result

Pipe and shared memory communication were successfully implemented and tested. The benchmark showed that shared memory took less time than the pipe implementation for all three tested transfer sizes in this run.
