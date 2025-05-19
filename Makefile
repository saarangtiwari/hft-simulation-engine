.PHONY: run
run:
	@clang++ src/main.cpp -o build/main && build/main
