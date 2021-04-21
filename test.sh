#!/bin/bash

args=$(./generate_random.py $1)
./f $args | ./checker $args
./f $args | ./count_operations.py