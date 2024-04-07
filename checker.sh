#!/usr/bin/bash
POINTS=(
            2.5 2.5
            2.5 2.5
            5
            2 2 2
            3 3 
            5 5
            5 5
            2 2 2
            5
            5 5 5
            3 3
            3 3
            2 2 2 2 2
        )
TESTS=30
TOTAL=100
TOTALTESTS=0 
VALGRINDTEST=0

function readme() {
    if test -f "README" || test -f "README.md"
        then
            echo "README: 5/5"
            let TOTALTESTS+=5
    else
        echo "README: 0/5"
    fi
}

function checkExe() {
    if test -f "main"
        then
            main
    else
        echo "The executable file needs to be named 'main'"
    fi
}

function valgrindTest() {
    valgrind --leak-check=full --error-exitcode=1 ./main 1> /dev/null 2>&1
    if [ "$?" -ne 0 ]
        then
            echo "    Valgrind failed"
    else
        echo "  Valgrind test$1.in: 1/1"
        let VALGRINDTEST+=1
    fi
}

function testInput() {
    cat tests/Input/test$1.in > ./tests/tests.in
    ./main

    if [ "$?" -eq 139 ]
        then
            echo "test$1.in: segmentation fault"
            return
    fi

    diff tests/Output/test$1.out ./tests/tests.out > /dev/null 2>&1
    if [ "$?" -ne 0 ]
        then
            echo "test$1.in: 0/${POINTS[$1-1]}"
    else
        echo "test$1.in: ${POINTS[$1-1]}/${POINTS[$1-1]}"
        TOTALTESTS=$(echo "$TOTALTESTS + ${POINTS[$1-1]}" | bc)
        valgrindTest    
    fi
}

function makeCommand() {
    make 1> /dev/null
    if [ "$?" -ne 0 ]
        then
            exit 1
    fi
}

function main() {
    echo " -= Harry's train =-"
    echo

    touch ./tests/tests.in
    touch ./tests/tests.out

    readme

    for i in $(seq 1 $TESTS)
    do
        testInput $i
    done
    
    echo
    echo "Total: $TOTALTESTS/$TOTAL"
    let VALGRINDTEST=$VALGRINDTEST*20/30
    echo "Valgrind: $VALGRINDTEST/20"
}
makeCommand
checkExe
