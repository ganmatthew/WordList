import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * class container for tokenizing input strings
 */
public class Tokenizer
{
    private static BufferedReader b;

    private static Pattern r = Pattern.compile("[A-Za-z]+"); // regex pattern
    private static Matcher m;// = r.matcher(s);

    private static String token; // token result of tokenizer
    private static String input = ""; // empty input string to tokenize
    private static BinarySearchTree tree; // binary search tree to output tokens to

    /**
     * creates a tokenizer class
     * @param br BufferedReader object
     * @param t holds the result string
     * @param i holds the input string to tokenize
     * @param bst holds the binary search tree to output to
     */
    public Tokenizer (BufferedReader br, String t, String i, BinarySearchTree bst)
    {   
        b = br;
        token = t;
        input = i;
        tree = bst;
    }

    /**
     * carries out the tokenization process
     */
    public void Tokenize () {
        try {
            while ((input = b.readLine()) != null)
            {
                m = r.matcher(input);
                while (m.find())
                {
                    token = m.group();
                    if (token.length() >= 3) // only inserts tokens greater than or equal to three characters
                    {
                        tree.Insert(token.toLowerCase());
                        //in.add(token.toLowerCase());
                        //System.out.println(token.toLowerCase());
                    }
                    
                }
            }
        }
        catch (IOException e) { // for debugging
            //System.out.println ("Source file became null during tokenizing sequence");
        }
    }
}
