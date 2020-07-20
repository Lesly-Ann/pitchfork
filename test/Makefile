CC=gcc
CFLAGS=-m32 -march=i386 -fno-stack-protector -static -no-pie -fno-pic

.PHONY: all spectrev1 forwarding test
all : spectrev1 forwarding test

test : test.c
	$(CC) $(CFLAGS) $< -o $@

spectrev1 : spectrev1.c
	$(CC) $(CFLAGS) $< -o $@

forwarding : forwarding.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean :
	rm spectrev1 forwarding
