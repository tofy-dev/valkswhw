#! /bin/bash

counter=1

while [ $counter -le 100000 ]
do
    echo $counter
    ((counter++))
done

echo Counting is a great way to greet people. Hello there!
