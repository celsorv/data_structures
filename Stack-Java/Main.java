/*********
 * Stack using linked list
 * 
 * UNIVESP - www.univesp.br
 * Computer Engineering
 * Data structures discipline
 */

package com.crv;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        ItemType stackItem = null;
        Stack<ItemType> stack = new StackLinkedList<>();

        // left... curly bracket, square bracket, round bracket and angle bracket
        final char[] leftBrackets = { '{', '[', '(', '<' };

        // right... curly bracket, square bracket, round bracket and angle bracket
        final char[] rightBrackets = { '}', ']', ')', '>' };

        boolean isMatched = true;

        System.out.println("\nInsira uma String.");
        System.out.print("?: ");
        String entry = (new Scanner(System.in)).next();

        int entryLength = entry.length();
        int entryIndex = 0;

        while (isMatched && entryIndex < entryLength)
        {
            ItemType character = new ItemType(entry.charAt(entryIndex));

            if (inArray(character.value, leftBrackets)) // is a left bracket
                stack.push(character);
            else
            {
                int index = indexOf(character.value, rightBrackets);

                if (index != -1)    // is a right bracket
                {
                    if (stack.isEmpty())    // stated with the right bracket
                        isMatched = false;
                    else
                    {
                        stackItem = stack.pop();
                        isMatched = (stackItem.value == leftBrackets[index]); // paired with last
                    }
                }

            }

            entryIndex++;
        }

        if (isMatched && stack.isEmpty())
            System.out.println("Bem formada");
        else
            System.out.println("Mal formada");

    }

    private static boolean inArray(char character, char[] brackets) {
        return indexOf(character, brackets) != -1;
    }

    private static int indexOf(char character, char[] brackets) {
        int sizeOfArray = brackets.length;

        for (int i = 0; i < sizeOfArray; i++)
            if (character == brackets[i]) return i;

        return -1;
    }

}
