/*********
 * Stack using linked list
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

package com.crv;

public class StackLinkedList<T> implements Stack<T> {

    private Node<T> top = null;

    private static class Node<T> {
        public T item;
        public Node next;
    }

    @Override
    public boolean isEmpty() {
        return top == null;
    }

    @Override
    public void push(T item) {
        Node<T> newNode = new Node<>();
        newNode.item = item;
        newNode.next = top;
        top = newNode;
    }

    @Override
    public T pop() {
        if (isEmpty())
            throw new RuntimeException("Stack is empty!");

        T aux = top.item;
        top = top.next;

        return aux;
    }

}
