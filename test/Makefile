CC=clang
CFLAGS=-O0

.PHONY: all
all : spectrev1 forwarding

test : test.c
	$(CC) $(CFLAGS) $< -o $@

spectrev1 : spectrev1.c
	$(CC) $(CFLAGS) $< -o $@

forwarding : forwarding.c
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean :
	rm spectrev1 forwarding
