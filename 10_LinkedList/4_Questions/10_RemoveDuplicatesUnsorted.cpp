ListNode* reverse(ListNode* &head)
{
    ListNode* prev =NULL;
    ListNode* curr = head;
    ListNode* forward = curr->next;

    while(curr!=NULL)
    {
        forward = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
    }

    return prev;
}

void insertAtTail(ListNode* &head,ListNode* &tail,int data)
{
    if(head==NULL)
    {
        ListNode* newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }

    ListNode* newnode = new node(data);
    tail->next = newnode;
    tail = newnode;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
    l1 = reverse(l1);
    l2 = reverse(l2);

    ListNode* temp1 = l1;
    ListNode* temp2 = l2;
    ListNode* head = NULL;
    ListNode* tail =NULL;
    int carry =0;
    while(temp1!=NULL && temp2!=NULL)
    {   
            int sum = temp1->val + temp2->val + carry;
            int digit = sum%10;
            carry =sum/10;
            insertAtTail(head,tail,digit); 
            temp1 = temp1->next;
            temp2 = temp2->next;
    }
    while(temp1!=NULL)
    {
            int sum = temp1->val + carry;
            int digit = sum%10;
            carry =sum/10;       
            insertAtTail(head,tail,digit);
            temp1 = temp1->next;
    }
    while(temp2!=NULL)
    {
         int sum = temp2->val + carry;
         int digit = sum%10;
         carry =sum/10;       
         insertAtTail(head,tail,digit);
         temp2 = temp2->next;
    }
    if(carry!=0)
    {
        insertAtTail(head,tail,carry);
    }

    head = reverse(head);

    return head;
}