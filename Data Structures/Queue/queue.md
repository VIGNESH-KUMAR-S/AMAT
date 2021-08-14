# Queue Functions
- Insertion is done at rear(back) end and deletion is done at front end.
    ![](https://www.callicoder.com/static/756cf2c68e5810a2f37f27ce1ce562a8/51aac/queue-data-structure.jpg)

1. empty()
	- Check whether the queue is empty or not.
	- If queue is empty then it returns non-zero otherwise it returns 0.

2. size()
    - Gives the size of the queue.
    - Returns an integer which represents size.

3. front()
    - Used to get the top element in the queue.
    - Used to get the first pushed element in queue.
    - It is not deleted the element but returns the reference to that element.

4. back()
    - Used to get the last element in the queue.
    - Used to get the last pushed element in queue.
    - It is not deleted the element but returns the reference to that element.

5. push()
    - It is also known as **enqueue**.
    - This is done at **rear** end.
    - Used to push the existing element/object at the top of the queue.
    - It takes only one argument.

6. pop()
    - It is also known as **dequeue**.
    - This is done at **front** end.
    - Used to delete the element/object at the top of the queue.

7. swap()
    - Used to swap the elements between two seperate queues.

8. emplace()
    - Used to create and then push the element/object at the top of the queue.
    - It takes any number of arguments, but this is always less than or equal to the number of parameters in constructor where this emplace() is used.
    - Because this function internally using concept called var-args.