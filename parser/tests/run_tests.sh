#!/bin/bash

# make binary

ICL=tests/maps/invalid_maps/invalid_config_lines
IML=tests/maps/invalid_maps/invalid_map_lines
VM=tests/maps/valid_maps

ICLM=(no_ceil_color.cub \
no_floor_color.cub \
no_no_texture.cub \
no_so_texture.cub \
no_we_texture.cub \
no_ea_texture.cub)

IMLM=(no_player.cub \
two_players.cub \
unclosed_wall_by_empty_space.cub \
unclosed_wall_by_player.cub)

VMM=(valid_map_big.cub \
valid_map_smallest.cub \
valid_map.cub)

function red () {
	echo -n "$(tput setaf 1)$1$(tput sgr0)"
}

function green () {
	echo -n "$(tput setaf 2)$1$(tput sgr0)"
}

test_num=0
test_passed=0
test_failed=0

{
	../parser/parser 2>&1 | grep "Error" 1>/dev/null

	exit_status=$?
	((test_num++))
	printf 'Test %d\t- ' "$test_num"
	if [ $exit_status == 0 ]; then
		green PASS
		((test_passed++))
	else
		red FAIL
		((test_failed++))
	fi
	echo -n " - $exit_status"
	echo " - no map provided"
}

for map in "${ICLM[@]}"; do
	../parser/parser "$ICL/${map}" 2>&1 | grep "Error" 1>/dev/null

	exit_status=$?
	((test_num++))
	printf 'Test %d\t- ' "$test_num"
	if [ $exit_status == 0 ]; then
		green PASS
		((test_passed++))
	else
		red FAIL
		((test_failed++))
	fi
	echo -n " - $exit_status"
	echo " - ${map}"
done

for map in "${IMLM[@]}"; do
	../parser/parser "$IML/${map}" 2>&1 | grep "Error" 1>/dev/null

	exit_status=$?
	((test_num++))
	printf 'Test %d\t- ' "$test_num"
	if [ $exit_status == 0 ]; then
		green PASS
		((test_passed++))
	else
		red FAIL
		((test_failed++))
	fi
	echo -n " - $exit_status"
	echo " - ${map}"
done

for map in "${VMM[@]}"; do
	../parser/parser "$VM/${map}" 2>&1

	exit_status=$?
	((test_num++))
	printf 'Test %d\t- ' "$test_num"
	if [ $exit_status == 0 ]; then
		green PASS
		((test_passed++))
	else
		red FAIL
		((test_failed++))
	fi
	echo -n " - $exit_status"
	echo " - ${map}"
done

echo "-----------------------------------------------------"
echo "total num of test - $test_num | $(green "passed - $test_passed") | $(red "failed - $test_failed")"; 