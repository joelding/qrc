/* skeleton.c: a skeleton for character drivers
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

static int major = 230;
#define DEVNAME "skeleton"

int skeleton_open(struct inode *inode, struct file *fs)
{
	printk("%s\n", __func__);
	return 0;
}

long skeleton_ioctl(struct file *fs, unsigned int cmd, unsigned long args)
{
	printk("%s\n", __func__);
	return 0;
}

ssize_t skeleton_read(struct file *fs, char __user *buffer, size_t size, loff_t *offset)
{
	printk("%s\n", __func__);
	return 0;
}

ssize_t skeleton_write(struct file *fs, const char __user *buffer, size_t size, loff_t *offset)
{
	printk("%s\n", __func__);
	return -EPERM;
}

int skeleton_release(struct inode *inode, struct file *fs)
{
	printk("%s\n", __func__);
	return 0;
}

struct file_operations fops = {
	.open	= skeleton_open,
	.read	= skeleton_read,
	.write	= skeleton_write,
	.unlocked_ioctl	= skeleton_ioctl,
	.release = skeleton_release,
};

static int __init skeleton_init(void)
{
	int retval;

	retval = register_chrdev(major, DEVNAME, &fops);
	if (retval < 0) {
		printk("Fail to register %d\n", retval);
		return retval; 
	}

	if (0 == major) {
		major = retval;
	}

	printk("%s %d\n", __func__, major);

	return 0;
}

module_init(skeleton_init);

static void __exit skeleton_exit(void)
{
	unregister_chrdev(major, DEVNAME);
	printk("%s\n", __func__);
}

module_exit(skeleton_exit);

MODULE_LICENSE("Dual BSD/GPL");

