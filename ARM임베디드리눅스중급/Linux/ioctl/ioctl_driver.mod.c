#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0xe19e516b, "module_layout" },
	{ 0xeb2318a4, "cdev_del" },
	{ 0x28139d22, "device_destroy" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xeb9bdc29, "class_destroy" },
	{ 0x2d741a25, "device_create" },
	{ 0xa273a1ca, "__class_create" },
	{ 0xbaece5a3, "cdev_add" },
	{ 0x4eac5b48, "cdev_init" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0xd697e69a, "trace_hardirqs_on" },
	{ 0xdcb764ad, "memset" },
	{ 0x12a4e128, "__arch_copy_from_user" },
	{ 0x6cbbfc54, "__arch_copy_to_user" },
	{ 0x9660b4a5, "cpu_hwcaps" },
	{ 0xec3d2e1b, "trace_hardirqs_off" },
	{ 0xb384ca2e, "cpu_hwcap_keys" },
	{ 0x14b89635, "arm64_const_caps_ready" },
	{ 0xf9ca2eb4, "kstrtoint_from_user" },
	{ 0x619cb7dd, "simple_read_from_buffer" },
	{ 0x3c3ff9fd, "sprintf" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0xc5850110, "printk" },
	{ 0x1fdc7df2, "_mcount" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "1104EE2104699B0D53CDE6C");
