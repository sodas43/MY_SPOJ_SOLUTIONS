/*
 This is a good problem as it involves some mathematics along with bfs.After reading the
 problem you will think that this problem is not at all related to bfs but it does.
 Let's figure it out how.

 In this they are saying about finding the multiple of 'n',so we can say that our result would be
 divisible by 'n', hence,

 result mod n = 0

 now number which consist of only 0 and 1 can be represented as follows:
 if a number is 11010, ((((1 * 10 + 1) * 10 + 0) * 10 + 1) * 10 + 0)

 so you can easily see one fact that we are moving from one number to two numbers that
 are (number*10 or number*10+1)

 As we know that mod can be distributed over addition hence we can say (number % n) has
 two adjacent vertices (number%n*10)%n and (number%n*10+1)%n and this way we can apply
 bfs and find the answer.

 In this problem instead of label you have to store the sequence of 1's and 0's or
 the number found upto that vertex.
*/

#include <bits/stdc++.h>
using namespace std;

//int res;

string getSmallest(int n) {
    string res;

    queue<pair<string, int>> q; //same no in <string format, int format>

    q.push({"1", 1}); // start from 1

    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();

        auto sStr = tmp.first;
        auto sVal = tmp.second;

        if (sVal % n == 0) {
            res = sStr;
            break;
        }

        sVal = sVal % n;

        //cout <<"["<< (sStr+"0")<<", "<<sVal*10<<"]"<<" "<<"["<<(sStr+"1")<<", "<<sVal*10+1<<"]"<<endl;
        q.push({sStr + "0", sVal * 10});
        q.push({sStr + "1", sVal * 10 + 1});
    }
    return res;
}
int main() {
    // your code goes here
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cout << getSmallest(n) << endl;
    }
    return 0;
}