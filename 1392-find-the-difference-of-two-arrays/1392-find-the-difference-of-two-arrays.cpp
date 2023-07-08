class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
       set<int> s1(nums1.begin(),nums1.end());      //to make set of nums1
       set<int> s2(nums2.begin(),nums2.end());      //to make set of nums2

       vector<vector<int>> ans;
       
       vector<int> v1;
       vector<int> v2;

    // to check wheather element of set 1 is present in set2 or not 
       for(auto ele : s1){
           if(s2.count(ele) == 0){   // if not present then push it in first list
               v1.push_back(ele);
           }
        }


  // to check wheather element of set 2 is present in set1 or not 
        for(auto ele : s2){
            if(s1.count(ele) == 0){     // if not present then push it in seconf list
                v2.push_back(ele);
            }
        }

        ans.push_back(v1);
        ans.push_back(v2);
       return ans;


    }
};