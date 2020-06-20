# DataStructuresAndAlgorithms

I'm taking this oppurtunity to work in C (which I love doing, but I don't really get the chance because I don't work in a relevant domain) and implement a lot of datastructures (which you've got to build it at least once if you want to use a common implementation). This isn't anything critical so don't expect too much error checking unless it really becomes a problem for me.

Feel free to look around if you so desire!

## Completed So Far

Arrays - Complete

Linked List - Complete

Stack - Complete

Queue - Soon(TM)

HashTable - Eventaully(TM)

## Notes

I'm not using compile time arrays, because I want to have as much control as possible (well as much as I can get with the code still being portable in C ie. no x86).

# Descriptions

## Array

It's an array. Just some pointer manipulation and auto resizing.

## Linked List

I implimented it using single nodes instead of clusters or simulating it with an array. Clusters could probably reduce the amount of time spent allocating, but would increase the cost of inserting and deleting. I'd argue that'd defeat the purpose of the linked list so I'm just sticking with single nodes.

## Stack

Easy dynamic array implemented stack. Potentially large memory overhead due to resize using a factor of 2 (instead of say 1.5, 1.25), but the implementation is simple and fast in most cases (ok, maybe not the fastest because of the heavy indirection, but that could just be inlined need be).

## Queue - Soon(TM)

I did a unfurled linked list because I get (most of) the speed from array and the ease of implementation of a linked list.  