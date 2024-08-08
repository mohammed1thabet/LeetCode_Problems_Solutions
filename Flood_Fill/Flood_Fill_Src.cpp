class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        /*if the image is empty return it as it is*/
        if(image.size() == 0)
            return image;

        /*if the starting pixel has the requested color then no change is needed*/
        if(image[sr][sc] == color)
            return image;
        
        /*traverse the image recursively to change all pixels with the starting pixel color*/
        floodFillDfs(image, sr, sc, image[sr][sc], color);

        return image;
    }
private:
    void floodFillDfs(vector<vector<int>>& image, int sr, int sc, int curColor, int newColor)
    {
        /*base state 1: stop traversing at the image boundaries */
        if(sr >= image.size() || sc >= image[0].size())
            return;

        /*base state 2: stop traversing if the current pixel has a color different than the starting pixel */
        if(image[sr][sc] != curColor)
            return;
        /*update the pixel with the requested color */
        else
            image[sr][sc] = newColor;
        
        /*traverse the 4-directionally connected to the current pixel*/
        floodFillDfs(image, sr+1, sc, curColor, newColor);
        floodFillDfs(image, sr-1, sc, curColor, newColor);
        floodFillDfs(image, sr, sc+1, curColor, newColor);
        floodFillDfs(image, sr, sc-1, curColor, newColor);
    }
};