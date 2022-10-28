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

# wait, what?
# * https://stackoverflow.com/questions/20179153/gdb-backtrace-with-no-user-input
# * https://www.commandlinefu.com/commands/view/4039/print-stack-trace-of-a-core-file-without-needing-to-enter-gdb-interactively
ENTRYPOINT [ "gdb", "-batch", "-ex", "run", "-ex", "bt", "--args", "python", "main.py"]

# ENTRYPOINT [ "python", "main.py" ]
