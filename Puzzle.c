#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printFoundLocation(int rowDir, int colDir) {
    if(rowDir == 1&&colDir==0){
        printf("south direction.");
    }else if(rowDir == 1 && colDir == -1){
        printf("southwest direction.");
    }else if(rowDir == 0&&colDir == -1){
        printf("west direction.");
    }else if(rowDir == -1&&colDir==-1){
        printf("northwest direction.");
    }else if(rowDir == -1 && colDir ==0){
        printf("north direction.");
    }else if (rowDir == -1 && colDir == 1){
        printf("northeast direction.");
    }else if (rowDir == 0 &&colDir == 1){
        printf("east direction.");
    }else if(rowDir == 1&& colDir == 1){
        printf("southeast direction.");
    }
}

bool search1D(char word[], int wordSize, const int Size, char grid[Size][Size], int row, int col, int rowDir, int colDir) {
    int i = 1;
    bool findWord;
    int rowIndex = row + rowDir;
    int colIndex = col + colDir;
    int length = 1;
    bool findFullWord;
    do{
        if (grid[rowIndex][colIndex]==word[i]&&rowIndex>=0&&rowIndex<Size&&colIndex>=0&&colIndex<Size&&i<wordSize){
            length++;
            i++;
            rowIndex = row + rowDir*i;
            colIndex = col + colDir*i;
            findWord = true;   
        } else{
            findWord = false;
        }
    }while(findWord);

    if (length == wordSize){
        findFullWord = true;
    } else{
        findFullWord = false;
    }
    return findFullWord;
}

void search2D(char word[], int wordSize, const int Size, char grid[Size][Size]) {
    int row;
    int col;
    int finalRowDir;
    int finalColDir;
    int finalRow, finalCol;
    int xDir[]={1,1,0,-1,-1,-1,0,1};
    int yDir[]={0,-1,-1,-1,0,1,1,1};
    bool firstFound = false;
    for (row = 0; row < Size;row++){
        for (col=0; col < Size; col++){
            if (grid[row][col]==word[0]&& !firstFound){
                for (int i=0;i<8&&!firstFound;i++){
                    if(search1D(word,wordSize,Size,grid,row,col,xDir[i],yDir[i])){
                        finalRow = row;
                        finalCol = col;
                        finalRowDir = xDir[i];
                        finalColDir = yDir[i];
                        firstFound = true;
                    }else{
                        firstFound = false;
                    }
                }
            }
        }
    }
    if (!firstFound){
        printf("Word not found.");
    }else{
        printf("Word found at row %d and column %d in the ",finalRow, finalCol);
        printFoundLocation(finalRowDir,finalColDir);
    }

}
