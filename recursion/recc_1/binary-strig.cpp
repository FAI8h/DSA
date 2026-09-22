#include <iostream>
#include <string>

using namespace  std;

string binaryString(int n, string last, string ans){
    if(n == 0) {
        cout << ans << "\n";
        return "";
    };

    if(last != "1"){
        binaryString(n - 1, "0", ans + "0");
        binaryString(n - 1, "1", ans + "1");
    }else{
        binaryString(n - 1, "0", ans + "0");
    }

    return ans;
}

int main () {
    binaryString(3, "0", "");

    return 0;
}