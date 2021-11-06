#!/bin/sh

run_test() {
  printf "========== RUNNING TEST $1 =========="
  time python3 "main.py" -f "$1/input.txt" "$1/output.txt"
  cmp --s "$1/output.txt" "$1/answer.txt" && printf "Result: OK\n" || printf "Result: WA\n"
}

run_random_test() {
  printf  "========== RUNNING RANDOM TEST $1 =========="
  time python3 "main.py" -n $2 "$1/output.txt"
}

run_test "tests/test_all_types_1"
run_test "tests/test_all_types_2"
run_test "tests/test_empty_input"
run_test "tests/complex_only"
run_test "tests/fraction_only"
run_test "tests/polar_only"
run_random_test "tests/random_test_1" 1
run_random_test "tests/random_test_10" 10
run_random_test "tests/random_test_100" 100
run_random_test "tests/random_test_1000" 1000
run_random_test "tests/random_test_10000" 10000