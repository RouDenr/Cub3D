#!/bin/bash

# make binary

# CHLEAKS=1

ICL=tests/maps/invalid_maps/invalid_config_lines
IML=tests/maps/invalid_maps/invalid_map_lines
VM=tests/maps/valid_maps

ICLM=(
no_ceil_color.cub 
no_floor_color.cub 
no_no_texture.cub
no_so_texture.cub
no_we_texture.cub
no_ea_texture.cub
double_ceil_color.cub
double_floor_color.cub
double_no_texture.cub
double_so_texture.cub
double_we_texture.cub
double_ea_texture.cub)

ICLMC=(
wrong_ceil_color_1.cub  wrong_ceil_color_2.cub  wrong_ceil_color_3.cub  wrong_ceil_color_4.cub  
wrong_ceil_color_5.cub  wrong_ceil_color_6.cub  wrong_ceil_color_7.cub  wrong_ceil_color_8.cub
wrong_floor_color_1.cub wrong_floor_color_2.cub wrong_floor_color_3.cub wrong_floor_color_4.cub
wrong_floor_color_5.cub wrong_floor_color_6.cub wrong_floor_color_7.cub wrong_floor_color_8.cub)

ICLMT=(
wrong_no_texture_1.cub wrong_no_texture_2.cub wrong_so_texture_1.cub wrong_so_texture_2.cub
wrong_we_texture_1.cub wrong_we_texture_2.cub wrong_ea_texture_1.cub wrong_ea_texture_2.cub)

IMLM=(
no_player.cub
two_players.cub
unclosed_wall_by_empty_space.cub
unclosed_wall_by_player.cub
empty_line_in_map_middle.cub
whitespaces_line_in_map_middle.cub
config_line_in_map_middle.cub
map_line_on_file_start.cub
no_map_lines_1.cub
no_map_lines_2.cub
no_extention    
wrong_extention_1.ca
wrong_extention_2.cuba
wrong_extention_3.)

VMM=(
valid_map_big.cub
valid_map_smallest.cub
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
	printf "%s" "$1"
}

function check_leaks () {
	exit_status=$?
	if [ "$CHLEAKS" == 1 ]; then
		if [ $exit_status == 0 ]; then
			green " - no leaks"
		else
			((leaks_num++))
			red " - leaks!"
		fi
		echo " - $exit_status"
	else
		echo ""
	fi
}

############################################################################################
############################################################################################
############################################################################################
test_num=0
test_passed=0
test_failed=0
leaks_num=0

{
	../parser/parser 2>&1 | grep "Error" 1>/dev/null
	do_test " - no map file provided"
	[[ $CHLEAKS == 1 ]] && leaks -atExit -- ../parser/parser 1>/dev/null 2>&1
	check_leaks
}
printf '\n--------------------------------------------------\n\n'

for map in "${ICLM[@]}"; do
	../parser/parser "$ICL/${map}" 2>&1 | grep "Error" 1>/dev/null
	do_test " - ${map}"
	[[ $CHLEAKS == 1 ]] && leaks -atExit -- ../parser/parser "$ICL/${map}" 1>/dev/null 2>&1
	check_leaks
done
printf '\n--------------------------------------------------\n\n'

for map in "${IMLM[@]}"; do
	../parser/parser "$IML/${map}" 2>&1 | grep "Error" 1>/dev/null
	do_test " - ${map}"
	[[ $CHLEAKS == 1 ]] && leaks -atExit -- ../parser/parser "$IML/${map}" 1>/dev/null 2>&1
	check_leaks
done
printf '\n--------------------------------------------------\n\n'

for map in "${VMM[@]}"; do
	../parser/parser "$VM/${map}" 2>&1
	do_test " - ${map}"
	[[ $CHLEAKS == 1 ]] && leaks -atExit -- ../parser/parser "$VM/${map}" 1>/dev/null 2>&1
	check_leaks
done
printf '\n--------------------------------------------------\n\n'

for map in "${ICLMC[@]}"; do
	../parser/parser "$ICL/${map}" 2>&1 | grep "Error" 1>/dev/null
	do_test " - ${map}"
	[[ $CHLEAKS == 1 ]] && leaks -atExit -- ../parser/parser "$ICL/${map}" 1>/dev/null 2>&1
	check_leaks
done
printf '\n--------------------------------------------------\n\n'

for map in "${ICLMT[@]}"; do
	../parser/parser "$ICL/${map}" 2>&1 | grep "Error" 1>/dev/null
	do_test " - ${map}"
	[[ $CHLEAKS == 1 ]] && leaks -atExit -- ../parser/parser "$ICL/${map}" 1>/dev/null 2>&1
	check_leaks
done

printf "\n--------------------------------------------------\n"
echo "total num of test - $test_num 
| $(green "passed - $test_passed") 
| $(red "failed - $test_failed")
$([[ $CHLEAKS == 1 ]] && echo "| leaks - $leaks_num")";