public class BinarySearchTree
{
    Node root;

    private int Compare (String s1, String s2)
    {
        for (int i = 0; i < s1.length(); i++)
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

    public BinarySearchTree ()
    {
        root = null;
    }

    public void Insert (String s)
    {
        root = InsertRec(root, s);
    }

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


    public void Inorder ()
    {
        InorderRec(root);
    }

    public void InorderRec (Node r)
    {
        if (r == null)
            return;

        InorderRec(r.left);
        System.out.printf("%-15s: %d\n", r.data, r.cnt);
        InorderRec(r.right);
    }

}