// boot/init.c
#include <linux/init.h>
#include <linux/kernel.h>

static int __init custom_kernel_init(void) {
    printk(KERN_INFO "[Custom Kernel] Bienvenido al kernel modificado por Diego Ahtohil Noj Armira\n");
    return 0;
}

static void __exit custom_kernel_exit(void) {
    printk(KERN_INFO "[Custom Kernel] Salida del kernel modificado. Adiós!\n");
}

module_init(custom_kernel_init);
module_exit(custom_kernel_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Diego Ahtohil Noj Armira");
MODULE_DESCRIPTION("Módulo de inicio personalizado del kernel");