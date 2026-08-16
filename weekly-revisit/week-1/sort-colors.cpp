#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

using namespace  std;

void sortColor(vector<int> &color){
    int n = color.size();

    int low{0}, mid{0}, high{n - 1};

    while(mid <= high){

        if(color[mid] == 0){
            swap(color[mid],color[low]);
            low++;
            mid++;
        }else if (color[mid] == 1){
            mid++;
        }else{
            swap(color[mid], color[high]);
            high--;
        }
    }
}

int main () {
    vector<int> colors = {1, 2, 0, 1, 0, 2};
    sortColor(colors);
    for(int color : colors){
        cout << color << " ";
    }
    cout << endl;
    return 0;
}