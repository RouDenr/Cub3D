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

ICLMC=(
wrong_ceil_color_1.cub  wrong_ceil_color_2.cub  wrong_ceil_color_3.cub  wrong_ceil_color_4.cub  
wrong_ceil_color_5.cub  wrong_ceil_color_6.cub  wrong_ceil_color_7.cub  wrong_ceil_color_8.cub
wrong_floor_color_1.cub wrong_floor_color_2.cub wrong_floor_color_3.cub wrong_floor_color_4.cub
wrong_floor_color_5.cub wrong_floor_color_6.cub wrong_floor_color_7.cub wrong_floor_color_8.cub)

ICLMT=(
wrong_no_texture_1.cub wrong_no_texture_2.cub wrong_so_texture_1.cub wrong_so_texture_2.cub wrong_we_texture_1.cub wrong_we_texture_2.cub wrong_ea_texture_1.cub wrong_ea_texture_2.cub)

IMLM=(no_player.cub \
two_players.cub \
unclosed_wall_by_empty_space.cub \
unclosed_wall_by_player.cub)

VMM=(valid_map_big.cub \
valid_map_smallest.cub \
valid_map.cub)

############################################################################################
############################################################################################
############################################################################################

function red () {
	echo -n "$(tput setaf 1)$1$(tput sgr0)"
}

function green () {
	echo -n "$(tput setaf 2)$1$(tput sgr0)"
}

function do_test () {
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
	echo "$1"
}
############################################################################################
############################################################################################
############################################################################################
test_num=0
test_passed=0
test_failed=0

{
	../parser/parser 2>&1 | grep "Error" 1>/dev/null
	do_test " - no map provided"
}
printf '\n--------------------------------------------------\n\n'

for map in "${ICLM[@]}"; do
	../parser/parser "$ICL/${map}" 2>&1 | grep "Error" 1>/dev/null
	do_test " - ${map}"
done
printf '\n--------------------------------------------------\n\n'

for map in "${IMLM[@]}"; do
	../parser/parser "$IML/${map}" 2>&1 | grep "Error" 1>/dev/null
	do_test " - ${map}"
done
printf '\n--------------------------------------------------\n\n'

for map in "${VMM[@]}"; do
	../parser/parser "$VM/${map}" 2>&1
	do_test " - ${map}"
done
printf '\n--------------------------------------------------\n\n'

for map in "${ICLMC[@]}"; do
	../parser/parser "$ICL/${map}" 2>&1 | grep "Error" 1>/dev/null
	do_test " - ${map}"
done
printf '\n--------------------------------------------------\n\n'

for map in "${ICLMT[@]}"; do
	../parser/parser "$ICL/${map}" 2>&1 | grep "Error" 1>/dev/null
	do_test " - ${map}"
done

printf "\n--------------------------------------------------\n"
echo "total num of test - $test_num | $(green "passed - $test_passed") | $(red "failed - $test_failed")"; 