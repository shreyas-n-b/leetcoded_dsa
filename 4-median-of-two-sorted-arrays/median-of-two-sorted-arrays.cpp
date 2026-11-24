class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total=nums1.size()+nums2.size();
        if(total%2 == 1){
            int i=0;
            int j=0;
            while(i<nums1.size() && j<nums2.size()){
                if(i+j == total/2){
                    return ((nums1[i]<nums2[j]) ? nums1[i] : nums2[j]);
                }
                if(nums1[i]<nums2[j]){
                    i++;
                }
                else{
                    j++;
                }
            }
            while(i<nums1.size()){
                if(i+j == total/2)return nums1[i];
                i++;
            }
            while(j<nums2.size()){
                if(i+j == total/2)return nums2[j];
                j++;
            }
            return 0.0;            
        }
        else{
            int i=0;
            int j=0;
            int prev=0;
            while(i<nums1.size() && j<nums2.size()){
                if(i+j == total/2){
                    int small=(nums1[i]<nums2[j]) ? nums1[i] : nums2[j];
                    double ans=((double)small + prev)/2;
                    return ans;
                }
                if(nums1[i]<nums2[j]){
                    prev=nums1[i];
                    i++;
                }
                else{
                    prev=nums2[j];
                    j++;
                }
            }
            while(i<nums1.size()){
                if(i+j == total/2)return ((double)prev + nums1[i])/2;
                prev=nums1[i];
                i++;
            }
            while(j<nums2.size()){
                if(i+j == total/2)return ((double)prev + nums2[j])/2;
                prev=nums2[j];
                j++;
            }
            return 0.0; 
        }
        
    }
};