// syscall: capture_memory_snapshot.c
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/mm.h>

SYSCALL_DEFINE0(capture_memory_snapshot) {
    struct sysinfo info;
    si_meminfo(&info);

    printk(KERN_INFO "[capture_memory_snapshot] Total RAM: %lu KB\n", info.totalram << (PAGE_SHIFT - 10));
    printk(KERN_INFO "[capture_memory_snapshot] Free RAM: %lu KB\n", info.freeram << (PAGE_SHIFT - 10));
    printk(KERN_INFO "[capture_memory_snapshot] Active pages: %lu\n", info.active);
    printk(KERN_INFO "[capture_memory_snapshot] Inactive pages: %lu\n", info.inactive);

    return 0;
}
