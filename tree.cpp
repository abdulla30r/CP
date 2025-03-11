#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;
	
	Node(int val){
		data = val;
		left = NULL;
		right = NULL;
	}
};

void displayPreOrder(Node* root){
	if(root==NULL) return;
	cout << root->data << " ";
	displayPreOrder(root->left);
	displayPreOrder(root->right);
}

void displayInOrder(Node* root){
	if(root==NULL) return;
	displayInOrder(root->left);
	cout << root->data << " ";
	displayInOrder(root->right);
}

void displayPostOrder(Node* root){
	if(root==NULL) return;
	displayPostOrder(root->left);
	displayPostOrder(root->right);
	cout << root->data << " ";
}

int maxDepth(Node* root) {
    if(root == NULL){
        return 0;
    }

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
}

int search(vector<int>nums, int start, int end, int curr){
	for(int i = start; i<=end;i++){
		if(nums[i]==curr) return i;
	}
	return -1;
}

Node* treeFromPreandInOrder(vector<int>preOrder, vector<int>inOrder, int start, int end){
	static int idx = 0;

	if(start>end)
		return NULL;

	int curr = preOrder[idx];idx++;
	Node* node = new Node(curr);
	if(start==end) return node;

	int pos = search(inOrder,start,end,curr);

	node->left = treeFromPreandInOrder(preOrder, inOrder, start, pos-1);
	node->right= treeFromPreandInOrder(preOrder, inOrder, pos+1, end);
	return node;
}

Node* treeFromPostandInOrder(vector<int>postOrder, vector<int>inOrder, int start, int end){
	static int idx = end;

	if(start>end)
		return NULL;

	int curr = postOrder[idx];idx--;
	Node* node = new Node(curr);
	if(start==end) return node;

	int pos = search(inOrder,start,end,curr);

	node->right= treeFromPostandInOrder(postOrder, inOrder, pos+1, end);
	node->left = treeFromPostandInOrder(postOrder, inOrder, start, pos-1);
	return node;
}

vector<vector<int>> traverseBFS(Node* root){
	vector<vector<int>> bfsVec;
	if(root == NULL) return bfsVec;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		int size = q.size();
		vector<int> level;
		for(int i=0;i<size;i++){
			Node* node = q.front();
			q.pop();
			if(node->left!=NULL) q.push(node->left);
			if(node->right!=NULL) q.push(node->right);
			level.push_back(node->data);

		}
		bfsVec.push_back(level);
	}
	return bfsVec;
}

vector<int> flatten2Vec(Node* root){
	vector<int> flatVec;
	if(root == NULL) return flatVec;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		int size = q.size();
		for(int i=0;i<size;i++){
			Node* node = q.front();
			q.pop();
			if(node->left!=NULL) q.push(node->left);
			if(node->right!=NULL) q.push(node->right);
			flatVec.push_back(node->data);
		}
	}
	return flatVec;
}

vector<int> iterativePreorder(Node * root){
	vector<int> result;
	if(root==NULL) return result;

	stack<Node*> st;
	st.push(root);

	while(!st.empty()){
		Node* node = st.top();
		st.pop();
		result.push_back(node->data);

		if(node->right!=NULL) st.push(node->right);
		if(node->left!=NULL) st.push(node->left);
	}

	return result;
}

vector<int> iterativeInOrder(Node* root){
	vector<int> result;
	if(root==NULL) return result;

	stack<Node*> st;
	Node* node = root;

	while(true){
		if(node !=NULL){
			st.push(node);
			node = node->left;
		}

		else{
			if(st.empty()) break;
			node = st.top();
			st.pop();
			result.push_back(node->data);
			node = node->right;
		}
	} 

	return result;
}

stack<int> iterativePostOrder(Node* root) {
	stack<int> result;
	stack<Node*> st;

	if(root==NULL) return result;

	st.push(root);
	while(!st.empty()){
		Node* node = st.top();
		st.pop();

		result.push(node->data);
		if(node->left!=NULL) st.push(node->left);
		if(node->right!=NULL) st.push(node->right);
	}

	return result;
}

void flattenPreOrderLinkedList(Node* root){
	if(root==NULL) return;
	stack<Node*> st;
	st.push(root);

	Node* newHead = new Node(0);
	Node* tmp = newHead;

	while(!st.empty()){
		Node* node = st.top();
		st.pop();
		if(node->right!=NULL) st.push(node->right);
		if(node->left!=NULL) st.push(node->left);

		newHead->left = NULL;
		newHead->right = node;
		newHead = node;
	}

	root = tmp->right;
}

int checkBalancedBinaryTree(Node* root){
	// left height ar right height er difference always <=1 for every node

	if(root == NULL) return 0;

	int lh = checkBalancedBinaryTree(root->left);
	if(lh == -1) return -1;
	int rh = checkBalancedBinaryTree(root->right);
	if(rh ==-1) return -1;

	if(abs(lh-rh)>1) return -1;
	return max(lh,rh)+1;
}

int sum = 0; // Declare sum as a global variable

bool pathSum(Node* root, int targetSum) {
    if (root == NULL) return false;
    sum += root->data;

    if (root->left == NULL && root->right == NULL && sum == targetSum) {
        return true;
    }

    if (pathSum(root->left, targetSum)) return true;
    sum -= (root->left ? root->left->data : 0); // Backtrack only if left exists

    if (pathSum(root->right, targetSum)) return true;
    sum -= (root->right ? root->right->data : 0); // Backtrack only if right exists

    return false;
}

bool isSymmetricHelp(Node* left,Node* right){
	if(left==NULL || right == NULL)
		return left==right;

	if(left->data != right->data) return false;

	return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right , right->left);
}

bool isSymmetric(Node *root){
	return root==NULL || isSymmetricHelp(root->left,root->right);
}

int width(Node* root){
	if(!root) return 0;
	int ans = 0;
	queue<pair<Node*, int>> q;
	q.push({root,0});

	while(!q.empty()){
		int size = q.size();
		int mmin = q.front().second;
		
		int first,last;
		for(int i=0;i<size;i++){
			int cur_id = q.front().second - mmin;
			Node* node = q.front().first;
			q.pop();

			if(i==0) first = cur_id;
			if(i==size-1) last = cur_id;

			if(node->left){
				q.push({node->left,2*cur_id+1});
			}
			if(node->right){
				q.push({node->right,2*cur_id+2});
			}
		}

		ans = max(ans, (last-first + 1));
	}

	return ans;
}

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(root==NULL || root==p || root == q) return root;

        Node* left = lowestCommonAncestor(root->left, p,q);
        Node* right = lowestCommonAncestor(root->right, p, q);

        if(left==NULL) return right;
        if(right==NULL) return left;

        else{
        	return root;
        }
}

bool getPathHelper(Node* root, vector<int>& path, int x){
	if(!root) return false;

	path.push_back(root->data);

	if(root->data == x) return true;

	if( getPathHelper(root->left, path, x) || getPathHelper(root->right,path,x) ) return true;

	path.pop_back();

	return false;
}

vector<int> getPath(Node* root, int x){
	vector<int> path;
	if(!root) return {};
	bool found = getPathHelper(root, path, x);
	return path;
}


int main(){
	// Node* root = new Node(1);
	// root->left = new Node(2);
	// root->right = new Node(3);
	// root->left->left = new Node(4);
	// root->left->right = new Node(5);
	// root->right->left = new Node(6);
	// root->right->right = new Node(7);

	// displayPreOrder(root);
	// cout << endl;
	// displayInOrder(root);
	// cout << endl;
	// displayPostOrder(root);
	// cout << endl;

	// // cout << maxDepth(root);

	// vector<int> preOrder = {1, 2, 4, 5, 3, 6, 7};
	// vector<int> inOrder = {4, 2, 5, 1, 6, 3, 7};
	// vector<int> postOrder = {4, 5, 2, 6, 7, 3, 1 };

	// Node* tmp = treeFromPostandInOrder(postOrder,inOrder,0,6);
	// displayPostOrder(tmp);

	// vector<vector<int>> bfsVec =  traverseBFS(root);
	// for(auto it: bfsVec){
	// 	cout << "-> ";
	// 	for(auto itt:it){
	// 		cout << itt<<" ";
	// 	}
	// 	cout << endl;
	// }

	// vector<int> flatVec =  flatten2Vec(root);
	// for(auto it: flatVec){
	// 	cout << it <<" ";
	// }

	// vector<int> result = iterativeInOrder(root);
	// for(auto it:result) cout << it <<" ";

	// flattenPreOrderLinkedList(root);
	// displayPreOrder(root);

	// stack<int> result = iterativePostOrder(root);
	// while(!result.empty()){
	// 	cout << result.top() << " ";
	// 	result.pop();
	// }

	//cout<< checkBalancedBinaryTree(root);

	Node* root = new Node(5);
	root->left = new Node(4);
	root->left->left = new Node(11);
	root->left->left->left = new Node(7);
	root->left->left->right = new Node(2);

	root->right = new Node(8);
	root->right->left = new Node(13);
	root->right->right = new Node(4);
	root->right->right->right = new Node(1);

	vector<int> res = getPath(root,11);

	for(auto it:res) cout << it <<" ";

}