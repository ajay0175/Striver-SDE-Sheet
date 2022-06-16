 Node* copyRandomList(Node* head) 
 {
        Node *temp = head; 
        Node *front = head;
        
        //making a copy of each node
        while(temp != NULL){
            front = temp->next;
            Node *copy = new Node(temp->val);
            temp ->next = copy;
            copy->next = front;
            
            temp = front;
        }
        
        //Assigning a random pointers
        temp = head;
        while(temp !=NULL){
            if(temp->random !=NULL)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        
        //restore and extract lists
        temp = head;
        Node *newhead = new Node(0);
        Node *copy = newhead;
        while(temp!=NULL){
            front = temp->next->next;
            copy ->next = temp->next;
            temp ->next = front;
            copy = copy->next;
            temp = front;
        }
        
        return newhead->next;
    }
};

/*
    TC => O(N)
    SC => O(1)
*/

