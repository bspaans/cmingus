#!/bin/bash

./src/mingus_core

tests_run=$?

if [ $tests_run != "134" ]; then
	./src/mingus_containers $tests_run
fi;

