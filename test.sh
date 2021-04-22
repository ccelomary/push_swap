#!/bin/bash

args=$(./generate_random.py $1)
./push_swap $args | ./checker $args
./push_swap $args | ./count_operations.py