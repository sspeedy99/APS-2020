class LinkedList{
    static Node head;

    static class Node {
        int data;
        Node next;
        Node(int data){ //constructor;
            this.data = data;
            this.next = null;
        }
    }

    public void insertStart(int data){
        Node new_node = new Node(data);
        if(head == null){
            head = new_node;
        }
        else {
            new_node.next = head;
            head = new_node;
        }
    }

    public void insertEnd(int data){
        Node new_node = new Node(data);
        Node prev = null;
        Node temp = head;
        while(temp!=null){
            prev = temp;
            temp = temp.next;
        }
        prev.next = new_node;
        new_node.next = null;

    }

    public void insertBefore(int data, int key){
        Node new_node = new Node(data);
        Node temp = head;

        while(temp!=null && temp.data != key){
            temp = temp.next;
        }
        new_node.next = temp.next;
        temp.next = new_node;
    }

    public void insertAfter(int data, int key){
        Node new_node = new Node(data);
        Node temp = head;

        while(temp!=null && temp.data == key){
            temp = temp.next;
        }
        new_node.next = temp.next;
        temp.next = new_node;
    }

    public void deleteKey(int key){
        Node temp = head;
        Node prev = null;
        while(temp!=null && temp.data !=key){
            prev = temp;
            temp = temp.next;
        }
        prev.next = temp.next;
    }

    public void reverse(){
        Node curr = head;
        Node next = null;
        Node prev = null;
        while(curr!=null){
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    public Node SortedMerge(Node L, Node R){
        Node result = null;
        if (L == null){
            return R;
        }
        if( R == null){
            return L;
        }

        if(L.data <= R.data){
            result = L;
            result.next = SortedMerge(L.next, R);
        }
        else {
            result = R;
            result.next = SortedMerge(R.next, L);
        }

        return result;
    }

    

    public void print(){
        Node temp = head;
        while(temp!=null){
            System.out.print(temp.data + " ");
            temp = temp.next;
        }
    }

    public static void main(String [] args){
        LinkedList ll = new LinkedList();
        ll.insertStart(55);;
        ll.insertStart(39);
        ll.insertStart(78);
        ll.insertEnd(85);
        ll.insertBefore(98, 39);
        ll.insertAfter(53, 98);
        ll.deleteKey(39);
        System.out.println("Original List");
        ll.print();
        System.out.println();
        System.out.println("After Reversing the List");
        ll.reverse();
        ll.print();

    }
}