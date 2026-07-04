1class Solution {
2public:
3    void setZeroes(vector<vector<int>>& matrix) {
4        int m = matrix.size();
5        int n = matrix[0].size();
6
7        bool firstRow = false;
8        bool firstCol = false;
9
10        for(int j = 0; j < n; j++) {
11            if(matrix[0][j] == 0) firstRow = true;
12        }
13
14        for(int i = 0; i < m; i++) {
15            if(matrix[i][0] == 0) firstCol = true;
16        }
17
18        for(int i = 1; i < m; i++) {
19            for(int j = 1; j < n; j++) {
20                if(matrix[i][j] == 0) {
21                    matrix[i][0] = 0;
22                    matrix[0][j] = 0;
23                }
24            }
25        }
26
27        for(int i = 1; i < m; i++) {
28            for(int j = 1; j < n; j++) {
29                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
30                    matrix[i][j] = 0;
31                }
32            }
33        }
34
35        if(firstRow) {
36            for(int j = 0; j < n; j++) {
37                matrix[0][j] = 0;
38            }
39        }
40
41        if(firstCol) {
42            for(int i = 0; i < m; i++) {
43                matrix[i][0] = 0;
44            }
45        }
46    }
47};