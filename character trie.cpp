#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define F first
#define S second

struct node {
	node *nxt[26];
	bool is_end;
	int cnt;
	node() {
		for (int i = 0; i < 26; i++) this->nxt[i] = NULL;
		is_end = false;
		cnt = 0;
	}
};

node *root;

void insert_in_trie(string name) {
	node *cur = root;
	cur->cnt++;
	for (int i = 0; i < name.size(); i++) {
		if (cur->nxt[name[i] - 'a'] == NULL) {
			cur->nxt[name[i] - 'a'] = new node();
		}
		cur = cur->nxt[name[i] - 'a'];
		cur->cnt++;
	}
	cur->is_end = true;
}

bool search_in_trie(string name) {
	node *cur = root;
	for (int i = 0; i < name.size(); i++) {
		if (cur->nxt[name[i] - 'a'] == NULL) {
			return false;
		}
		cur = cur->nxt[name[i] - 'a'];
	}
	return cur->is_end;
}

int name_with_prefix(string prefix) {
	node *cur = root;
	for (int i = 0; i < prefix.size(); i++) {
		if (cur->nxt[prefix[i] - 'a'] == NULL) {
			return 0;
		}
		cur = cur->nxt[prefix[i] - 'a'];
	}
	return cur->cnt;
}

int lexicographically_smaller(string name) {
	node *cur = root;
	int ans = 0;
	for (int i = 0; i < name.size(); i++) {

		for (int j = 0; j < (name[i] - 'a'); j++) {
			if (cur->nxt[j] != NULL) ans += cur->nxt[j]->cnt;
		}

		if (cur->nxt[name[i] - 'a'] == NULL) {
			return ans;
		}
		cur = cur->nxt[name[i] - 'a'];
	}

	return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// code
	root = new node();
	insert_in_trie("apaar");
	insert_in_trie("ajay");
	insert_in_trie("omkar");
	insert_in_trie("bonnie");

	if (search_in_trie("apaar")) {
		cout << "found";
	}
	else {
		cout << "not found";
	}

}