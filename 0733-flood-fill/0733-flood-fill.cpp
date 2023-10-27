class Solution {
public:
    void DFS(vector<vector<int>>& image, int sr, int sc, int color,int currCol){

        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc] == color || image[sr][sc] != currCol) return;

        image[sr][sc] = color;
        DFS(image,sr-1,sc,color,currCol);  //left
        DFS(image,sr+1,sc,color,currCol);  //right
        DFS(image,sr,sc-1,color,currCol);  //above
        DFS(image,sr,sc+1,color,currCol);  //down
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int currCol = image[sr][sc];

        DFS(image,sr,sc,color,currCol);

        return image;
    }
};