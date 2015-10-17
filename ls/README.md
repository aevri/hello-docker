Docker 'ls'
===========

'ls' in an 'empty' container.

This makes a simple 'ls'-like program which will recursively list all files in
an 'empty' container.

This illustrates that even when you start from scratch, there are some things
that the kernel and Docker will already have provided in order for the
container to work.

Run `build_and_run.sh` to build the `ls` docker image and run it.
