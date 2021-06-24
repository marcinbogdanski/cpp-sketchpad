all: amqp_producer

amqp_producer: utils.c platform_utils.c amqp_producer.c
	g++ -I/usr/include -o amqp_producer utils.c platform_utils.c amqp_producer.c -lrabbitmq

clean:
	rm amqp_producer
