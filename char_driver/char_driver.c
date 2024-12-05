#include <linux/init.h>
#include<linux/kernel.h>
#include <linux/module.h>
// module intialization function
static int hello_init(void)
{
	printk(KERN_INFO "Hello, world\n");
	return 0;// RETURN 0 INDICATES sucessful loading
}
// module cleanup function
static void hello_exit(void)
{
	printk(KERN_INFO "Goodbye, cruel world\n");
}
// register module intialization and cleanup function
module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("TECHDHABA");
MODULE_DESCRIPTION("A BASIC LINUX DEVICE DRIVER");

