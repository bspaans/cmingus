#!/bin/bash

./src/mingus_core

tests_run=$?

if [ $tests_run != "134" ]; then
	./src/mingus_containers $tests_run
	tests_run=$?
else
	echo "Not passing all tests in core."
	exit 1
fi;


if [ $tests_run != "134" ]; then
	./src/mingus_midi $tests_run
	tests_run=$?
else
	echo "Not passing all tests in containers."
	exit 1
fi;


if [ $tests_run = "134" ]; then
	echo "Not passing all tests in containers."
	exit 1
fi;

