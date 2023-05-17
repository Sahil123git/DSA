//app1
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return NULL;
        }
        map<Node*, Node*> mp;
        Node* cHead = new Node(-1), *temp = head, *tempHead = cHead;

        while(temp != NULL) {
            mp[temp] = cHead;
            cHead->val = temp->val;
            cHead->next = new Node(-1);
            temp = temp->next;
            if(temp == NULL) {
                cHead->next = NULL;
            }
            else {
                cHead = cHead->next;
            }
        }

        temp = head;
        Node* res = tempHead;

        while(temp != NULL) {
            Node* rndm = temp->random;
            Node* cRndm = mp[rndm];
            tempHead->random = cRndm;

            temp = temp->next;
            tempHead = tempHead->next;
        }

        return res;
    }
};

//app2
//Time:O(n) and Space:O(1)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){//if head is NULL
            return NULL;
        }
        Node* chead = head;
        while(chead != NULL){//addding new copied node next to org node
            Node* nxt=chead->next;
            chead->next = new Node(chead->val);//value of next copied will be same as org node
            chead->next->next = nxt;
            chead = nxt;
        }
         
        chead = head;
        while(chead != NULL){//now connecting random ptr using copied nodes which are inserted after every ord node
            if(chead->random != NULL){//if node random pts to null then there can't be next of NULL  
                chead->next->random = chead->random->next;
            }
            else{
                chead->next->random=NULL;
            }
            chead=chead->next->next;//moving to the next org node
        }
        
        Node* nhead=head->next;//our copied node which we'll return
        chead=head;
        
        while(chead!=NULL && chead->next!=NULL){//now removing cnctn i.e removing in between inserted nodes 
            Node* nxt=chead->next;//saving next of org node
            chead->next=chead->next->next;//using this org node will points to next org node not inserted one
            if(chead->next!=NULL){//if next org node is not null then only it can have next inserted node
                nxt->next=nxt->next->next;//Making inserted node pointes to next inserted node
            }
            chead=chead->next;//now iterating to next org node
        }
        return nhead;
        
    }
};
