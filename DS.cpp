#include "bits/stdc++.h"
using namespace std;

#define ll long long 

struct node{
    ll ph,sr;
    string name;
    node* left, *right ;

    node(ll a,string s,ll p){
        left=NULL;
        right = NULL;
        sr=a;
        name=s;
        ph=p;
  
    }
};

node* makebst(node* &root,ll a,string s,ll b){
    if(root==NULL)return new node(a,s,b);

    if(a<root->sr)root->left=makebst(root->left,a,s,b);

    else root->right=makebst(root->right,a,s,b);

    return root;
}

int searchph(node*root,ll val,int x){
    if(root==NULL){
        return x;
    }
    
    if(root->ph==val){
        cout<<root->sr<<") "<<root->name;
        return x+=1;
    }

    searchph(root->left,val,x);

    searchph(root->right,val,x);
    

    return x;
}


void display(node*&root){
    if(root==NULL)  return;
    
    display(root->left);

    cout<<root->sr<<") "<<root->name<<" -> "<<root->ph<<endl;
    
    display(root->right);
}

void searchsr(node*root,ll  val){
    if(root==NULL)  {
        cout<<"No Node"<<endl;
        return ;
    }
    if(root->sr==val) {
        cout<<root->name<<" -> "<<root->ph ;
        return;
    }

    else if(root->sr>val) return searchsr(root->left,val);

    else return searchsr(root->right,val);
    
    cout<<"Not Found"<<endl;
    return ;
}

int32_t main(){
   
   node* root=NULL;
    root=makebst(root,5,"AA",9096631079);
    makebst(root,1,"AB",9158158170);  
    makebst(root,3,"BA",7775072160);  
    makebst(root,4,"AC",9822748251);  
    makebst(root,2,"CA",8087666446);  
    makebst(root,6,"BC",7020423937);    

    cout<<"Enter a no according to the following:"<<endl;
    cout<<"1 - Display All"<<endl;
    cout<<"2 - Search With Sr.No"<<endl;
    cout<<"3 - Search With Phone Number"<<endl;    
    cout<<"4 - Enter New User Detail"<<endl;

    int x;
    cin>>x;

    
    if(x==1){
        cout<<"All the numbers are: "<<endl;
        display(root);
    }

    else if(x==2){
        cout<<"Enter a Sr.no. :"<<endl;
        int h;
        cin>>h;
        searchsr(root,h);}

    else if(x==3){
        cout<<"Type the Phone no."<<endl;
        ll ph;
        cin>>ph;   
        int y=0;
        y=searchph(root,ph,y);
        
    }

    else if(x==4){
        cout<<"Enter sr. no."<<endl;
        int q;
        cin>>q;
        cout<< "Name: "<<endl;
        string s;
        cin>>s;
        cout<<"Ph. No. :"<<endl;
        ll n;
        cin>>n;
        makebst(root,q,s,n);
        display(root);
    }

    else cout<<"Enter a Valid No."<<endl<<endl;
   
}