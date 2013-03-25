// HelloStrings.java

/**
  A class to introduce you to class String
*/
public class HelloStrings
{
  //-------------------------------------------------------main()
  /**
    <p>Creates and uses Some String objects.
    It is strongly suggested that you look up class String
    in the API documenation (package java.lang) and try
    to use a few of the methods by adding instructions to
    this program and recompiling.</p>
    
    <p>You should add some Javadoc comments to the code
    to explain each of the methods that you use, what you
    were trying to denonstate and whether it worked or not.
    Then create the javadoc documentation for this class.</p>
        
    <p>Note that there is no object of class HelloStrings
    in this application.</p>
  */
  public static void main(String[] args)
  {
    //---------------------------Lab 1-----------------------------------//
    System.out.println("-----------------Lab 1-------------------");
    // Example strings
    String word1 = "Hello";
    String word2 = "World";
    String word3 = "Hello World";
    
    // QUESTION 1
    System.out.println("\n--------------Question 1----------------\n");
    System.out.println("Answer 1: I tried public char charAt(int index)");
    
    char temporaryChar;
    // charAt will go to the index of 1 in the word1 string and take that char and return it.
    temporaryChar = word1.charAt(1);
    System.out.println("This is charAt(): " + temporaryChar);

    // QUESTION 2
    System.out.println("\n--------------Question 2----------------\n");
    System.out.println("Answer 2: I tried public String substring(int beginIndex, int endIndex)");
    
    String temp;
    // substring() will take every char from position 0 to position 4 in the word3 string.
    temp = word3.substring(0, 4);
    System.out.println("This is substring(): " + temp);
    
    // QUESTION 3
    System.out.println("\n--------------Question 3----------------\n");
    System.out.println("Answer 3: I tried public int compareTo(String anotherString)");
    
    // compareTo will return a negative value, because word3 is bigger than word1.
    int compareNum = word1.compareTo(word3);
    System.out.println("This is compareTo(): " + compareNum);
    
    // compareTo will return 0, because both strings are equal.
    compareNum = word3.compareTo(word3);
    System.out.println("This is compareTo(): " + compareNum);
    
    // compareTo will return a positive value, because word3 is smaller than word2.
    compareNum = word2.compareTo(word3);
    System.out.println("This is compareTo(): " + compareNum);
    
    // QUESTION 4
    System.out.println("\n--------------Question 4----------------\n");
    System.out.println("Answer 4: I tried public int indexOf(String str)");
    
    int index;
    // Will return the first index/position of the first letter of the string "World" within the string "Hello World" once
    // it finds it.
    index = word3.indexOf(word2);
    System.out.println("This is indexOf(): " + index);
    
    // QUESTION 5
    System.out.println("\n--------------Question 5----------------\n");
    System.out.println("Answer 5: I tried public int indexOf(int ch)");
    char o = 'o';
    // will return the index of the first 'o' found withing the string.
    index = word3.indexOf(o);
    System.out.println("This is indexOf() " + index + "\n");
    
    System.out.println("Answer 5: I tried public int indexOf(int ch, int fromIndex)");
    // will return the index of the first 'o' found withing the string starting from the index provided, in this case, 6.
    index = word3.indexOf(o, 6);
    System.out.println("This is indexOf() " + index + "\n");
    
    System.out.println("Answer 5: I tried public int indexOf(String str, int fromIndex)");
    // will return the index of the first string match, it will search forward starting from the specified index.
    index = word3.indexOf(word2, 3);
    System.out.println("This is indexOf() " + index);
    
    // QUESTION 6
    System.out.println("\n--------------Question 6----------------\n");
    System.out.println("Answer 6: I tried public String toUpperCase()");
    // will convert the entire string into upper case.
    System.out.println("This is toUpperCase(): " + word3.toUpperCase());
    
    // QUESTION 7
    System.out.println("\n--------------Question 7----------------\n");
    System.out.println("Answer 7: I tried public String trim()");
    // will simply take out all extra spaces at the beggining and ending for the string.
    String x = "            X          x      ";
    System.out.println("This is trim(): " + x.trim());
    
    // QUESTION 8
    System.out.println("\n--------------Question 8----------------\n");
    System.out.println("Answer 8: I tried public int length()");
    // in this case, returns how many caracters are in the string.
    int stringLength = word2.length();
    System.out.println("This is lenght(): " + stringLength);
    
    // QUESTION 9
    System.out.println("\n--------------Question 9----------------\n");
    System.out.println("Answer 9: I tried public String concat()");
    // will add two strings/object back to back
    System.out.println("This is concat(): " + word1.concat(word2) + "\n");
    System.out.println("Answer 9: I tried +");
    // it will perform the same as concat(), adds two strings/object back to back
    System.out.println("This is '+': " + word1 + word2);

  } // end of main()  

} // end of class HelloStrings

