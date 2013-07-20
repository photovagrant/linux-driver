#include <linux/module.h>
#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/delay.h>
#include <linux/vmalloc.h>
#include <linux/sched.h>
#include <linux/timer.h>
#include <linux/mm.h>
#include <linux/interrupt.h>
#include <linux/irq.h>
#include <linux/miscdevice.h>
#include <linux/input.h>
#include <linux/mutex.h>
#include <linux/spinlock.h>
#include <asm/io.h>
#include <asm/uaccess.h>
#include "cdata_ioctl.h"

static int cdata_open(struct inode *inode, struct file *filp)
{
//	while(1)
//	    schedule();
	//need call schedule meachine to prevent this problem.
	printk(KERN_INFO "cdata_open filp_addr= %08x\n", filp);
	return 0;
}

static size_t cdata_read(struct file *filp, char __user *buf,size_t size,loff_t *off)
{
	return 0;	
}

static ssize_t cdata_write(struct file *filp,const char __user *buf,size_t size,loff_t *off)
{
	return 0;
}

static int cdata_close(struct inode *inode,struct file *filp)
{
	printk(KERN_INFO "cdata_close");
	return 0;
}
//long (*unlocked_ioctl) (struct file *, unsigned int, unsigned long);
static long cdata_ioctl(struct file *filp,
                unsigned int cmd, unsigned long arg)
{
	switch (cmd) {
		case IOCTL_EMPTY:
			printk(KERN_INFO "in ioctl: IOCTL_EMPTY\n");
			break;
		case IOCTL_SYNC:
			printk(KERN_INFO "in ioctl: IOCTL_SYNC\n");
			break;
		default:
			return -1;
	}
	return 0;
}


static struct file_operations cdata_fops = {
	owner:		THIS_MODULE,
	open:		cdata_open,
	read:		cdata_read,
	write:		cdata_write,
	compat_ioctl:          cdata_ioctl,
	//unlocked_ioctl:          cdata_ioctl,
	release:	cdata_close,
};

static int cdata_init_module(void)
{
	register_chrdev(121,"cdata",&cdata_fops); //register device API , it will register to /dev/ major numer  (120 ~ 127 is reserved for development)
	return 0;
}

static void cdata_cleanup_module(void)
{
	unregister_chrdev(121,"cdata");

}

module_init(cdata_init_module);
module_exit(cdata_cleanup_module);

MODULE_LICENSE("GPL");
