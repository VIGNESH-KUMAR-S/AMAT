# Stack Functions

1. empty()
	- Check whether the stack is empty or not.
	- If stack is empty then it returns non-zero otherwise it returns 0.

2. size()
    - Gives the size of the stack.
    - Returns an integer which represents size.

3. top()
    - Used to get the top element in the stack.
    - It is not deleted the element but returns the reference to the element.

4. push()
    - Used to push the existing element/object at the top of the stack.
    - It takes only one argument.

5. pop()
    - Used to delete the element/object at the top of the stack.

6. swap()
    - Used to swap the elements between two seperate stacks.

7. emplace()
    - Used to create and then push the element/object at the top of the stack.
    - It takes any number of arguments, but this is always less than or equal to the number of parameters in constructor where this emplace() is used.
    - Because this function internally using concept called var-args.