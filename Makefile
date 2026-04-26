test:
	cd build && cmake .. -DCMAKE_BUILD_TYPE=Debug > /dev/null 2>&1 && make -s tests && ./tests

build:
	mkdir -p build && cd build && cmake .. && make

reconfig:
	cd build && cmake ..

clean:
	rm -rf build