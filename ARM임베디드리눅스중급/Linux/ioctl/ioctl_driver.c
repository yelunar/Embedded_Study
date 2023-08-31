#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/uaccess.h>
#include <linux/ioctl.h>

#define IOCTL_TYPE 'I'

#define WRITE_ACT _IOW(IOCTL_TYPE, 1, int*)
#define READ_ACT _IOR(IOCTL_TYPE, 2, int*)

int value;

dev_t dev = 0;
static struct class *dev_class;
static struct cdev driver_cdev;

static int driver_open(struct inode *inode, struct file *file)
{
        pr_info("device open\n");
        return 0;
}

static int driver_release(struct inode *inode, struct file *file)
{
        pr_info("device closed\n");
        return 0;
}

static ssize_t driver_read(struct file *filp, char __user *user_buf, size_t len, loff_t *off)
{
	char num[16] = {};
	
	if (*off > 0)
		return 0;

        pr_info("device read: value = %d\n", value);
	sprintf(num, "%d\n", value);

	return simple_read_from_buffer(user_buf, len, off, num, sizeof(num));
}

static ssize_t driver_write(struct file *filp, const char __user *user_buf, size_t len, loff_t *off)
{
	if (kstrtoint_from_user(user_buf, len, 0, &value)) {
		pr_err("write error\n");
		return len;
	}

        pr_info("device write: %d\n", value);
        return len;
}

static long driver_ioctl(struct file *file, unsigned int user_request, unsigned long user_arg)
{	
	switch(user_request) {
	case WRITE_ACT:
		if (copy_from_user(&value ,(int*) user_arg, sizeof(value)))
			pr_err("write error\n");

		pr_info("IOCTL: %d is written \n", value);
		break;
	case READ_ACT:
		if (copy_to_user((int*) user_arg, &value, sizeof(value)))
			pr_err("read error\n");

		pr_info("IOCTL: %d is read \n", value);
		break;
	default:
		pr_info("unknown command\n");
		break;
        }
        return 0;
}

static struct file_operations fops =
{
        .owner          = THIS_MODULE,
        .read           = driver_read,
        .write          = driver_write,
        .open           = driver_open,
        .unlocked_ioctl = driver_ioctl,
        .release        = driver_release,
};

static int __init ioctl_test_driver_init(void)
{
        if((alloc_chrdev_region(&dev, 0, 1, "ioctl_test_driver_dev")) <0){
                pr_err("Error: cannot allocate device number\n");
                return -1;
        }
        pr_info("major = %d minor = %d \n",MAJOR(dev), MINOR(dev));
 
        cdev_init(&driver_cdev,&fops);
 
        if((cdev_add(&driver_cdev,dev,1)) < 0){
		pr_err("Error: cannot add device\n");
		goto err;
        }

	if((dev_class = class_create(THIS_MODULE,"ioctl_test_driver_class")) == NULL){
		pr_err("Error: cannot create the struct class\n");
		goto err;
        }
 
        if((device_create(dev_class,NULL,dev,NULL,"ioctl_test_device")) == NULL){
		pr_err("Error: cannot create device\n");
		goto err_dev;
        }
        pr_info("IOCTL test driver start\n");
        return 0;
 
err_dev:
        class_destroy(dev_class);
err:
        unregister_chrdev_region(dev,1);
        return -1;
}

static void __exit ioctl_test_driver_exit(void)
{
        device_destroy(dev_class,dev);
        class_destroy(dev_class);
        cdev_del(&driver_cdev);
        unregister_chrdev_region(dev, 1);
        pr_info("IOCTL test driver done\n");
}
 
module_init(ioctl_test_driver_init);
module_exit(ioctl_test_driver_exit);
 
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Real Linux <help@reallinux.co.kr>");
MODULE_DESCRIPTION("IOCTL test device driver");
MODULE_VERSION("1.0");

