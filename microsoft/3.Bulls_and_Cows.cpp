#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0, cows =0;

        int numbers[10] = {0};
        for( int i=0; i<secret.length(); i++ ) {
            // converting string to int
            int s = secret.at(i) - '0';
            int g = guess.at(i) - '0';

            if( s == g ) 
                bulls++;
            else {
                if( numbers[s]++ < 0 ) cows++;
                if( numbers[g]-- > 0 ) cows++;
            }
        }

        return to_string( bulls ) + "A" + to_string( cows ) + "B";
    }
};

int main() {
    Solution s;
    cout << s.getHint("1123", "0111" );

    return 0;
}