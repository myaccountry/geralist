static: libgeralist.a

libgeralist.a: geralist.o
	ar rcs $@ $^

geralist.o: geralist.cpp geralist.h
	g++ -c $< -o $@

clean:
	rm geralist.o libgeralist.a

install:
	sudo cp libgeralist.a /usr/local/lib/ && sudo cp geralist.h /usr/local/include/

all:
	make && make install && make clean