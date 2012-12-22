#!/bin/bash

#include 
source utility.sh

#--main routine
sleep 5

while true; do
#-shift away mouse from screen
    xte "mousemove 2 2"
    echo launching bobber
#-launch binded float key
    xte "key 7"
#-wait float to be visible
    sleep 2
#-take a screenshot with high priority
    nice -n 19 scrot /tmp/botscreen.png 
    echo searching bobber
#-scanning scrnshot to find float 
    position=$(./scanner)
    x=$(echo $position | awk '{print $1}')
    y=$(echo $position | awk '{print $2}')
    echo suspected location: $x $y
    x=$[ $x + 30 ]
    xte "mousemove $x $y"
    x=$[ $x - 30 ]
    (( x+=1 )) #adjusting aim---TO BE FIXED
    #(( y+=1 ))
#-movement searching routine
    while true; do
 	nice -n 19 scrot /tmp/botscreen.png
#-find high float movement in the area
 	trigger=$(./clicker $x $y)
#-if float moved considerably
 	if [ $trigger = "movement" ]
 	then
#-loot
	    xte "mousemove $x $y"
 	    xte "keydown Shift_L"
 	    xte "mouseclick 3"
 	    xte "keyup Shift_L"                   
	    break
	fi
#-repeat the search every 0,2s
	sleep 0.2
    done
done
