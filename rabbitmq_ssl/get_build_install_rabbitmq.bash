#!/bin/bash

# Note: while rabbitmq-c can be installed via librabbitmq-dev package on 
# Debian, the package is compiled without SSL support. Because of that we
# have to install from source. We also want more recent version than in package.

# Download latest rabbitmq-c
cd /root
wget https://github.com/alanxz/rabbitmq-c/archive/refs/tags/v0.11.0.zip
unzip v0.11.0.zip

# Build the library
cd rabbitmq-c-0.11.0
mkdir build
cd build
cmake ..
cmake --build .

# Put it somewhere linker can see it
make install
cp /usr/local/lib/x86_64-linux-gnu/librabbitmq.so /usr/lib/x86_64-linux-gnu/librabbitmq.so
ln -s /usr/lib/x86_64-linux-gnu/librabbitmq.so /usr/lib/x86_64-linux-gnu/librabbitmq.so.4

# Now we can compile RabbitMQ programs by adding -lrabbitmq flag
