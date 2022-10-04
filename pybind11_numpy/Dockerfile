FROM python:3.9.7-slim

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential

RUN pip install numpy
RUN pip install pybind11

RUN useradd -ms /bin/bash appuser
USER appuser

COPY --chown=appuser:appuser . /home/appuser/app
WORKDIR /home/appuser/app

RUN c++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` example.cpp -o example`python3-config --extension-suffix`

ENTRYPOINT [ "python", "main.py" ]
