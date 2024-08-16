#include <linux/module.h>

static int __init helloworld_init(void)
{
    printk("Hello world\n");
    return 0;
}

static void __exit helloworld_exit(void)
{
    printk("Exit module\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tudo");
MODULE_DESCRIPTION("first module");
MODULE_INFO(board,"BBB");


