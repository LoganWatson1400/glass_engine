.PHONY: build config test run reconfig clean

build:
	mkdir -p build && cd build && cmake .. && make

config:
	mkdir -p build && cd build && cmake ..

test:
	cd build && make -s tests && ./tests

run:
	cd build && make -s glass_engine_game && ./glass_engine_game

reconfig:
	cd build && cmake ..

clean:
	rm -rf build