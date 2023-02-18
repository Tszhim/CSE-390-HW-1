#!/bin/bash

basic_test() {
    $(./bin/main "./tests/basic_test.txt")

    if [ $? -eq 0 ]; then
        echo "basic_test passed."
    else
        echo "basic_test failed".
    fi
}

jagged_house_test() {
    $(./bin/main "./tests/jagged_house_test.txt")

    if [ $? -eq 0 ]; then
        echo "jagged_house_test passed."
    else
        echo "jagged_house_test failed".
    fi
}

jagged_house_test2() {
    $(./bin/main "./tests/jagged_house_test2.txt")

    if [ $? -eq 0 ]; then
        echo "jagged_house_test2 passed."
    else
        echo "jagged_house_test2 failed".
    fi
}

single_space_test() {
    $(./bin/main "./tests/single_space_test.txt")

    if [ $? -eq 0 ]; then
        echo "single_space_test passed."
    else
        echo "single_space_test failed".
    fi
}

uncleanable_dirt_test() {
    $(./bin/main "./tests/uncleanable_dirt_test.txt")

    if [ $? -eq 0 ]; then  
        echo "uncleanable_dirt_test passed."
    else
        echo "uncleanable_dirt_test failed".
    fi
}

house_data_fail_test() {
    out=$(./bin/main "./tests/house_data_fail_test.txt")

    if [ $? -ne 0 -a "$out" = "Input file format error or I/O error." ]; then
        echo "house_data_fail_test passed."
    else
        echo "house_data_fail_test failed."
    fi
}

house_data_fail_test2() {
    out=$(./bin/main "./tests/house_data_fail_test2.txt")

    if [ $? -ne 0 -a "$out" = "Input file format error or I/O error." ]; then
        echo "house_data_fail_test2 passed."
    else
        echo "house_data_fail_test2 failed."
    fi
}

robot_data_fail_test() {
    out=$(./bin/main "./tests/robot_data_fail_test.txt")

    if [ $? -ne 0 -a "$out" = "Input file format error or I/O error." ]; then
        echo "robot_data_fail_test passed."
    else
        echo "robot_data_fail_test failed."
    fi
}

robot_data_fail_test2() {
    out=$(./bin/main "./tests/robot_data_fail_test2.txt")
    
    if [ $? -ne 0 -a "$out" = "Input file format error or I/O error." ]; then
        echo "robot_data_fail_test2 passed."
    else
        echo "robot_data_fail_test2 failed."
    fi
}

# Compile source code. 
make

# Run all tests. 
basic_test
jagged_house_test
jagged_house_test2
single_space_test
uncleanable_dirt_test
house_data_fail_test
house_data_fail_test2
robot_data_fail_test
robot_data_fail_test2

# Cleanup.
make clean
rm -f output.txt
