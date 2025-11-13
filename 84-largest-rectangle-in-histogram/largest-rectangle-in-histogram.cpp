class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>left(n);
        vector<int>right(n);
        stack<int> st;
        for(int i=0;i<n;i++){    //next smallest right
            while(!st.empty() && heights[st.top()]>heights[i]){
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){  //if no smallest exist in right and stack is not empty
            right[st.top()] = n;    
            st.pop();
        }
        for(int i=n-1;i>=0;i--){   //next smallest left
            while(!st.empty() && heights[st.top()]>heights[i]){
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){   //if no smallest exist in left and stack is not empty
            left[st.top()] = -1;
            st.pop();
        }

        int area = 0;
        for(int i=0;i<n;i++){
            area = max(area, heights[i]*(right[i]-left[i]-1));
        }
        return area;
    }
};