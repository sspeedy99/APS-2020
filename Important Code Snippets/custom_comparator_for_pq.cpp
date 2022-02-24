// The is an example of custom comparator in cpp implemented as lambda function

bool cmp = [&](pair<int,int>p1, pair<int,int>p2){
    return p1.second < p2.second;
};

// PQ implementation for min heap
priority_queue<pair<int,int>, vector< pair<int, int> >, decltype(cmp) > = pq(cmp);
