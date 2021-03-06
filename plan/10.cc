/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==nullptr)
            return pHead;
        if(pHead->next==nullptr)
            return pHead;
        
        ListNode *cur;
        
        if(pHead->val!=pHead->next->val){
            pHead->next=deleteDuplication(pHead->next);
            return pHead;
        }
        else{
            int tmp=pHead->val;
            cur=pHead->next;
            while(cur!=nullptr&&cur->val==tmp){
                ListNode *d=cur;
                cur=cur->next;
                delete d;
            }
            delete pHead;
            return deleteDuplication(cur);
        }
    }
};
