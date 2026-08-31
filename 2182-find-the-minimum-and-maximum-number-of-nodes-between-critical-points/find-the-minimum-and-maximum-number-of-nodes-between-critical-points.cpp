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
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(-1);
        if(head == nullptr)return ans;
        ListNode* curr=head->next;
        ListNode* prev=head;
        if(curr == nullptr)return ans;
        ListNode* nextNode=curr->next;
        vector<int> criticalPoints;
        int ind=2;
        while(nextNode != nullptr){
            bool maxima=(curr->val>prev->val && curr->val>nextNode->val);
            bool minima=(curr->val<prev->val && curr->val<nextNode->val);
            if(maxima || minima){
                criticalPoints.push_back(ind);
            }
            prev=curr;
            curr=nextNode;
            nextNode=nextNode->next;
            ind++;
        }
        int m=criticalPoints.size();
        if(m<2)return ans; 
        int maxDist=criticalPoints.back()-criticalPoints.front();
        int minDist=INT_MAX;
        for(int i=0; i<m-1; i++){
            int dist=criticalPoints[i+1]-criticalPoints[i];
            minDist=min(minDist,dist);
        }
        ans[0]=minDist;
        ans[1]=maxDist;
        return ans;       
    }
};