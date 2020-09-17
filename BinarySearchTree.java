import java.io.*;

/**
 * class container for all BST-related operations
 */
public class BinarySearchTree
{
    Node root;
    private static FileWriter f;
    private static BufferedWriter b;

    /**
     * creates a Binary Search Tree
     */
    public BinarySearchTree ()
    {
        root = null;
    }
    
    /** 
     * compares two given key values
     * @param s1 first key value
     * @param s2 second key value
     * @return 1 if first key is less than second key, -1 if first key is greater than second key.
     */
    private int Compare (String s1, String s2)
    {
        int a;

        if (s1.length() > s2.length())
            a = s2.length();
        else
            a = s1.length();

        for (int i = 0; i < a; i++)
        {
            if ((int)s1.charAt(i) < (int)s2.charAt(i))
            {
                return 1;
            }
            else if ((int)s1.charAt(i) > (int)s2.charAt(i))
            {
                return -1;
            }
        }

        return 0;
    }

   /**
     * calls the recursive InsertRec operation
     */
    public void Insert (String s)
    {
        root = InsertRec(root, s);
    }

    
    /** 
     * adds a new node recursively in the BST
     * @param r
     * @param s
     * @return Node
     */
    private Node InsertRec (Node r, String s)
    {
        if (r == null)
        {
            r = new Node(s);
            return r;
        }

        if (s.contentEquals(r.data))
        {
            r.cnt++;
        }
        else
        {
            if (Compare(s, r.data) > 0)
                r.left = InsertRec(r.left, s);
            else if (Compare(s, r.data) < 0)
                r.right = InsertRec(r.right, s);
        }
        return r;
    }
    
    /**
     * executes inorder traversal of the BST and writes its contents to an output file
     */
    public void Write (String fileName)
    {
        try
        {
            File file = new File(fileName);
            file.createNewFile(); // creates a new File of given fileName

            f = new FileWriter(file);
            b = new BufferedWriter(f);

            Inorder();
            closeIOStream();
        }
        catch (IOException e) // used for debugging
        {
            //System.out.println("Cannot find created file with filename " + fileName);
            //e.printStackTrace();
        }
    }

    /**
     * calls functions to close the FileWriter and BufferedWriter output streams
     */
    public void closeIOStream ()
    {
        try
        {
            b.flush();
            b.close();
            f.flush();
            f.close();
        }
        catch (IOException e) // used for debugging
        {
            //System.out.println("Output stream closing error");
            //e.printStackTrace();
        }
    }

    /**
     * calls the recursive InorderRec operation
     */
    public void Inorder ()
    {
        InorderRec(root);
    }

    
    /** 
     * performs the inorder traversal of the BST recursively
     * @param r refers to the current root node being sorted
     */
    private void InorderRec (Node r)
    {
        if (r == null)
            return;

        try
        {
            InorderRec(r.left);
            //System.out.printf("%-15s: %d\n", r.data, r.cnt);
            b.write(String.format("%-15s: %d\n", r.data, r.cnt));
            InorderRec(r.right);
        }
        catch (NullPointerException e) {} // used to terminate at the end
        catch (IOException e) // used for debugging
        {
            //System.out.println("File writing error");
            //e.printStackTrace();
        }
    }

    
    /** 
     * determines if a specific search key exists in the BST
     * @param r refers to the current node being searched
     * @param s refers to the search key to check for
     * @return Node
     */
    public Node Search(Node r, String s)
    {
        if (r == null || r.data.contentEquals(s))
            return r;
        
        if (Compare(s, r.data) > 0)
            return Search(r.left, s);
        
        return Search(r.right, s);
    }

    
    /** 
     * cleans up the BST before terminating the program after writing to file
     * @param r refers to the current node being cleared
     */
    public static void Destroy(Node r)
    {
        if (r != null)
        {
            Destroy(r.left);
            Destroy(r.right);
            r = null;
        }
    }
}