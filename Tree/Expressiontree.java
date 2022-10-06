import java.util.*;

class Node 
{
    char data;
    Node left;
    Node right;

    Node(char value) 
    {
        data = value;
    }
}

class Built 
{
    Node root;

    public static boolean isoperator(char op) 
    {
        if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^') 
        {
            return true;
        }
        return false;
    }

    Node builttree(String s) 
    {  // for prefix only start from last index i.e in reverse order
        if(s.length()==0)
        {
            return null;
        }
        Stack<Node> st = new Stack<Node>();
        for (int i = 0; i < s.length(); i++) 
        {
            if (isoperator(s.charAt(i))) 
            {
                Node newnode = new Node(s.charAt(i));
                Node op1 = st.pop();
                Node op2 = st.pop();
                newnode.left = op2;  // for prefix op2 on right
                newnode.right = op1; // for prefix op1 on left
                st.push(newnode);
            } 
            else 
            {
                Node newnode = new Node(s.charAt(i));
                newnode.left = null;
                newnode.right = null;
                st.push(newnode);
            }
        }
        return st.pop();
    }

    void inorder(Node root)
    {
        if(root ==null)
        {
            return;
        }
        inorder(root.left);
        System.out.print(root.data + " ");
        inorder(root.right);
       
    }
    
    void preorder(Node root)
    {
        if(root==null)
        {
            return;
       
        }
        System.out.print(root.data + " ");
        preorder(root.left);
        preorder(root.right);
       
    }
   
    void postorder(Node root)
    {
        if(root ==null)
        {
           return;
        }
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");
        
    }
    
    void inorderiterative(Node root)
    {
        if(root == null)
        {
            return;
        }
        
        Stack<Node> st = new Stack<Node>();
        
        while(true)
        {
            if(root!=null)
            {
                st.push(root);
                root = root.left;
            }
            else
            {
                if(st.size()==0)
                {
                    break;
                }
                else
                {
                root = st.peek();
                st.pop();
                System.out.print(root.data + " ");
                root =root.right;
                }
            }
        }
        
    }
    
    void preorderiterative(Node root)
    {
        if(root == null)
        {
            return;
        }
        
        Stack<Node> st = new Stack<Node>();
        
        st.push(root);
        
        while(st.size()!=0)
        {
                root = st.peek();
                st.pop();
                if(root.right!=null)
                {
                st.push(root.right);
                }
                if(root.left!=null)
                {
                st.push(root.left);
                }
                
                System.out.print(root.data + " ");
        }
        
    }
    
    void postorderiterative(Node root)
    {
        if(root == null)
        {
            return;
        }
        
        Stack<Node> post = new Stack<Node>();
        ArrayList<Character> lt = new ArrayList<Character>();
        
        post.push(root);
        while(post.size()!=0)
        {
                root = post.peek();
                post.pop();
                
                if(root.left!=null)
                {
                  post.push(root.left);
                }
                
                if(root.right!=null)
                {
                    post.push(root.right);
                }
                
                lt.add(root.data);
        }
        
        for(int i=lt.size()-1 ;i>=0;i--)   // in reverse order
        {
            System.out.print(lt.get(i) + " ");
        }
        System.out.println();
    }
    
    int evaluation(Node root)
    {   // same for both prefix and postfix expression 
        if(root!=null)
        {
            if(!isoperator(root.data))
            {
                return root.data-'0'; // char to int 
            }
            else 
            {
                int leftvalue=evaluation(root.left);
                int rightvalue=evaluation(root.right);
                char operator = root.data;

                switch(operator)
                {
                    case '-':
                    {
                        return leftvalue - rightvalue;
                        
                    }
                    case '+':
                    {
                        return leftvalue + rightvalue;
                        
                    }
                    case '*':
                    {
                        return leftvalue * rightvalue;
                        
                    }
                    case '/':
                    {
                        return leftvalue/rightvalue;
                        
                    }
                    
                }
                

            }
        }
        return 0;
    }

}

public class Expressiontree 
{

    public static void main(String[] args) 
    {  
        Scanner in = new Scanner(System.in);

        Built tree = new Built();
        System.out.println("enter postfix expression");
        String expression = in.nextLine();
        tree.root = tree.builttree(expression);
        
        System.out.println("inorder traversal ");
	    tree.inorder(tree.root);
	    System.out.println("\npreorder traversal ");
	    tree.preorder(tree.root);
	    System.out.println("\npostorder traversal ");
	    tree.postorder(tree.root);
	    System.out.println("\nvalue of expression evaluation is");
        int ans= tree.evaluation(tree.root);
        System.out.println(ans);
    }
}