Docker 'ls'
===========

'ls' in an 'empty' container.

This makes a simple 'ls'-like program which will recursively list all files in
an 'empty' container.

This illustrates that even when you start from scratch, there are some things
that the kernel and Docker will already have provided in order for the
container to work.

Run `build_and_run.sh` to build the `ls` docker image and run it.

File system entries and what they're for
----------------------------------------

- `/.dockerinit` - this seems to be the real entrypoint for the container. Source code appears to be [here](https://github.com/docker/docker/blob/729c9a97822ebee2c978a322d37060454af6bc66/daemon/execdriver/lxc/init.go).
- `/sys` - this appears to be linked to `/proc/sys`.
- `/dev` - virtual file system of devices, see [wikipedia](https://en.wikipedia.org/wiki/Device_file).
- `/etc` - configuration files for the system.
- `/etc/hosts`, `/etc/hostname`, `/etc/resolv.conf` - overlaid network config files, supplied and updated by docker, see the [docker documentation](https://docs.docker.com/articles/networking/).
- `/proc` - virtual file system of processes and other system information provided by the kernel, see [wikipedia](https://en.wikipedia.org/wiki/Procfs).
- `/ls` - our ls binary!
