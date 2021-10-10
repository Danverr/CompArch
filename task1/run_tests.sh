run_test () {
  echo "========== RUNNING TEST $1 ==========\c"
  time "bin/task1" -f "$1/input.txt" "$1/output.txt"
  cmp --s "$1/output.txt" "$1/answer.txt" && echo "Result: OK" || echo "Result: WA"
}

run_random_test() {
  echo "========== RUNNING RANDOM TEST $1 ==========\c"
  time "bin/task1" -n $2 "$1/output.txt"
}

run_test "tests/test_all_types_1"
run_test "tests/test_all_types_2"
run_test "tests/test_empty_input"
run_random_test "tests/random_test_1" 1
run_random_test "tests/random_test_10" 10
run_random_test "tests/random_test_100" 100
run_random_test "tests/random_test_1000" 1000
run_random_test "tests/random_test_10000" 10000