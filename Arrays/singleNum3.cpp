#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace  std;

/*
! 1.
? TC :- O(n), SC :- O(n)
vector<int> singleNum(vector<int>& nums){
    int n = nums.size();
    vector<int> ans;
    unordered_map<int, int> m;

    for(int num : nums){
        m[num]++;
    };
    for (int num : nums){
        if(m[num] == 1){
            ans.push_back(num);
        }
    }
    return ans;
}

! 2.
? TC :- O(n), SC :- O(1)
vector<int> singleNum(vector<int>& nums){
    long long int xorAll = 0;

    for(int num : nums){
        xorAll ^= num;//? we xor all num , we dont know which one is unique yet
    };

    long long int diffBit = xorAll & (-xorAll);//? now we get diifferent bits from where the bits starts to differ we get that bit

    int a = 0, b = 0;
    ;//? a stores if the bit is same --> 1 if same we cancel and get the first unique number
    ;//? b stores if the bit is diff --> 0 if same we cancel and get the second unique number

    for(int num : nums){
        if(num & diffBit){
            a ^= num;
        }else{
            b ^= num;
        }
    };

    return {a, b};//? return the unique number;

;//! exp
a ^ b = 3 ^ 5 = 6 = 110 in binary

What does this 110 MEAN?

  3 = 011
  5 = 101
  --------
  ^ = 110  ← wherever there's a 1, a and b DIFFER at that bit

  Bit 0: 1 vs 1 → same → 0
  Bit 1: 1 vs 0 → DIFFER → 1  ← they differ here!
  Bit 2: 0 vs 1 → DIFFER → 1  ← and here!

  example Array: [1, 2, 1, 3, 2, 5]
  
  Binary:
    1 = 001 → bit 1 = 0 → Group A
    2 = 010 → bit 1 = 1 → Group B
    1 = 001 → bit 1 = 0 → Group A
    3 = 011 → bit 1 = 1 → Group B
    2 = 010 → bit 1 = 1 → Group B
    5 = 101 → bit 1 = 0 → Group A

  Group A: [1, 1, 5]  ← 5 is here!//? now perform the xor and get the unique number
  Group B: [2, 2, 3]  ← 3 is here!//? now perform the xor and get the unique number
}

*/

vector<int> singleNum(vector<int>& nums){
    long long int xorAll = 0;
    
    for(int num : nums){
        xorAll ^= num;
    };

    long long int diffBit = xorAll & (-xorAll);

    int a = 0, b = 0;

    for(int num : nums){
        if(num & diffBit){
            a ^= num;
        }else{
            b ^= num;
        }
    };

    return {a, b};
}

int main () {
    vector<int> nums = {1,2,1,4,2,5};
    vector<int> res = singleNum(nums);
    for (int num : res){
        cout << num << " " << endl;
    }

    return 0;
} 