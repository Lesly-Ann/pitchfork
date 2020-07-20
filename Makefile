
.PHONY: spectrev4 tests spectrev1 test

all: spectrev1 spectrev4 tests test

spectrev1:
	-timeout 1h python pitchfork.py spectrev1

spectrev1masking:
	-timeout 1h python pitchfork.py spectrev1masking

spectrev4:
	-timeout 1h python pitchfork.py 01
	-timeout 1h python pitchfork.py 02
	-timeout 1h python pitchfork.py 03
	-timeout 1h python pitchfork.py 04
	-timeout 1h python pitchfork.py 05
	-timeout 1h python pitchfork.py 06
	-timeout 1h python pitchfork.py 07
	-timeout 1h python pitchfork.py 08
	-timeout 1h python pitchfork.py 09
	-timeout 1h python pitchfork.py 09_bis
	-timeout 1h python pitchfork.py 10
	-timeout 1h python pitchfork.py 11
	-timeout 1h python pitchfork.py 12
	-timeout 1h python pitchfork.py 13

tests:
	-timeout 1h python pitchfork.py 10
	-timeout 1h python pitchfork.py 11
	-timeout 1h python pitchfork.py 12
	-timeout 1h python pitchfork.py 13

test:
	-timeout 1h python pitchfork.py test	
