#include <iostream>

using namespace std;

void honai(int n, char from, char to, char aux){// n = number of disc, from / to / aux are pegs(rod) type chars 'A','B','C', aux = spare rod 
    if(n == 1){
        cout << "Move disc 1 from " << from << " to " << to << endl;
        return;
    }

    honai(n - 1, from, aux, to);

    cout << "Move disc " << n << " from " << from << " to " << to << endl;

    honai(n - 1, aux, to, from);
}

int main(){
    honai(2, 'A', 'B', 'C');

    return 0;
}