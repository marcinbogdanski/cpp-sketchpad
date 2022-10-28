FROM python:3.9.7-slim

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential \
    python3-dbg \
    gdb

RUN pip install pybind11

RUN useradd -ms /bin/bash appuser
USER appuser

COPY --chown=appuser:appuser . /home/appuser/app
WORKDIR /home/appuser/app

RUN c++ -g -Wall -shared -std=c++20 -fPIC `python3 -m pybind11 --includes` example.cpp -o example`python3-config --extension-suffix`

# In case of c++ crash we want to print backtrace, here is breakdown:
#   "gdb", "-batch",                  <- run gdb debugger in non-interactive mode [1,2]
#   "-ex", "run",                     <- inside gdb run command specified with final arguments: "--args" "python" "main.py" [1,2]
#   "-ex", "set $i = $_exitcode",     <- inside gdb capture exit code of program we just executed ("void" if crashed in c++) [4]
#   "-ex", "bt",                      <- inside gdb show backtrace, on clean exit this will print "No stack.", otherwise backtrace of thread that crashed [1,2],
#                                        without following "quit $i" gdb would return "bt" exit code which is always 1
#   "-ex", "print $i",                <- inside gdb print exit code we captured earlier, this will print "$1 = 123" where 123 if exit code
#   "-ex", "quit $i",                 <- quit gdb and return exit code, on clean exit this will return capture code,
#                                        on c++ crash this will print "Value can't be converted to integer." [3]
# Few experiments show following results:
#   * clean exit causes gdb to print "$1 = 0" and exit with code 0
#   * 'sys.exit(13)' in Python causes gdb to print "$1 = 13" and exit with code 13
#   * 'raise ValueError()' in Python causes gdb to print "$1 = 1" and exit with code 1
#   * c++ crash in PyBind11 causes gdb to print "Value can't be converted to integer." and exit with code 1
# All in all this will preserve exit code in all cases, apart from c++ crash,
# in which case exit code is 1 because "void" exit code from failed execution "can't be converted to integer."
# References:
# * [1] https://stackoverflow.com/questions/20179153/gdb-backtrace-with-no-user-input
# * [2] https://www.commandlinefu.com/commands/view/4039/print-stack-trace-of-a-core-file-without-needing-to-enter-gdb-interactively
# * [3] https://stackoverflow.com/questions/52191529/using-the-return-command-in-a-gdb-script
# * [4] https://stackoverflow.com/questions/39657418/how-does-gdb-retrieve-the-exit-code-of-target-program
ENTRYPOINT ["gdb", "-batch", "-ex", "run", "-ex", "set $i = $_exitcode", "-ex", "bt", "-ex", "print $i", "-ex", "quit $i", "--args", "python", "main.py"]

# ENTRYPOINT [ "python", "main.py" ]
