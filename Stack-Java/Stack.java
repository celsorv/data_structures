/*********
 * Stack using linked list
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

package com.crv;

public interface Stack<T> {

    public boolean isEmpty();
    public void push(T item);
    public T pop();

}
