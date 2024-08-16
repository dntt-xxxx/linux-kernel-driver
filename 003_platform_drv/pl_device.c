#include<linux/module.h>
#include<linux/platform_device.h>

void pcdev_release(struct device *dev)
{
    printk("Device released \n");
}

struct platform_device pl_device ={
    .name = "pl-drv-cpa",
    .id = 1,
    .dev = {
        .platform_data="This is a platform device for testing only",
        .release = pcdev_release
    }
};


static int  __init  pl_device_init(void)
{
    /**
     * platform_device_register - add a platform-level device
     * @pdev: platform device we're adding
     *
     * NOTE: _Never_ directly free @pdev after calling this function, even if it
     * returned an error! Always use platform_device_put() to give up the
     * reference initialised in this function instead.
     */
    platform_device_register(&pl_device);
    printk("platform device init successfully\n");

    return 0;

}


static void __exit pl_device_exit(void)
{

    platform_device_unregister(&pl_device);
    printk("platform device exit successfully\n");

}

module_init(pl_device_init);
module_exit(pl_device_exit);


MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module which registers n platform devices ");
MODULE_AUTHOR("Tu Do");
