#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:

    void dfsFill(vector<vector<int>> &image,int currentColour,int colour,int currentRow, int currentColumn , int parentRow , int parentColumn){
        int m=image.size();
        int n=image[0].size();
        if(currentRow+1 < n && parentRow!=currentRow+1 && image[currentRow+1][currentColumn]==currentColour) {
            image[currentRow][currentColumn]=colour;
            dfsFill(image,currentColour,colour,currentRow+1,currentColumn,currentRow,currentColumn);
        }
        if(currentRow-1 > 0 && parentRow!=currentRow-1 && image[currentRow-1][currentColumn]==currentColour) {
            image[currentRow][currentColumn]=colour;
            dfsFill(image,currentColour,colour,currentRow-1,currentColumn,currentRow,currentColumn);
        }
        if(currentColumn+1<m && parentColumn!=currentColumn+1 && image[currentRow][currentColumn+1]==currentColour){
            image[currentRow][currentColumn]=colour;
            dfsFill(image,currentColour,colour,currentRow,currentColumn+1,currentRow,currentColumn);
        }
        if(currentColumn-1>0 && parentColumn!=currentColumn-1 && image[currentRow][currentColumn-1]==currentColour){
            image[currentRow][currentColumn]=colour;
            dfsFill(image,currentColour,colour,currentRow,currentColumn-1,currentRow,currentColumn);
        }

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int startingRow, int startingColumn, int colour) {
        int m=image.size();
        int n=image[0].size();
        int startingPixelColour=image[startingRow][startingColumn];
        if(startingPixelColour==colour) return image;
        dfsFill(image,startingPixelColour,colour,startingRow,startingColumn,startingRow,startingColumn);

        return image;
    }
};



int main(){
    Solution s;
    

    vector<vector<int>> image={{1,1,1},{1,1,0},{1,0,1}};
    s.floodFill(image,1,1,2);
    return 0;
}