#pragma GCC optimize("Ofast")
#include <algorithm>
#include <bitset>
#include <deque>
#include <iostream>
#include <iterator>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void abhisheknaiidu()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

struct TreeNode
	{
		int val;
		TreeNode* left;
		TreeNode* right;
	};

	// BstNode* rootptr = NULL;

TreeNode* GetNewNode(int val) {
	TreeNode* newNode = new TreeNode(); // returns back the address the new node
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode; // address of newNode
}

// TreeNode* root = NULL;

int check(TreeNode* root, int sum, vector <int> &cur) {
	if(root == NULL) return 0;
	cur.push_back(root->val);
	// reverse(cur.begin(), cur.end());
	int s = 0;
	int count =0;
	for(auto it=cur.rbegin(); it != cur.rend(); it++) {
		s+=*it;
		// cout << s << endl;
		if(s == sum) count++;
	}
	// cout << count << " ";
	// check(root->left, sum, cur, count);
	// check(root->right, sum, cur, count);
	count += check(root->left, sum, cur);
	count += check(root->right, sum, cur);
	cur.pop_back();

	// cout << count << endl;
	return count;
}


int main(int argc, char* argv[]) {
	abhisheknaiidu();


	TreeNode* root = GetNewNode(1);
	root->left = GetNewNode(7);
	root->right = GetNewNode(9);
	root->left->left = GetNewNode(6);
	root->left->right = GetNewNode(5);
	root->right->left = GetNewNode(2);
	root->right->right = GetNewNode(3);
	int sum = 12;
	vector<int> cur;
	// int count = 0;
	cout << check(root, sum, cur);


   return 0;
}