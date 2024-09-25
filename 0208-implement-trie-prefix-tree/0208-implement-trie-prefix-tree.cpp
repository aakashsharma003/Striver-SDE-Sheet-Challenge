struct Node {
	Node* links[26];
	bool flag = false;
	bool containsKey(char ch) {
		return (links[ch - 'a'] != nullptr);
	}
	Node* get(char ch) {
		return links[ch - 'a'];
	}
	void put(char ch, Node* node) {
		links[ch - 'a'] = node;
	}
	void setEnd() {
		flag = true;
	}
	bool isEnd(){
		return flag;
	}

};
class Trie {
private: Node* root;
public:

	Trie() {
		root = new Node();
	}

	void insert(string str) {
		Node* cur = root;
		for (auto ch : str) {
			if (!cur->containsKey(ch)) cur->put(ch, new Node());
				cur = cur->get(ch);
		}
		cur->setEnd();
	}

	bool search(string str) {
		Node* cur = root;
		for (auto ch : str) {
			if (!cur->containsKey(ch)) return false;
			cur = cur->get(ch);
		}
		return cur->isEnd();
	}

	bool startsWith(string str) {
		Node* cur = root;
		for (auto ch : str) {
			if (!cur->containsKey(ch)) return false;
			cur = cur->get(ch);
		}
		return true;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */