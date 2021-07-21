all: amqps_producer

amqps_producer: utils.c platform_utils.c amqps_producer.c
	g++ -I/usr/include -o amqps_producer utils.c platform_utils.c amqps_producer.c -lrabbitmq

clean:
	rm amqps_producer
