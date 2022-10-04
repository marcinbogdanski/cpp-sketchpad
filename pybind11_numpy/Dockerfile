FROM python:3.9.7-slim

RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    build-essential

RUN pip install numpy
RUN pip install pandas
RUN pip install pybind11

RUN useradd -ms /bin/bash appuser
USER appuser

COPY --chown=appuser:appuser . /home/appuser/app
WORKDIR /home/appuser/app

RUN make

ENTRYPOINT [ "python", "main.py" ]
