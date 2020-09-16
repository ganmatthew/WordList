import java.io.*;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class MainClass
{
    private static Scanner kb = new Scanner (System.in);
    public static void main(String[] args) 
    {
        FileReader f; //= new FileReader("input.txt");
        BufferedReader b; // b = new BufferedReader(f);

        String srcFileName = "";
        String input = "";
        String token;

        Pattern r = Pattern.compile("[A-Za-z]+");
        Matcher m;// = r.matcher(s);

        BinarySearchTree tree = new BinarySearchTree();

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
