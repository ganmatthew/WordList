import java.io.*;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class MainClass
{
    private static Scanner kb = new Scanner (System.in);

    private static FileReader f; //= new FileReader("input.txt");
    private static BufferedReader b; // b = new BufferedReader(f);

    private static String srcFileName = "";
    private static String input = "";
    private static String token;

    private static Pattern r = Pattern.compile("[A-Za-z]+");
    private static Matcher m;// = r.matcher(s);

    private static BinarySearchTree tree = new BinarySearchTree();

    public static void main(String[] args) 
    {

        try
        {
            System.out.print("Input filename: ");
            srcFileName = kb.next();

            f = new FileReader(srcFileName);
            b = new BufferedReader(f);

            while ((input = b.readLine()) != null)
            {
                m = r.matcher(input);
                while (m.find())
                {
                    token = m.group();
                    if (token.length() >= 3)
                    {
                        tree.Insert(token.toLowerCase());
                        //in.add(token.toLowerCase());
                        //System.out.println(token.toLowerCase());
                    }
                    
                }
            }
            
            tree.Inorder();
            f.close();
            b.close();

            BinarySearchTree.CleanTree(tree.root);
        }
        catch (FileNotFoundException e)
        {
            System.out.println(srcFileName + " not found.");
        }
        catch (IOException e)
        {
            System.out.println("Error in inputting / Closing.");
        }
        
    }
}
