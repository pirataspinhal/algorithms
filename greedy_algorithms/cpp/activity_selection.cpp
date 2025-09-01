#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int>a,pair<int,int>b){
	return a.second<=b.second;
}

void ActivitySelection(vector<pair<int,int>> time,int n){
	sort(time.begin(),time.end(),cmp); //sort according to increasing order of finish time
	int i,j;
	i=0;
	cout<<time[i].start<<" "<<time[i].finish<<endl;
	for(j=1;j<n;j++){
		if(time[j].first >= time[i].second){
			cout<<time[j].start<<" "<<time[j].finish<<endl;
		}
	}

	return;	
}