// boot/other_changes.c
#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(custom_system_name) {
    printk(KERN_INFO "[Custom Kernel] El nombre del sistema ha sido modificado a: 'KernelUSAC-6.8'\n");
    return 0;
}
