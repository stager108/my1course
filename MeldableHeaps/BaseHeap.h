#pragma once
template <typename T>
class BaseHeap : public IHeap {
protected:
	std::shared_ptr<T> Root = nullptr;
	//virtual std::shared_ptr <T>& subMeld(std::shared_ptr<T> &index1, std::shared_ptr<T> &index2) = 0;
public:
	explicit BaseHeap() {}

	//BaseHeap(BaseHeap* OldHeap) {}//copy
	//BaseHeap() {}//move

	~BaseHeap() {
	}

	void Insert(int key) override {
		std::shared_ptr<T> New(new T);
		New->value = key;
		Root =  (subMeld(Root, New));
	}

    virtual void Meld(std::shared_ptr <IHeap> &other){
    //	std::shared_ptr <BaseHeap> tmp = dynamic_cast<std::shared_ptr <BaseHeap>>(other);
	//	Root =  (subMeld(Root, tmp->Root));
	//	tmp->Root = nullptr;
	}

    virtual	void ChildrenSwap(std::shared_ptr <T> &index1) = 0;

	virtual std::shared_ptr <T>& subMeld(std::shared_ptr <T> &index1, std::shared_ptr <T> &index2) {
	
		if (index1 == nullptr) {
			return index2;
		}
		if (index2 == nullptr) {
			return index1;
		}
		if (index1->value > index2->value) std::swap(index1, index2);
		index1->right = (subMeld(index2, index1->right));
		ChildrenSwap(index1);
		return index1;
	}
	
	int Min() const override {
		if (Root != nullptr) { return Root->value; }
		else return 0;
	}

	void ExtractMin() override {
		std::shared_ptr<T> DelNode = Root;
		if (Root != nullptr) {
			Root =  (subMeld(Root->left, Root->right));
			DelNode->left = nullptr;
			DelNode->right = nullptr;
		}
	}
};