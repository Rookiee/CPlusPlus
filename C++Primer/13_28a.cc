#include <string>

class TreeNode {
private: 
	std::string value;
	int count;
	TreeNode *left;
	TreeNode *right;
public:
	//constructor
	TreeNode() : count(0), left(0), right(0) {}
	TreeNode( const TreeNode &rhs):value(rhs.value),count(rhs.count) {
		if(rhs.left)
			left = new TreeNode(*rhs.left);
		else
			left = 0;
		if(rhs.right)
			right = new TreeNode(*rhs.right);
		else
			right = 0;
	}
	~TreeNode() {
		if(left)
			delete left;
		if(right)
			delete right;
	}
};


class BinStrTree {
private:
	TreeNode *root;
public:
	BinStrTree () : root(0) {}
	BinStrTree(const BinStrTree &rhs) {
		if(rhs.root)
			root = new NodeTree(*rhs.root);
		else
			root = 0;
	}
	~BinStrTree() {
		if(root)
			delete root;
	}
};
