class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans = 0;
        vector<double> v;
        for(int i = 0 ; i < nums1.size() ; i++) {
            v.push_back((double)nums1[i]);
        }       
        for(int i = 0 ; i < nums2.size() ; i++) {
            v.push_back((double)nums2[i]);
        }
        sort(v.begin(), v.end());
        if(v.size() & 1)
        ans = v[v.size() / 2];
        else 
        ans = (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
        return ans;
    }
};