#include "BST_PRIMARY_TREE.cpp"
#include <bits/stdc++.h>
#include "LLRB_TREE.cpp"
using namespace std;

string first_type(const vector<string>& in_vec);
void read_Input(const string& input_file, vector<string> &input_vector);
void tokenize(std::string const &str, const char* delim,
              std::vector<std::string> &out);


void write_output_file(const string& basicString, const char *str);

void second_Type(vector<string> vector1);

int main(int argc, char **argv) {
    vector<string> input_vector;
    read_Input(argv[1],input_vector);
    string  print_str;
    /*
    print_str=first_type(input_vector);
    write_output_file(print_str,argv[2]);
*/
    second_Type(input_vector);
   // std::cout << "Hello, World!" << std::endl;
    return 0;
}

void second_Type(vector<string> vector1) {
    LLRB_TREE tree;
    LLRB as=NULL;
    LLRB_NODE * goat = NULL;

    /* LLRB tree made after all insertions are made.

    1. Nodes which have double INCOMING edge means
       that they are RED in color.
    2. Nodes which have single INCOMING edge means
       that they are BLACK in color.

        root
         |
         40
       //  \
      20    50
     /  \
    10    30
        //
       25    */

    as = tree.insert(goat,"bass", 10);

    // To make sure that root remains
    // black is color
    as -> color = false;

    root = tree.insert(root,"bass", 10);
    root -> color = false;

    root = tree.insert(root,"bass", 10);
    root -> color = false;

    root = tree.insert(root,"bass", 10);
    root -> color = false;

    root = tree.insert(root,"bass", 10);
    root -> color = false;

    root = tree.insert(root,"bass", 10);
    root -> color = false;

    // Display the tree through inorder traversal.
    tree.inorder(root);
}

void write_output_file(const string& basicString, const char * str) {
    ofstream of;
    of.open(str);
    if(!of.is_open()){
        cout<<"FIlE COULD NOT OPEN\n";
        return;
    }
    of<<basicString;
    of.close();


}

void read_Input(const string& input_file, vector<string> &input_vector){
    std::ifstream read;
     read.open(input_file);
    //read.open(input_file.c_str());

    if(!read.is_open()){
        cout<<"Input file was not found \n";
        return;
    }

    string str;
    while (std::getline(read,str)){
      input_vector.push_back(str);
  //    cout<<str<<endl;
    }
}


string first_type(const vector<string>& in_vec){
    vector<string> split_command_vec;
    string first;
    string print_string;
    BST_PRIMARY_TREE Primary_TREE;
    for (auto i:in_vec){//    cout<<i<<endl;
        split_command_vec.clear();
        tokenize(i,"\t",split_command_vec);

        //cout<<i<<endl;
       first=split_command_vec[0];
       if(first=="insert"){
           Primary_TREE.insert_PrimaryItem(split_command_vec[1],split_command_vec[2], stoi(split_command_vec[3]));
       }
       else if(first=="printAllItems"){
           print_string+="command:printAllItems\n{\n";

           print_string+=   Primary_TREE.print_ALL_Category();
           print_string+="}\n";
      //     cout<<print_string;
       }
       else if(first=="updateData"){
        //   cout<<"new start updateData\n";
        Primary_TREE.Update_item(split_command_vec[1],split_command_vec[2], stoi(split_command_vec[3]));
         //  cout<<"new start updateData\n";

       }
       else if(first=="printItem"||first=="find"){
           print_string+="command:\t"+split_command_vec[0]+"\t"+split_command_vec[1]+"\t"+split_command_vec[2]+"\n{\n";
           print_string+=Primary_TREE.print_item(split_command_vec[1],split_command_vec[2]);
           print_string+="}\n";

       }
       else if(first=="printAllItemsInCategory"){
           print_string+="command:\t"+split_command_vec[0]+"\t"+split_command_vec[1]+"\n{\n";
           print_string+=Primary_TREE.print_Category(split_command_vec[1]);
           print_string+="}\n";

       }
       else if(first=="remove"){
        Primary_TREE.Delete_Product_item(split_command_vec[1],split_command_vec[2]);
       }
    }
    return print_string;
}



void tokenize(std::string const &str, const char* delim,
              std::vector<std::string> &out)
{
    char *token = strtok(const_cast<char*>(str.c_str()), delim);
    while (token != nullptr)
    {
        out.emplace_back(token);
        token = strtok(nullptr, delim);
    }
}






/*
 * TRY FUNCTİONS BELOW
 *
 *
 *
 *
 *
 * void splitString(vector<string>&vec,string str, string delimiter )
{
    int start = 0;
    int end = str.find(delimiter);
    while (end != -1) {
        vec.push_back(str.substr(start, end - start));
        cout << str.substr(start, end - start) << endl;
        start = end + delimiter.size();
        end = str.find(delimiter, start);
    }
    cout << str.substr(start, end - start);
}
 *
  BST_PRIMARY_TREE Primary_TREE;
  Primary_TREE.insert_PrimaryItem("SELO BAŞKAN");
  Primary_TREE.insert_PrimaryItem("MEMO BAŞKAN");
  Primary_TREE.insert_PrimaryItem("YUSUF BAŞKAN");
  Primary_TREE.insert_PrimaryItem("ZEN BAŞKAN");
  Primary_TREE.insert_PrimaryItem("OMAR BAŞKAN");
  Primary_TREE.insert_PrimaryItem("ALi BAŞKAN");
  Primary_TREE.insert_PrimaryItem("GAVAT_VELİ");
  Primary_TREE.insert_PrimaryItem("SELİ BAŞKAN");
  Primary_TREE.insert_PrimaryItem("TELLİ BAŞKAN");
  Primary_TREE.insert_PrimaryItem("ZANA BAŞKAN");
  Primary_TREE.insert_PrimaryItem("YUSUF BAŞKAN");
  Primary_TREE.Delete_Item("GAVAT_VELİ");

  Primary_TREE.Print_InOrder();





  AVL_TREE_SECONDKEY avlTreeSecondkey;
avlTreeSecondkey.Insert_Item_to_AVL_TREE("Ahmet",21);
 // cout<<"Debug \n";
//   cout<<avlTreeSecondkey.print_Item("Ahmet");

  avlTreeSecondkey.Insert_Item_to_AVL_TREE("Bahmet",35);
//  cout<<"Debug \n";
 // cout<<avlTreeSecondkey.print_Item("Bahmet");

  avlTreeSecondkey.Insert_Item_to_AVL_TREE("Chmet",12);
//   cout<<avlTreeSecondkey.print_Item("Chmet");

  avlTreeSecondkey.Insert_Item_to_AVL_TREE("Dhmet",7);
  avlTreeSecondkey.Insert_Item_to_AVL_TREE("Fahmet",44);
  avlTreeSecondkey.Insert_Item_to_AVL_TREE("Ahmat",7);


  //  cout<<"Debug \n";
  cout<<avlTreeSecondkey.Print_InOrder();

//  avlTreeSecondkey.delete_Node("Bahmet");
  cout<<avlTreeSecondkey.Print_InOrder();
 ///  avlTreeSecondkey.Change_Item("Chmet",77);
//  cout<<avlTreeSecondkey.print_Item("Chmet");
  cout<<avlTreeSecondkey.Print_Level_Order();


    BST_PRIMARY_TREE Primary_TREE;
  Primary_TREE.insert_PrimaryItem("BOSS","SELO BOSS",21);
  Primary_TREE.insert_PrimaryItem("BOSS","EKO BOSS",21);
  Primary_TREE.insert_PrimaryItem("BOSS","YUSE BOSS",21);
  Primary_TREE.insert_PrimaryItem("BOSS","KRAL BOSS",21);
  Primary_TREE.insert_PrimaryItem("HAS","SELO BOSS",21);
  Primary_TREE.insert_PrimaryItem("HAS","EKO BOSS",21);
  Primary_TREE.insert_PrimaryItem("HAS","YUSE BOSS",21);
  Primary_TREE.insert_PrimaryItem("HAS","KRAL BOSS",21);
  Primary_TREE.insert_PrimaryItem("BOSS","SELO BOSS",21);
  Primary_TREE.insert_PrimaryItem("BOSS","EKO BOSS",21);
  Primary_TREE.insert_PrimaryItem("BOSS","YUSE BOSS",21);
  Primary_TREE.insert_PrimaryItem("BOSS","KRAL BOSS",21);
  Primary_TREE.insert_PrimaryItem("HAS","SELO BOSS",21);
  Primary_TREE.insert_PrimaryItem("HAS","EKO BOSS",21);
  Primary_TREE.insert_PrimaryItem("HAS","YUSE BOSS",21);
  Primary_TREE.insert_PrimaryItem("HAS","KRAL BOSS",21);
  Primary_TREE.insert_PrimaryItem("Sports","chess",21);
  Primary_TREE.Delete_Product_item("Sports","chess");
  cout<<  Primary_TREE.print_Category("Sports");
  cout<<Primary_TREE.print_item("Sports","chess");
//   cout<<Primary_TREE.print_ALL_Category();
 // cout<<Primary_TREE.print_item("BOSS","YUSE BOSS");
*/
