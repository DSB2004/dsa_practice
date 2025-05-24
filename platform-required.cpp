int calculateMinPatforms(int at[], int dt[], int n) {
  vector<pair<int,char>> trains;
  for(int i=0;i<n;i++){
    int t=at[i];
    trains.push_back({t,'A'});
  }
    for(int i=0;i<n;i++){
        int t=dt[i];
    trains.push_back({t,'D'});
  }

  sort(trains.begin(),trains.end());

  int count=0;
  int _max=0;

  for(auto train:trains){
    if(train.second=='A'){
        count++;
    }
    else{
        count--;
    }
    _max=max(_max,count);
  }
  return _max;
}