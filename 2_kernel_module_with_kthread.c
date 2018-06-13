#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <stddef.h>
#include <linux/kthread.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("LWQ");
MODULE_DESCRIPTION("");

static struct task_struct *tsk;

static int thread_function(void *data)
{
	while(!kthread_should_stop())
	{
		printk(KERN_INFO "Loop\n");
	}
	return 0;
}

static int __init func_init(void)
{
	printk(KERN_INFO "Start\n");
	tsk = kthread_run(thread_function,NULL,"mythread");
	if(IS_ERR(tsk)){
		printk(KERN_INFO "create kthread failed\n");
	}
	else
	{
		printk(KERN_INFO "create kthread OK\n");
	}
	return 0;
}
static void __exit func_end(void)
{
	printk(KERN_INFO "Exit\n");
	if(!IS_ERR(tsk)){
		int ret = kthread_stop(tsk);
	}
}

module_init(func_init);
module_exit(func_end);

