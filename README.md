# icepanic
kernel-rootkit for ANTI-ICE Ops

```
$ sudo lsmod | grep icepanic | wc -l
0
```

## INSTALL
```
make
sudo insmod icepanic.ko
```

## RUN
```
cat /proc/cpuinfo
```
## CLEAN (optional)
```
make clean
```
