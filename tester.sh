#!/bin/bash

make gcovr

clear

function do_test() {
    file=$1
    error_code=$2
    shift 2
    ./palindrome "$@" > tmp
    return_value=$?
    cmp tmp "$file"
    compare=$?
    echo -en "return value: "
    if [ $return_value -eq $error_code ]
    then
        echo -en "\033[32mOK\033[0m"
    else
        echo -en "\033[31mKO\033[0m"
    fi
    echo -n " output: "
    if [ $compare -eq 0 ]
    then
        echo -en "\033[32mOK\033[0m"
    else
        echo -en "\033[31mKO\033[0m"
    fi
    echo -e "\tpalindrome" "$@"
    rm tmp
}

do_test results/test1.res 0 -n 4782 -b 10
do_test results/test2.res 0 -n 64 -b 2
do_test results/test3.res 84 -n 4782 toto
do_test results/test4.res 0 -p 363 -b 10
do_test results/test5.res 0 -p 363 -b 10 -imax 2
do_test results/test6.res 0 -p 363 -b 10 -imin 6
do_test results/test7.res 0 -p 363 -b 10 -imin 7
do_test results/1-A.res 0 -n 4782
do_test results/1-B.res 0 -n 4782 -b 10
do_test results/1-C.res 0 -n 363
do_test results/1-D.res 0 -n 363 -b 10
do_test results/1-E.res 0 -n 100 -b 2
do_test results/1-F.res 0 -n 122 -b 5
do_test results/1-G.res 0 -n 457 -b 5
do_test results/1-H.res 0 -n 457 -b 2

do_test results/2-A.res 0 -n 2784 -imin 1
do_test results/2-B.res 0 -n 2784 -imin 2
do_test results/2-C.res 0 -n 100 -b 5 -imin 2
do_test results/2-D.res 0 -n 2 -imin 10
do_test results/2-E.res 0 -n 2 -imax 10
do_test results/2-F.res 0 -n 10 -imax 3
do_test results/2-G.res 0 -n 10 -b 5 -imax 3
do_test results/2-H.res 0 -n 100 -b 5 -imax 0
do_test results/2-I.res 0 -n 100 -b 5 -imin 1 -imax 5
do_test results/2-J.res 0  -n 100 -b 4 -imin 1 -imax 5

do_test results/3-A.res 0 -p 363
do_test results/3-B.res 0 -p 242
do_test results/3-C.res 0 -p 121
do_test results/3-D.res 0 -p 565
do_test results/3-E.res 0 -p 100 -b 9
do_test results/3-F.res 0 -p 2 -b 3
do_test results/3-G.res 0 -p 2 -b 6

do_test results/5-A.res 84 -n
do_test results/5-B.res 84 -n toto
do_test results/5-C.res 84 -toto
do_test results/5-D.res 84 -n  55 -b -1
do_test results/5-E.res 84 -n  55 -b 11
do_test results/5-F.res 84 -n  55 -b toto
do_test results/5-G.res 84 -n 55 -p 50
do_test results/5-H.res 84 -p



gcovr -r . --branches --txt

echo -e '\n\033[32;1mIF YOU WANT A REALLY NICE OUTPUT I SUGGEST YOU TO TYPE "make report_html" :))\033[0m'
