#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:

    void dfsFill(vector<vector<int>> &image,int startingColour,int colour,int currentRow, int currentColumn , int parentRow , int parentColumn){
        int m=image.size();
        int n=image[0].size();
        image[currentRow][currentColumn]=colour;
        if(currentRow+1 < n && parentRow!=currentRow+1 && image[currentRow+1][currentColumn]==startingColour){
            dfsFill(image,startingColour,colour,currentRow+1,currentColumn,currentRow,currentColumn);
        }
        if(currentRow-1 >= 0 && parentRow!=currentRow-1 && image[currentRow-1][currentColumn]==startingColour){

            dfsFill(image,startingColour,colour,currentRow-1,currentColumn,currentRow,currentColumn);
        }
        if(currentColumn+1<m && parentColumn!=currentColumn+1 && image[currentRow][currentColumn+1]==startingColour){
            dfsFill(image,startingColour,colour,currentRow,currentColumn+1,currentRow,currentColumn);
        }
        if(currentColumn-1>=0 && parentColumn!=currentColumn-1 && image[currentRow][currentColumn-1]==startingColour){
            dfsFill(image,startingColour,colour,currentRow,currentColumn-1,currentRow,currentColumn);
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
    vector<vector<int>> ans;
    ans=s.floodFill(image,1,1,2);

    for(auto vectr:image){
        for(auto pixel:vectr){
            cout<<pixel<<" ";
        }
        cout<<'\n';
    }
    return 0;
}