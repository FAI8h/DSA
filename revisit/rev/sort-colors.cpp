#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& colors){
    int n = colors.size();
    int st{0},  mid{0}, end{n - 1};
    while (mid <= end){
        if(colors[mid] == 0){
            swap(colors[mid], colors[st]);
            st++;
            mid++;
        }
        else if (colors[mid] == 1)
        {
            mid++;
        }else{
            swap(colors[mid], colors[end]);
            mid++;
            end--;
        }
    }
}

int main (){

    vector<int> colors = {2,0,2,1,1,0};
    sortColors(colors);
    for (int color : colors)
    {
        cout << color << " ";
    }
    cout << '\n';
    return 0;
}