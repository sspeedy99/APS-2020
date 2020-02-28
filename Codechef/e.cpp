#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

 
const int INF=1e9+5;

vector<int> times = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };


 
int32_t main()
{
	IOS;
    int t,m1,y1,m2,y2,flag1,flag2;
    cin>>t;
    while(t--) {
        cin>>m1>>y1>>m2>>y2;
        if (m1 > 2)
            y1 += 1;
        if (m2 < 2)
            y2 -= 1;

        int cnt = 0;

        cnt += ((y2-y1)/(400) * 101) ;
        y1 = y2 - (y2-y1)%400;

        for(int i =y1; i< y2+1; i++){
            int y = i;
            y -= 1;
            int day = (( y + int(y / 4) - int(y / 100) + int(y/ 400) + times[1] + 1) % 7);
            if (day == 0 and not ((i%4==0 and i%100 != 0) or i%400==0) or day == 6)
                cnt++;
        }
        cout<<cnt<<endl;

    }

	return 0;
}