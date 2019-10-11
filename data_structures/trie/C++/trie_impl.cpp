#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;
const int alp_s = 26;
struct Trie{
	struct Trie *children[alp_s];
	bool eow;
};
struct Trie *getnode(){
	struct Trie *pnode = new Trie;
	for(int i=0;i<26;i++){
		pnode->children[i]=NULL;
	}
	pnode->eow=false;
	return pnode;
}
void insert(struct Trie *root, string key){
	struct Trie *ppoin = root;
	int i,index;
	for(i=0;i<key.length();i++){
		index = key[i] - 'a';
		if(!ppoin->children[index]){
			ppoin->children[index] = getnode();
		}
		ppoin = ppoin->children[index];
	}
	
	ppoin->eow = true;
}
bool search(struct Trie *root, string key){
	struct Trie *ppoin = root;
	for(int i=0;i<key.length();i++){
		int index = key[i] - 'a';
		if(!ppoin->children[index])return false;
		ppoin = ppoin->children[index];
	}
	return(ppoin!=NULL && ppoin->eow);
}
int main(){
	int n;
	cin>>n;
	string keys[n];
	for(int i=0;i<n;i++){
		cin>>keys[i];
	}
	struct Trie *root = getnode();
	for(int i=0;i<n;i++){
		insert(root,keys[i]);
	}
	bool res = search(root,"pprt");
	if(res)cout<<"Yes";
	else cout<<"No";
	return 0;
}
