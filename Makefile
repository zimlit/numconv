check: test/*
	gcc test/check_intconv.c -lm -lcheck -o bin/check_intconv
	gcc test/check_floatconv.c -lm -lcheck -o bin/check_floatconv
	./bin/check_intconv
	./bin/check_floatconv

install: src/*
	cp src/* /usr/local/include