import java.io.*;
import java.util.Scanner;

/**
 * main driver class
 */
public class MainClass
{
    private static Scanner kb = new Scanner (System.in); // handles console input

    private static FileReader f;
    private static BufferedReader b;
    private static Tokenizer t;

    private static String srcFileName = ""; // empty name of file to read from
    private static String destFileName = "WORDS.txt"; // name of file to write to
    private static String input = "";
    private static String token;

    private static BinarySearchTree tree = new BinarySearchTree(); // creates a binary search tree

    public static void main(String[] args) 
    {

        try
        {
            System.out.print("Input filename: ");
            srcFileName = kb.next();

            f = new FileReader(srcFileName);
            b = new BufferedReader(f);
            t = new Tokenizer(b, token, input, tree);
      
            t.Tokenize(); // parses the input sentences into tokens

            tree.Write(destFileName); // sorts the BST and writes contents to an output file
            f.close(); // closes the FileReader stream
            b.close(); // closes the BufferedReader stream

            BinarySearchTree.Destroy(tree.root); // destroys and clears the BST
        }
        catch (FileNotFoundException e) // goes here if the input file could not be found
        {
            System.out.println(srcFileName + " not found.");
        }
        catch (IOException e) // debugging purposes only
        {
            //System.out.println("Error in input or file closing.");
        }
        
    }
}
