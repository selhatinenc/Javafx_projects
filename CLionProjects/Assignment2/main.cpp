#include <iostream>
#include <string>
#pragma once
#include "ApartmentLinkedList.cpp"
#include "FlatNodeDoubleLinkedList.cpp"
#include <fstream>
#include <utility>
#include <sstream>
#include <cstring>

using namespace std;
void usestrtok(char* str);
int Read_Input_File(const string filename);

void DoCommand(string basicString);
void split(string str, char div, string x[]);
vector<int> split(string str, char div, vector<int>);
void getNumberFromString(string s) {
    stringstream str_strm;
    str_strm << s; //convert the string s into stringstream
    string temp_str;
    int temp_int;
    while(!str_strm.eof()) {
        str_strm >> temp_str; //take words into temp_str one by one
        if(stringstream(temp_str) >> temp_int) { //try to convert string to int
            cout << temp_int << " ";
        }
        temp_str = ""; //clear temp string
    }
}
void CreateApartment(string ApartmenName, string InsertPlace, const string& Max_BandWith);
vector<int> extractIntegerWords(string str, vector<int> vector);
void CreateFlat(string ApartmenName, const string& InsertIndex, const string& Initial_BandWith, const string& Flat_Id);
ApartmentLinkedList* ApLL;
ApartmentNode* Node;
FlatNode* flatNode;
//vector<int> vec;
string print;
string tempstr1;
string  tempstr2;
void tokenize(std::string const &str, const char delim,
              std::vector<std::string> &out)
{
    // construct a stream from the string
    std::stringstream ss(str);

    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
}
int main() {
    ApLL=new ApartmentLinkedList();


   print="";


    Read_Input_File(R"(C:\Users\as_as\CLionProjects\Assignment2\input1.txt)");
    ofstream  of;
    string instr=R"(C:\Users\as_as\CLionProjects\Assignment2\aasds.txt)";
    of.open(instr.c_str());
    if(of.is_open()){
        of<<print;

        of.close();
    }
    else{
        cout<<"Error when opening the output file"<<endl;
    }


    return 0;
}

int Read_Input_File(const string filename) {
    fstream readstream;
    string str="";
    readstream.open(filename,ios::in);
    if(!readstream.is_open()){
        cout<<"There is exception when opening input file \n";
        return 0;
    }

    while (getline(readstream,str)){
        try {
            
        }
        catch (exception exception) {

        }
        str+="\n";

        if(str=="-1") break;
     //   cout<<str;
        DoCommand(str);
    }

    readstream.close();


    return 1;
}


string command1,command2,arg1,arg2,arg3,arg4;
void DoCommand(string linestr) {
    string arr[5];
    string arrOther[5];
    cout << linestr;

    split(std::move(linestr), '\t', (arr));
    command1 = arr[0];
    split(command1, '_', arrOther);
    command2 = arrOther[0];

    if (command2 == "add") {
        //  cout<<"here"+arrOther[1]+" \n";
        arg1 = arr[1];
        arg2 = arr[2];
        arg3 = arr[3];
        if (arrOther[1] == "flat")CreateFlat(arg1, arg2, arg3, arr[4]);
        else {
            cout << "Apartment Name:" + arg1 + " InsertPlace " + arg2 + " Max_BandWith" + arg3;
            CreateApartment(arg1, arg2, arg3);
        }
    }
    else if (command2 == "list")
    {
      print+=  ApLL->toString("");
        cout << print + "list";
    }
    else if (command2 == "merge"){

    //    cout<<"Merge two list  "+arr[1]+" "+ arr[2]+"\n";
        ApLL->MergeTwoList(arr[1],arr[2]);
    }else if (command2 == "find"){
        int max= ApLL->findMax_BandWidth();
        print+= "sum of bandwidth:\t"+to_string(max)+"\n\n";
       cout<<"Max_BandWithd:  "<< max<<"\n";
    }

    else if (command2 == "remove"){
        std::cout<<" Remove Node:"+arr[0]+"    \n";
       /*
        std::string s = arr[0];
        const char delim = ' ';

        std::vector<std::string> out;
        tokenize(s, delim, out);
        string foundatlaststr;
        for (auto &s: out) {
            if(s!=out.at(0)&&s!=""){
                foundatlaststr=s[0];
             //   std::cout << s[0] << "a\n";
            }
        }
        */

        ApLL->Remove_Apartment(arr[1]);
    }
    else if (command2 == "make"){
        ApLL->MakeFLatEmpty(arr[1], stoi(arr[2]));

    }
    else if (command2 == "relocate"){
        ////////// split manuel
        cout<<arr[3]+" arr3 \n";
        vector<int> aVector={};
        std::string s = arr[3];

    //    std::cout << "String s before removing whitespaces: " << s;
            //   << std::endl << std::endl;

         //using the erase, remove_if, and ::isspace functions
       //  s.end();
        s.erase(std::remove_if(s.begin(), s.end(), ::isspace),
                s.end());
     //   std::cout << "String s after removing whitespaces: " << s+"a ";
     ///   getNumberFromString(s);
        s=s.substr(1,s.size()-2);
        std::cout << "String s after removing whitespaces:" << s+"\n";
        aVector=split(s,',',aVector);

         cout<<" relocate  vector size:"<<aVector.size()<<" arr1 : arr2:"+arr[1]+" "<<stoi(arr[2])<<"\n";
         ApLL->toString("");
        ApLL->relocate_flats_to_same_apartment(arr[1], stoi(arr[2]),aVector);
    }




}

void CreateFlat(string ApartmenName, const string& InsertIndex, const string& Initial_BandWith, const string& Flat_Id) {
      // cout<<"ApartmentName:"+ApartmenName<<" Insert Index:"<<InsertIndex<<" Flat_ID:"+Flat_Id<<endl;
        Node=ApLL->getNode(std::move(ApartmenName));
         Node->ApartmantDLL->CreateNewNode(atoi(Flat_Id.c_str()), atoi(Initial_BandWith.c_str()), atoi(InsertIndex.c_str()));

}

void CreateApartment(string ApartmenName, string InsertPlace, const string& Max_BandWith) {
       Node= ApLL->CreateApartmentNode(std::move(ApartmenName), atoi(Max_BandWith.c_str()));

    string arr[2];
       split(std::move(InsertPlace),'_',arr);
       tempstr1=arr[0];
  //  cout<<"here  "+arr[1]+" \n";

    if(tempstr1=="before"){

        ApLL->Add_Before(ApLL->getNode(arr[1]),Node);
    }
    else if (tempstr1=="after"){

        ApLL->Add_After(ApLL->getNode(arr[1]),Node);
    }
    else ApLL->Add_to_Head(Node);


}
void usestrtok(char* str){
    char *token = strtok(str, " ");

    // Keep printing tokens while one of the
    // delimiters present in str[].
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }
}
void split(string str, char div, string x[]){

    int index=0;
    string temp = "";

    for(int i=0; i<(int)str.size(); i++){
        if(str[i] != div){
            temp += str[i];
        }
        else{


            x[index]=(temp);
            index++;
            temp = "";
        }
    }
    x[index]=(temp);


}
vector<int> split(string str, char div, vector<int> vec){

    string temp = "";

    for(int i=0; i<(int)str.size(); i++){
        if(str[i] != div){
            temp += str[i];
        }
        else{

            cout<<"temp:"+temp+"a"<<endl;
            vec.push_back(stoi(temp)) ;
            temp = "";
        }
    }

    vec.push_back(stoi(temp)) ;

    return vec;
}
vector<int> extractIntegerWords(string str, vector<int> vector)
{
    stringstream ss;

    /* Storing the whole string into string stream */
    ss << str;

    /* Running loop till the end of the stream */
    string temp;
    int found;
    while (!ss.eof()) {

        /* extracting word by word from stream */
        ss >> temp;

        /* Checking the given word is integer or not */
        if (stringstream(temp) >> found){
            vector.push_back(found);
            cout << found << " ";
        }

        /* To save from space at the end of string */
        temp = "";
    }
    return  vector;
}



/*
 *  string str="";
    std::cout << "Hello, World!" << std::endl;
    FlatNodeDoubleLinkedList FlatList;

    FlatNode* newnode;

  //  cout<<"yess";
    newnode=FlatList.CreateNewNode(21,11);
    FlatList.Add_FlattoHead(newnode);
    newnode=FlatList.CreateNewNode(20,11);

    FlatList.Add_FlattoHead(newnode);

    newnode=FlatList.CreateNewNode(19,11);
    FlatList.Add_FlattoHead(newnode);
    newnode=FlatList.CreateNewNode(18,11);

    FlatList.Add_FlattoHead(newnode);
  //  cout<<"yes  dfdfs ";
 //   cout<<to_string(FlatList.get_Node(21)->initail_bandwith);
    FlatList.Add_beforenode(FlatList.get_Node(21),FlatList.TakeawayFlatNode(18));
    newnode=FlatList.TakeawayFlatNode(19);
    FlatList.Append_NewNode(newnode);
    newnode=FlatList.TakeawayFlatNode(21);
    //cout<<to_string(newnode->flat_id)+" ";

    FlatList.Append_NewNode(newnode);
    newnode=FlatList.TakeawayFlatNode(18);
    FlatList.Add_FlattoHead(newnode);
    newnode=FlatList.TakeawayFlatNode(21);
   // cout<<to_string(newnode->flat_id)+" ";

    FlatList.Add_beforenode(FlatList.get_Node(19),newnode);
    newnode=FlatList.CreateNewNode(7,100);
    FlatList.Add_Flat_Node(3,newnode);

    // Dİsplay

 //   cout<<to_string(FlatList.sizeoflist)+"\n";
    //str=FlatList.Displays_Nodes(str);
  //  cout<<str;
 //   cout<<"yess";

//ApartmentNode
    ApartmentLinkedList* ApLL=new ApartmentLinkedList();
    ApartmentNode* xNode;
    string print="";
    xNode=ApLL->CreateApartmentNode("X",20);
    ApLL->Add_to_Head(xNode);

    FlatNode* newFlatNode;

    newFlatNode=new FlatNode;
    newFlatNode->flat_id=1;
    newFlatNode->initial_bandwith=21;
    xNode->ApartmantDLL->Add_FlattoHead(newFlatNode);

    newFlatNode=new FlatNode;
    newFlatNode->initial_bandwith=21;
    newFlatNode->flat_id=2;
    xNode->ApartmantDLL->Add_FlattoHead(newFlatNode);

    newFlatNode=new FlatNode;
    newFlatNode->initial_bandwith=21;
    newFlatNode->flat_id=3;
    xNode->ApartmantDLL->Add_FlattoHead(newFlatNode);

    // cout<<xNode->ApartmentName;



    xNode=ApLL->CreateApartmentNode("Y",20);
    ApLL->Add_to_Head(xNode);

    newFlatNode=new FlatNode;
    newFlatNode->initial_bandwith=21;
    newFlatNode->flat_id=7;
    xNode->ApartmantDLL->Add_FlattoHead(newFlatNode);

    newFlatNode=new FlatNode;
    newFlatNode->initial_bandwith=21;
    newFlatNode->flat_id=8;
    xNode->ApartmantDLL->Add_FlattoHead(newFlatNode);

    xNode=ApLL->CreateApartmentNode("Z",20);
    ApLL->Add_to_Head(xNode);

    newFlatNode=new FlatNode;
    newFlatNode->initial_bandwith=21;
    newFlatNode->flat_id=4;
    xNode->ApartmantDLL->Add_FlattoHead(newFlatNode);

    newFlatNode=new FlatNode;
    newFlatNode->initial_bandwith=21;
    newFlatNode->flat_id=5;
    xNode->ApartmantDLL->Add_FlattoHead(newFlatNode);

    newFlatNode=new FlatNode;
    newFlatNode->initial_bandwith=21;
    newFlatNode->flat_id=6;
    xNode->ApartmantDLL->Add_FlattoHead(newFlatNode);

    //ApLL->Remove_Apartment("");
    //ApLL->MergeTwoList("Y","Z");
   // ApLL->MergeTwoList("Z","X");
    cout<<ApLL->SumOfBandwith();
   // ApLL->MakeFLatEmpty("Z",6);
   vector<int> vector={1,5,7};
   ApLL->relocate_flats_to_same_apartment("X",2,vector); //work
   ApLL->MakeFLatEmpty("X",5);
    print=ApLL->toString("");
 */

//print= ApLL->toString(print);
//cout<<print+" end\n";
//getNumberFromString("[ 17, 25 ]");
// string arr[2];
//  split("remove_x    X",' ',arr);
//  cout<<"arr[0: "+arr[0]+"\n";
/*
    std::string s = "This      is java2blog";
    const char delim = ' ';

    std::vector<std::string> out;
    tokenize(s, delim, out);

    for (auto &s: out) {
        std::cout << s << "a\n";
    }*/