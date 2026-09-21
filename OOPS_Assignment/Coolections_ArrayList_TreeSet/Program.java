import java.util.ArrayList;
import java.util.Collections;
import java.util.TreeSet;


public class Program {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		ArrayList<String>colours  = new ArrayList<>();
				colours.add("Red");
				colours.add("Yellow");
				colours.add("Blue");
				colours.add("Black");
				
		System.out.println(colours);
		
		// insert an element
		colours.add(0,"Green");
		System.out.println(colours);
		
		//get the element
		String element = colours.get(2);
		System.out.println(element);
		
		//update a element
		colours.set(2, "Brown");
		System.out.println(colours);
		
		//remove a element
		colours.remove(3);
		System.out.println(colours);
		
		//Element search in array
		if(colours.contains("Brown"))
			System.out.println("Present");
		else
			System.out.println("Not present");
		
		//sort an array list
		Collections.sort(colours);
		System.out.println(colours);
		
		//copy the array list
		ArrayList<String> newList = new ArrayList<>();
		
		newList.add("");
		newList.add("");
		newList.add("");
		newList.add("");
		
		Collections.copy(newList, colours);
		System.out.println(newList);
		
		//shuffle the list
		Collections.shuffle(colours);
		
		//reverse the arraylist
		Collections.reverse(colours);
		
		System.out.println("**********************************");
		
		//Create a tree set
		
		TreeSet<String> tree = new TreeSet<>();
		tree.add("red");
		tree.add("Black");
		tree.add("White");
		
		System.out.println(tree);
		
		//create a new and add all of tree
		TreeSet<String> newTree = new TreeSet<>();
		newTree.add("yellow");
		newTree.add("Blue");
		newTree.addAll(tree);
		
		System.out.println(newTree);
		
		//reverse of the tree
		System.out.println(newTree.descendingSet());
		
		//get first and last
		System.out.println(tree.first());
		System.out.println(tree.last());
		
		//Ceiling in tree
		TreeSet<Integer> noTree = new TreeSet<>();
		noTree.add(10);
		noTree.add(20);
		noTree.add(30);
		noTree.add(40);
		System.out.println(noTree.ceiling(25));


	}

}
