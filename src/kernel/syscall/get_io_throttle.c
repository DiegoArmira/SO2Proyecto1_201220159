// syscall: get_io_throttle.c
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/fs.h>

SYSCALL_DEFINE1(get_io_throttle, pid_t, pid) {
    struct task_struct *task;
    struct io_accounting io_stats;

    rcu_read_lock();
    task = find_task_by_vpid(pid);
    if (!task) {
        rcu_read_unlock();
        return -ESRCH; // Process not found
    }

    io_stats = task->ioac;
    rcu_read_unlock();

    printk(KERN_INFO "[get_io_throttle] PID: %d\n", pid);
    printk(KERN_INFO "[get_io_throttle] Bytes read: %llu\n", io_stats.read_bytes);
    printk(KERN_INFO "[get_io_throttle] Bytes written: %llu\n", io_stats.write_bytes);
    printk(KERN_INFO "[get_io_throttle] Swap in: %llu\n", io_stats.swapin_count);
    printk(KERN_INFO "[get_io_throttle] Block I/O delays: %llu ns\n", io_stats.blkio_delay_total);

    return 0;
}
