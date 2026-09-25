/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
ListNode* reverse(ListNode* head) {
    ListNode* curr = head;
    ListNode* nextN=NULL;
    ListNode* prevN=NULL;
    while(curr!=NULL) {
         nextN = curr->next;
         curr->next=prevN;
         prevN= curr;
         curr=nextN;
    }
    return prevN;
}
ListNode* findKNode(ListNode* head, int k) {
    k--;
    while(head!=NULL && k>0){
         head = head->next;
         k--;
    }
    return head;
}
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* nextNode=NULL;
        ListNode* prevNode=NULL;
        ListNode* temp=head;
        while(temp!=NULL) {
            ListNode* knode = findKNode(temp,k);
            if(knode==NULL) {
            if(prevNode!=NULL) {
                prevNode->next=temp;
                break;
            }
            }
            nextNode = knode->next;
            knode->next=NULL;
            reverse(temp);
            if(temp==head){
                head = knode;
            } else{
                prevNode->next=knode;
            }
            prevNode = temp;
            temp= nextNode;
        }
        return head;
    }
};