#!/bin/bash

echo "Checking file example.txt."
expec="$(sha256sum example.txt)"
myout="$(./sha256 example.txt)  example.txt"
echo "Expected: " $expec
echo "Output:   " $myout
if [[ $myout == $expec ]]; then
    echo "Pass"
else
    echo "Fail"
fi

echo "Checking file random.txt."
expec="$(sha256sum random.txt)"
myout="$(./sha256 random.txt)  random.txt"
echo "Expected: " $expec
echo "Output:   " $myout
if [[ $myout == $expec ]]; then
    echo "Pass"
else
    echo "Fail"
fi