#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    int orignal_index;
    TreeNode(int x=-1,int idx=-1):val(x),left(nullptr),right(nullptr),orignal_index(idx){}
};
vector<string> parse_input_string(const string& input_str) {
    vector<string> tokens;
    string current_token;
    bool in_brackets = false;
    if(!input_str.empty()&&input_str.front()=='{'){
        in_brackets = true;
    }
    for(size_t i=(in_brackets?1:0);i<input_str.length();++i){
        char c = input_str[i];
        if(c==','||(in_brackets&&c=='}')){
            if(!current_token.empty()){
                size_t first=current_token.find_first_not_of(" ");
                size_t last=current_token.find_last_not_of(" ");
                if(first!=string::npos){
                    tokens.push_back(current_token.substr(first,last-first+1));
                }
            }else if(current_token.find_first_of("-#0123456789")!=string::npos){
                tokens.push_back(current_token);
            }else if(!tokens.empty()&&tokens.back()==","){
                tokens.push_back("#");
            }
            current_token="";
            if(c=='}') break;
        }else{
            if(!(current_token.empty()&&c==' '&&i==(in_brackets?1:0))&&!(c==' '&&i==input_str.length()-(in_brackets?2:1))){
                current_token+=c;
            }
        }
    }
    if(!current_token.empty()){
        size_t first=current_token.find_first_not_of(" ");
        size_t last=current_token.find_last_not_of(" ");
        if(first!=string::npos){
            current_token=current_token.substr(first,last-first+1);
        }else if(current_token.find_first_of("-#0123456789")!=string::npos){
            tokens.push_back(current_token);
        }
    }
    return tokens;
}
int main(){
    string input_line;
    getline(cin, input_line);
    vector<string> input_tokens=parse_input_string(input_line);
    vector<TreeNode*> nodes;
    vector<TreeNode*> nodes_to_fill;
    int n=0;
    nodes.reserve(input_tokens.size());
    for(size_t i=0;i<input_tokens.size();++i){
        if(input_tokens[i]=="#"||input_tokens[i]=="null"){
            nodes.push_back(nullptr);
        }else{
            try{
                int val=stoi(input_tokens[i]);
                TreeNode* node=new TreeNode(-1,i);
                nodes.push_back(node);
                if(val==-1){
                    nodes_to_fill.push_back(node);
                    n++;
                }else{

                }
            }catch(const invalid_argument& e){
                cerr<<"Invalid argument: "<<input_tokens[i]<<endl;
                nodes.push_back(nullptr);
            }
        }
    }
    n=0;
    nodes_to_fill.clear();
    for(TreeNode* node:nodes){
        if(node!=nullptr){
            nodes_to_fill.push_back(node);
            n++;
        }
    }
    if(n==0||nodes.empty()||nodes[0]==nullptr){
        cout<<"{}"<<endl;
        return 0;
    }
    queue<TreeNode*> q_build;
    q_build.push(nodes[0]);
    size_t current_index=1;
    while(!q_build.empty()&&current_index<nodes.size()){
        TreeNode* parent=q_build.front();
        q_build.pop();
        if(parent==nullptr){
            continue;
        }
        if(current_index<nodes.size()){
            parent->left=nodes[current_index++];
            if(parent->left!=nullptr){
                q_build.push(parent->left);
            }
        }
        if(current_index<nodes.size()){
            parent->right=nodes[current_index++];
            if(parent->right!=nullptr){
                q_build.push(parent->right);
            }
        }
    }
    vector<TreeNode*> odd_level_nodes;
    vector<TreeNode*> even_level_nodes;
    queue<pair<TreeNode*,int>> q_level;
    if(nodes[0]){
        q_level.push({nodes[0],1});
    }
    while(!q_level.empty()){
        TreeNode* cur_node=q_level.front().first;
        int level=q_level.front().second;
        q_level.pop();
        if(level%2!=0){
            odd_level_nodes.push_back(cur_node);
        }else{
            even_level_nodes.push_back(cur_node);
        }
        if(cur_node->left){
            q_level.push({cur_node->left,level+1});
        }
        if(cur_node->right){
            q_level.push({cur_node->right,level+1});
        }
    }
    if(odd_level_nodes.size()+even_level_nodes.size()!=n){
        cout<<"{}"<<endl;
        return 1;
    }
    vector<int> odd_values;
    vector<int> even_values;
    long long cur_sum_odd=0;
    long long cur_sum_even=0;
    int slots_odd=odd_level_nodes.size();
    int slots_even=even_level_nodes.size();
    for(int k=n;k>=1;--k){
        bool can_assign_odd=(slots_odd>0);
        bool can_assign_even=(slots_even>0);
        bool assign_to_odd=false;
        if(can_assign_odd && can_assign_even){
            assign_to_odd=(cur_sum_odd<=cur_sum_even);
        }else if(can_assign_odd){
            assign_to_odd=true;
        }else if(can_assign_even){
            assign_to_odd=false;
        }else{
            cout<<"{}"<<endl;
            return 1;
        }
        if(assign_to_odd){
            odd_values.push_back(k);
            cur_sum_odd+=k;
            slots_odd--;
        }else{
            even_values.push_back(k);
            cur_sum_even+=k;
            slots_even--;
        }
    }
    if(abs(cur_sum_odd-cur_sum_even)>1){
        cout<<"{}"<<endl;
        return 1;
    }
    vector<string> result_tokens(input_tokens.size());
    for(size_t i=0;i<input_tokens.size();++i){
        result_tokens[i]=input_tokens[i];
    }
    int odd_val_idx=0;
    for(TreeNode* node:odd_level_nodes){
        if(odd_val_idx<odd_values.size()){
            node->val=odd_values[odd_val_idx++];
            if(node->orignal_index!=-1&&node->orignal_index<result_tokens.size()){
                result_tokens[node->orignal_index]=to_string(node->val);
            }
        }
    }
    int even_val_idx=0;
    for(TreeNode* node:even_level_nodes){
        if(even_val_idx<even_values.size()){
            node->val=even_values[even_val_idx++];
            if(node->orignal_index!=-1&&node->orignal_index<result_tokens.size()){
                result_tokens[node->orignal_index]=to_string(node->val);
            }
        }
    }
    while(!result_tokens.empty()&&result_tokens.back()=="#"){
        result_tokens.pop_back();
    }
    bool first=true;
    bool use_brackets=(!input_line.empty()&&input_line.front()=='{');
    if(use_brackets){
        cout<<"{";
    }
    for(const auto& token:result_tokens){
        if(!first){
            cout<<",";
        }
        cout<<token;
        first=false;
    }
    if(use_brackets){
        cout<<"}";
    }
    cout<<endl;
    for(TreeNode* node:nodes){
        delete node;
    }
    return 0;
}
