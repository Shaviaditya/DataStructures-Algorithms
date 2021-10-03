import java.util.*;


public class right_view {
	static class Node{
		int data;
		Node right;
		Node left;
		Node(int data)
		{
			this.data=data;
		}
	}
	static Node create_tree()
	{
		Scanner in =new Scanner(System.in);
		Node root=null;
		System.out.println("Enter data:");
		int data=in.nextInt();
		if (data==-1)
			return null;
		root=new Node(data);
		System.out.println("Enter left of "+data);
		root.left=create_tree();
		System.out.println("Enter right of "+data);
		root.right=create_tree();
		return root;
	}
	static void right_view(Node root)
	{
		Queue<Node> q=new LinkedList<>();
		q.add(root);
		while(!q.isEmpty())
		{
			int size=q.size();
			for (int i=0;i<size;i++)
			{
				Node curr=q.poll();
				if (i==size-1)
					System.out.println(curr.data);
				if (curr.left!=null)
					q.add(curr.left);
				if (curr.right!=null)
					q.add(curr.right);
			}
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Node root=create_tree();
		right_view(root);
	}

}
