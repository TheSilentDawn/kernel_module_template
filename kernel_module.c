#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("");
MODULE_DESCRIPTION("");

static int __init start(void)
{
	printk(KERN_INFO "\n");
	
	return 0;
}
static void __exit end(void)
{
	printk(KERN_INFO "\n");
}

module_init(start);
module_exit(end);