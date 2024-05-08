gcc -o fsgi fsgi.c -L/usr/lib/x86_64-linux-gnu/ -I/usr/include/ -I./include -L/opt/OpenBLAS/lib -I/opt/OpenBLAS/include -Wl,-rpath,/opt/OpenBLAS/lib -lopenblas -lfcgi -lpthread
