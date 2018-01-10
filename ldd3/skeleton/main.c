/* skeleton.c: a skeleton for character drivers
 */
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <asm/uaccess.h>

#define DEVNAME "skeleton"
#define BUFSIZE 80
static char mem[BUFSIZE];
static unsigned len;
static int major = 0, minor = 0;
static struct cdev cdev;

int skeleton_open(struct inode *inode, struct file *fs)
{
	printk("%s\n", __func__);

#if 0
	static int cnt = 0;

	sprintf(mem, "skeleton %d\n", cnt++);
	len = strlen(mem);
//	len = 0;
#endif
	try_module_get(THIS_MODULE);
	return 0;
}

long skeleton_ioctl(struct file *fs, unsigned int cmd, unsigned long args)
{
	printk("%s\n", __func__);
	return 0;
}

ssize_t skeleton_read(struct file *fs, char __user *buffer, size_t size, loff_t *offset)
{
	ssize_t retval = 0;
	unsigned int idx = 0;

	printk("%s\n", __func__);

#if 0	
	if (!access_ok(VERIFY_WRITE, buffer, size))
		return -EFAULT;
#endif

	while (len) {
		put_user(mem[idx++], buffer++);
		++retval;
		--len;
	}

	return retval;
}

ssize_t skeleton_write(struct file *fs, const char __user *buffer, size_t size, loff_t *offset)
{
	unsigned int idx = 0;

	printk("%s\n", __func__);

#if 0
	if (!access_ok(VERIFY_READ, buffer, size))
		return -EFAULT;
#endif

	if (size > BUFSIZE) {
		return -EFAULT;
	}

	while (idx < size) {
		get_user(mem[idx++], buffer++);
	}

	len = idx;

	return ((ssize_t) len);
}

int skeleton_release(struct inode *inode, struct file *fs)
{
	printk("%s\n", __func__);
	module_put(THIS_MODULE);
	return 0;
}

struct file_operations fops = {
	.open	= skeleton_open,
	.release = skeleton_release,
	.read	= skeleton_read,
	.write	= skeleton_write,
	.unlocked_ioctl	= skeleton_ioctl,
};

static int __init skeleton_init(void)
{
	int retval = 0;

#if 0
	retval = register_chrdev(major, DEVNAME, &fops);
	if (retval < 0) {
		printk("Fail to register %d\n", retval);
		return retval; 
	}

	if (0 == major) {
		major = retval;
	}
	
	return 0;
#endif

	dev_t devno;

	if (major) {
		devno = MKDEV(major, minor);
		retval = register_chrdev_region(devno, 1, DEVNAME);
		if (retval < 0) {
			printk("Fail register_chrdev_region() errcode=%d\n", retval);
			return retval;
		}
	} else {
		retval = alloc_chrdev_region(&devno, 0, 1, DEVNAME);
		if (retval < 0) {
			printk("Fail alloc_chrdev_region() errcode=%d\n", retval);
			return retval;
		}

		major = MAJOR(devno);
		minor = MINOR(devno);
	}

	cdev_init(&cdev, &fops);
	cdev.owner = THIS_MODULE;
	retval = cdev_add(&cdev, devno, 1);
	if (retval < 0) {
		printk("Fail cdev_add() error code=%d\n", retval);
		goto fail_cdev_add;
	}

	printk("%s major=%d\n", __func__, major);

	return 0;

fail_cdev_add:
	unregister_chrdev_region(devno, 1);

	return retval;
}

module_init(skeleton_init);

static void __exit skeleton_exit(void)
{
#if 0
	unregister_chrdev(major, DEVNAME);
#endif

	cdev_del(&cdev);
	unregister_chrdev_region(MKDEV(major, minor), 1);

	printk("%s\n", __func__);
}

module_exit(skeleton_exit);

MODULE_LICENSE("Dual BSD/GPL");

