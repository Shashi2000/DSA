# DSA

# Queue

A Queue is a linear structure which follows a particular order in which the operations are performed. The order is First In First Out (FIFO). A good example of a queue is any queue of consumers for a resource where the consumer that came first is served first. The difference between stacks and queues is in removing. In a stack we remove the item the most recently added; in a queue, we remove the item the least recently added.

## Some operations performed on Queue
* enqueue:
    This operation inserts element to the Queue if its not full.
* dequeue:
    This operation deletes the first element of the Queue if its not empty.
* peek:
    This operation returns the first element of the Queue if its not empty.
* isFull:
    This operation returns `True` if the Queue is completely full else returns `False`.
* isEmpty:
    This operation return `True` if the Queue is completely empty elese returns `False`.

## Types of Queue
1. Linear Queue (Simple Queue)
2. Circular Queue
3. Priority Queue
4. Dequeue (Double Ended Queue)

## Linear Queue
  In a simple queue, insertion takes place at the rear and removal occurs at the front. It strictly follows the FIFO (First in First out) rule.
  
## Circular Queue
  In a circular queue, the last element points to the initial element creating a circular link. The main advantage of a circular queue over a simple queue is better memory  utilization. If the last position is full and the first position is empty, we can insert an element in the first position. This action is not possible in a simple queue 
