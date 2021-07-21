# RabbitMQ

Build:

* make sure `librabbitmq-dev` is installed
  * make sure and `librabbitmq.a` is in linker path (should be by default)

Run:

* start RabbitMQ on localhost, e.g. via docker container
* create `test queue` and bind to `amq.direct` exchange
  * don't forget to specify `test queue` as bind key as well
* in terminal run `./amqp_producer localhost 5672 1 1`
  * `localhost` is IP/host of RabbitMQ server
  * `5672` is the TCP/IP port of RabbitMQ server
  * first `1` is rate limit sending to one message per second
  * second `1` is number of messages to send
