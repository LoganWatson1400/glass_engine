test:
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug > /dev/null 2>&1 && make -s && ./tests

build:
	mkdir -p build && cd build && cmake .. && make

clean:
	rm -rf build