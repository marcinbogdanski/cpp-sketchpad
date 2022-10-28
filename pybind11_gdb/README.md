Note:
* install `gdb` and `python3-gdb`
* `-g` flag when compiling the code

# Resource 1
* https://stackoverflow.com/questions/20179153/gdb-backtrace-with-no-user-input

Thanks to Aditya Kumar; acceptable solution:

gdb -batch -ex "run" -ex "bt" ${my_program} 2>&1 | grep -v ^"No stack."$

If the program needs arguments:

gdb -batch -ex "run" -ex "bt" --args ${my_program} param1 param2 \
                              param3 ... 2>&1 | grep -v ^"No stack."$

# Resource 2
* https://www.commandlinefu.com/commands/view/4039/print-stack-trace-of-a-core-file-without-needing-to-enter-gdb-interactively

## Run a program transparently, but print a stack trace if it fails

For automated unit tests I wanted my program to run normally, but if it crashed, to add a stack trace to the output log. I came up with this command so I wouldn't have to mess around with core files. The one downside is that it does smoosh your program's stderr and stdout together. Show Sample Output

gdb -batch -ex "run" -ex "bt" ${my_program} 2>&1 | grep -v ^"No stack."$

## Print stack trace of a core file without needing to enter gdb interactively

This does almost the same thing as the original, but it runs the full backtrace for _all_ the threads, which is pretty important when reporting a crash for a multithreaded software, since more often than not, the signal handler is executed in a different thread than the crash happened.

gdb --batch --quiet -ex "thread apply all bt full" -ex "quit" ${exe} ${corefile}
