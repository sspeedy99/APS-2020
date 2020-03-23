#include <bits/stdc++.h>
using namespace std;

int N, Q;

// Variables, that hold current "state" of computation
long long cnt;


// Array to store answers (because the order we achieve them is messed up)
long long answers[100500];
int BLOCK_SIZE;
int arr[100500];


/* 
We will represent each query as three numbers: L, R, idx, val. Idx is 
the position (in original order) of this query and value will be the value to check.

queries[i].first.first - L
queries[i].first.second - R
queries[i].second.first - idx
queries[i].second.second - val

*/
pair< pair<int, int>, pair<int,int> > queries[100500];


// Essential part of Mo's algorithm: comparator, which we will
// use with std::sort. It is a function, which must return True
// if query x must come earlier than query y, and False otherwise.
inline bool mo_cmp(const pair< pair<int, int>, pair<int,int> > &x,
        const pair< pair<int, int>, pair<int,int> > &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}



// Returns true if x is in range [low..high], else false 
inline bool isValid(size_t low, size_t high, size_t x) 
{ 
    return ((x-low) <= (high-low)); 
}


int32_t main(){
    ios_base::sync_with_stdio(false); // some shit for faster io
    cin.tie(NULL);   // ditto
    cout.tie(NULL); // ditto

    int t;
    cin>>t;
    while(t--){
        cin>>N>>Q;
        BLOCK_SIZE = static_cast<int>(sqrt(N));

        //Read the input array
        for(int i =0 ; i<N ; i++)
            cin>>arr[i];

        //Store the Queries
        for(int i=0; i<Q; i++) {
            cin>>queries[i].first.first >> queries[i].first.second >> queries[i].second.second;
            queries[i].second.first = i;
        }
        
        //Arrange the queries in Mo's order
        sort(queries, queries+Q, mo_cmp);

        // Set up current segment [mo_left, mo_right].
        int mo_left = 0, mo_right = -1;

        //Iterate over all the queries
        for(int i=0; i<Q; i++) {

            int left = queries[i].first.first - 1;
            int right = queries[i].first.second - 1;
            int val = queries[i].second.second;

            while(mo_right < right) {
                if(isValid(min(arr[mo_right],arr[mo_right+1]) ,max(arr[mo_right],arr[mo_right+1]) ,val))
                    cnt++;

                mo_right++;
                
            }
            while(mo_right > right) {
                if(isValid( min(arr[mo_right],arr[mo_right-1]) ,max(arr[mo_right],arr[mo_right-1]) ,val))
                    cnt--;
                mo_right--;
            }

            while(mo_left < left) {
                if(isValid( min(arr[mo_left],arr[mo_left+1]) ,max(arr[mo_left],arr[mo_left+1]) ,val))
                    cnt--;
                mo_left++;
            }
            while(mo_left > left) {
                 if(isValid( min(arr[mo_left],arr[mo_left-1]) ,max(arr[mo_left],arr[mo_left-1]) ,val))
                    cnt++;
                mo_left--;

            }
                    // Store the answer into required position.
        answers[queries[i].second.first] = cnt;

        }

            // We output answers *after* we process all queries.
        for(int i = 0; i < Q; i++)
            cout << answers[i] << "\n";


    }
    return 0;
}