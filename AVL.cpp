#include<iostream>
#include<queue>
using namespace std;
template<typename T>
struct TNode{
	T data;
	TNode<T>* left,*right;int height,balance;
};

template<typename T>
class BST{
private:
	TNode<T>* root;

public:
	BST(){
	root=NULL;
	}

	void insert(T val){
	
	insertR(root,val);

	}


	bool Delete(T val){
	return DeleteR(root,val);
	}

	////////////////////////////LEVEL ORDER  TRAVERSAL///////////////////
	


	void make_empty(){
		//if(root==NULL){return;}
			
	make_emptyR(root);
	root=NULL;//////////////////////////////////why
	}
	

	void operator=(const BST<T>& src){
	make_empty();
	copy_tree(root,src.root);
	
	}

	void preorder(){
	pre_order(root);
	}

	void levelorder(){
		//cout<<root<<endl;
		level_orderR(this->root);
	}

	
	~BST(){
		make_emptyR(root);
	}


	 

};

template<typename T>
void pre_order(TNode<T>* ptr){
	if(ptr!=NULL){
	cout<<ptr->data;
	pre_order(ptr->left);
	pre_order(ptr->right);
	
	}
}


template<typename T>
void make_emptyR(TNode<T> *&ptr){
	 

	if(ptr!=NULL){
		///make_emptyR(ptr->left);
		//make_emptyR(ptr->right);
		//delete ptr;	
	}

}/////////////////////////////////ending make_emptyR////////////////

template<typename T>
void copy_tree(TNode<T> *&dest,const TNode<T>* src){
	if(src!=NULL){
	dest=new TNode<T>;
	dest->data=src->data;
	dest->left=dest->right=NULL;
	
	

	copy_tree(dest->left,src->left);
	copy_tree(dest->right,src->right);
	
	}
	
}//////////////ending copy_tree//////////////////////////////////////




////////////////////////////LEVEL ORDER  TRAVERSAL///////////////////
template<typename T>
void level_orderR(TNode<T>* ptr) {
	////why const can't be written before TNode<T>* ptr 
	
queue<TNode<T>*> q;
q.push(ptr);

while(!q.empty()){
TNode<T>* temp=q.front();
 
cout<<temp->data<<" ";

cout<<temp->height;
cout<<endl;
if(temp->left!=NULL)
q.push(temp->left);

if(temp->right!=NULL)
q.push(temp->right);
q.pop();
//delete temp;
}
	
}//////////level_order ends/////////////////////////////
	


template<typename T>
bool DeleteNode(TNode<T> *&ptr){
	if(ptr->left==NULL&& ptr->right==NULL){
	delete ptr;
	ptr=NULL;
	return 1;
	}

	else if(ptr->left!=NULL && ptr->right==NULL){
		TNode<T>* temp;
	temp=ptr;
		ptr=ptr->left;
		delete temp;
		return 1;

	}

	else if(ptr->left==NULL && ptr->right!=NULL){
		TNode<T>* temp;
	temp=ptr;
		ptr=ptr->right;
		delete temp;
		return 1;

	}

	else{
		TNode<T>* suc=ptr->right;

		while(suc->left!=NULL){
		suc=suc->left;
		}

		ptr->data=suc->data;

		return DeleteR(ptr->right,suc->data);

	}






}///////////////////////////////////////////Ending DeleteNode///////////



template<typename T>
bool DeleteR(TNode<T> *&ptr ,T val){
		if(ptr==NULL){
		return false;
		}

		else if(val==ptr->data){
		return DeleteNode(ptr);
		}

		else if(val<ptr->data){
		return DeleteR(ptr->left,val);
		}

		else{
		return DeleteR(ptr->right,val);
		}


	}///////////////////////////ending DELETER

template<typename T>

int height(TNode<T>* ptr){
if (ptr==NULL)return 0;

return ptr->height;
}


template<typename T>
void insertR(TNode<T> *&ptr,T val){
	if(ptr==NULL){
	
	ptr=new TNode<T>;
	ptr->data=val;
	ptr->left=ptr->right=NULL;
	ptr->height=1;////new node has height 1
	 

	}//ending if

	else if(val<ptr->data){
		insertR(ptr->left,val);
	}/////ending else if

	else if(val>ptr->data){
	
		insertR(ptr->right,val);

	}///////////////ending else

	//ptr->height=1+(max(ptr->left->height,ptr->right->height)); 
////OR
	

	ptr->height=1+(max(  height(ptr->left),  height(ptr->right) ) );
	
	int balance=(height(ptr->left) - height(ptr->right));


	if(balance<-1 && val> ptr->right->data){
	TNode<T> * G,*H;
	G=ptr->right;
	H=ptr->right->left;

	ptr->right=H;
	G->left=ptr;

	G->height=1+(max   (   height(G->left)  ,  height(G->right)  )  );//by left rotation  height of ptr->right and that of ptr changes
	ptr->height=1+(max   (   height(ptr->left)  ,  height(ptr->right)  )  );

	
	}

	

}///////////////////////////////////ending insertR



int main(){
BST<int> t1;
t1.insert(20);
t1.insert(30); 
t1.insert(40);
 

BST<int> t2;
t2=t1;

 
t1.levelorder();cout<<endl;



system("PAUSE");
return 0;
}
