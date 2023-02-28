#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
string printstr="";

struct Flats {
    int flat_id;
    int initial_bandwidth;
    bool is_empty;
    Flats* next = NULL;
    Flats* prev = NULL;
};

struct Apartments {
    int current_maxBandwidth=0;
   string apartment_name;
   int max_bandwidth;
   struct Flats *flats = NULL;
   struct Apartments *next;
};

struct Apartments* current = NULL;

struct Apartments* addEmptyApartments(string apartment_name, int max_bandwidth)
{
    if (current != NULL)
        return current;

     Apartments* temp = new Apartments();

    temp->apartment_name = apartment_name;
    temp->max_bandwidth = max_bandwidth;

    current = temp;

    current->next = NULL;
    return current;
}

struct Apartments* addBeginApartments(string apartment_name, int max_bandwidth)
{
    if (current == NULL)
        return addEmptyApartments(apartment_name, max_bandwidth);

    struct Apartments* temp = new Apartments();

    temp->apartment_name = apartment_name;
    temp->max_bandwidth = max_bandwidth;

    temp->next = current->next;
    current->next = temp;
    return current;
}

struct Apartments* addAfterApartment(string apartment_name, int max_bandwidth, string target_apartment) {

    struct Apartments *temp = current;

    if(current->next == NULL) {
        temp->next = new Apartments();
        temp->next->apartment_name = apartment_name;
        temp->next->max_bandwidth = max_bandwidth;
        temp->next->next = NULL;
        return current;
    }

    while(temp != NULL) {
        if(temp->apartment_name == target_apartment){

            struct Apartments *new_apartment = new Apartments();
            new_apartment->apartment_name = apartment_name;
            new_apartment->max_bandwidth = max_bandwidth;
            new_apartment->next = temp->next;
            temp->next = new_apartment;
            return current;
        }
        temp = temp->next;
    }
    return current;
}

struct Apartments* addBeforeApartment(string apartment_name, int max_bandwidth, string target_apartment)
{

    struct Apartments *temp = current;

    if(current->apartment_name == target_apartment) {
        struct Apartments *temp_2 = new Apartments();
        temp_2->apartment_name = apartment_name;
        temp_2->max_bandwidth = max_bandwidth;
        temp_2->next = temp;
        current = temp_2;
        return current;
    }

    while(temp != NULL) {
        if(temp->next->apartment_name == target_apartment){
            addAfterApartment(apartment_name, max_bandwidth, temp->apartment_name);
            return current;
        }
        temp = temp->next;
    }

    return current;
}


void deleteSpecificApartment(string apartment_name)
{

    if (current == NULL)
        return;

    struct Apartments *temp = current;
    if(temp->apartment_name == apartment_name) {
        current = current->next;
        delete temp;
        return;
    }

    while(temp != NULL) {
        if(temp->next->apartment_name == apartment_name){
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }

}


// Extra function to print vector values
void _print_vector_values (const vector<int>& v){

  for (int i = 0; i < v.size(); i++);
    //cout << v[i] << " ";

}

// Extra function to convert string to vector
/* Realocate
 * */
vector<int> _string_to_vector_list(string list){

    char chars[] = "[]";

   for (unsigned int i = 0; i < strlen(chars); ++i)
        list.erase (remove(list.begin(), list.end(), chars[i]), list.end());

    replace(list.begin(), list.end(), ',', ' ');

    stringstream ss(list);
    string number;
    vector<int> numbers_list;

    while (ss >> number) {
        numbers_list.push_back(stoi(number));
    }
    return numbers_list;
}


void _determine_apartment_add_location(string apartment_name, string location, int max_bandwidth) {

    string operation_name = location;

    if(operation_name == "head")
        addBeginApartments(apartment_name, max_bandwidth);
    else{
        replace(operation_name.begin(), operation_name.end(), '_', ' ');

        stringstream ss(operation_name);
        string arg;
        vector<string> location_list;

        while (ss >> arg) {
            location_list.push_back(arg);
        }

        string operation_name = location_list[0];
        string target_apartment = location_list[1];

        if (operation_name == "after"){
            addAfterApartment(apartment_name, max_bandwidth, target_apartment);
        }
        else if (operation_name == "before")
            addBeforeApartment(apartment_name, max_bandwidth, target_apartment);

    }

}

void add_apartment(string apartment_name, string location, int max_bandwidth){
    // //cout << "apartment_name: " << apartment_name << " , location: " << location << " , max_bandwidth: " << max_bandwidth << endl;
    _determine_apartment_add_location(apartment_name, location, max_bandwidth);
}


void add_flat(string apartment_name, int index, int initial_bandwidth, int flat_id){
    // TODO: 1 - max_bandwidth bound check with flats initial_bandwidth
    // 2 - 1 2 1 eklemesi yapıldığında hata
    struct Apartments *temp_apartment = current;

    if(temp_apartment == NULL)
        return;

    while(temp_apartment != NULL) {
        if(temp_apartment->apartment_name == apartment_name){
            struct Flats *new_flat = new Flats();
            new_flat->flat_id = flat_id;
            if(initial_bandwidth+temp_apartment->current_maxBandwidth>temp_apartment->max_bandwidth){
                initial_bandwidth=temp_apartment->max_bandwidth-temp_apartment->current_maxBandwidth;
            }
            new_flat->initial_bandwidth = initial_bandwidth;
            new_flat->is_empty = false;

            if(index == 0) {
                if(temp_apartment->flats==NULL){
                temp_apartment->flats = new_flat;
                temp_apartment->flats->next = NULL;
                temp_apartment->flats->prev = NULL;
                return;
                }
                else{
                    new_flat->next=temp_apartment->flats;
                    temp_apartment->flats->prev=new_flat;
                    temp_apartment->flats=new_flat;
                }
            }

            int count = 0;
            struct Flats *temp_flat = temp_apartment->flats;
            while(temp_flat != NULL) {
                if(count + 1 == index){
                    if(temp_flat->next==NULL){
                    temp_flat->next = new_flat;
                    new_flat->prev = temp_flat;
                    temp_flat->next->prev = temp_flat;
                    }
                    else{
                        new_flat->prev=temp_flat;
                        new_flat->next=temp_flat->next;
                        temp_flat->next=new_flat;
                        new_flat->next->prev= new_flat;
                    }
                    break;
                }
                temp_flat = temp_flat->next;
                count++;
            }

        }
        temp_apartment = temp_apartment->next;
    }


}

void remove_apartment(string apartment_name){
    deleteSpecificApartment(apartment_name);
    // //cout << "apartment_name: " << apartment_name << endl;
}

void make_flat_empty(string apartment_name, int flat_id){
    struct Apartments *temp_apartment = current;

    if(temp_apartment == NULL)
        return;

    while(temp_apartment != NULL) {
        if(temp_apartment->apartment_name == apartment_name) {
            struct Flats *temp_flat = temp_apartment->flats;
            while(temp_flat != NULL) {
                if(temp_flat->flat_id == flat_id){
                    temp_flat->initial_bandwidth = 0;
                    temp_flat->is_empty = true;
                }
                temp_flat = temp_flat->next;
            }
        }
        temp_apartment = temp_apartment->next;
    }
}

int find_sum_of_max_bandwidths(){

    struct Apartments *temp = current;
    int sum_of_max_bandwidths = 0;
    while(temp != NULL) {
        sum_of_max_bandwidths += temp->max_bandwidth;
        temp = temp->next;
    }

    return sum_of_max_bandwidths;
}

void merge_two_apartments(string apartment_name_1, string apartment_name_2){

     Apartments* temp_apartment = current;
     Flats* source_flats ;
    int source_max_bandwidth;
    while(temp_apartment != NULL){
        if(temp_apartment->apartment_name == apartment_name_2){
            source_flats = temp_apartment->flats;
           // //cout<< "head 2 flats id:"<<source_flats->flat_id<<endl;
            source_max_bandwidth = temp_apartment->max_bandwidth;
            break;
        }
        temp_apartment = temp_apartment->next;
    }

    struct Apartments* temp_apartment_2 = current;

    while(temp_apartment_2 != NULL){
        if(temp_apartment_2->apartment_name == apartment_name_1){
            temp_apartment_2->max_bandwidth += source_max_bandwidth;

            // TODO: Flatları ekleme ile ilgili hata var !!

            struct Flats *temp_flat = temp_apartment_2->flats;
            while(temp_flat->next != NULL) {
                //cout << temp_flat->flat_id << endl;
                temp_flat = temp_flat->next;
            }

            temp_flat->next = source_flats;

            break;
        }
        temp_apartment_2 = temp_apartment_2->next;
    }
    if(temp_apartment==current){
        current=current->next;
        delete(temp_apartment);
        return;
    }
     Apartments* temp = current;
    while (temp->next!=temp_apartment)temp=temp->next;
    temp->next=temp_apartment->next;
    delete(temp_apartment);


    //remove_apartment(apartment_name_2);
}


void list_apartments(){
    //cout<<endl;
    if(current == NULL)
      return;

   struct Apartments* temp_apartment = current;
    while(temp_apartment != NULL){

      //cout << temp_apartment->apartment_name << "(" << temp_apartment->max_bandwidth << ")" << "\t";
        printstr+=temp_apartment->apartment_name + "(" + to_string(temp_apartment->max_bandwidth) + ")" + "\t";
      struct Flats* temp_flats = temp_apartment->flats;

        while(temp_flats != NULL){
            printstr+="Flat" + to_string( temp_flats->flat_id) +  "(" + to_string( temp_flats->initial_bandwidth )+")" + "\t";
            //cout << "Flat" << temp_flats->flat_id << "(" << temp_flats->initial_bandwidth << ")" << "\t";
            temp_flats = temp_flats->next;
        }
        printstr+="\n";
      //cout << endl;
      temp_apartment = temp_apartment->next;
    }
    printstr+="\n";

    //cout<<endl;



}

 Flats* getFlat(int x){// taking out flat from the apartment list
      Apartments* temp_apartment = current;
      Flats* tempflat;
     while (temp_apartment!=NULL){
         tempflat=temp_apartment->flats;
         while (tempflat!=NULL){
             if(tempflat->flat_id==x){
                 temp_apartment->max_bandwidth-=tempflat->initial_bandwidth;
                 ////cout<<" burada patliyor 1 "<<endl;
                 if(tempflat->prev==NULL){
                     if(tempflat->next!=NULL){
                         tempflat->next->prev=NULL;
                     }
                     temp_apartment->flats=tempflat->next;
                     tempflat->next=NULL;
                     tempflat->prev=NULL;
                     return  tempflat;
                 }
                 tempflat->prev->next=tempflat->next;
                 if(tempflat->next!=NULL)
                 tempflat->next->prev=tempflat->prev;
                 tempflat->prev=NULL;
                 tempflat->next=NULL;
                // //cout<<" burada patlıyor 2 "<<endl;

                 return tempflat;
             }
             tempflat=tempflat->next;
         }
         temp_apartment=temp_apartment->next;
     }

     return NULL;
}
void Add_before_flat( string new_apartment_name, int flat_id_to_shift,Flats* add){
    struct Apartments *temp_apartment = current;

    if(temp_apartment == NULL)
        return;
    while(temp_apartment!=NULL){
        if(temp_apartment->apartment_name==new_apartment_name) break;
        temp_apartment=temp_apartment->next;
    }
    Flats* tempflat=temp_apartment->flats;
    while(tempflat!=NULL){
        if(tempflat->flat_id==flat_id_to_shift)break;
        tempflat=tempflat->next;
    }
    temp_apartment->max_bandwidth=temp_apartment->max_bandwidth+add->initial_bandwidth;
    if(tempflat==temp_apartment->flats){
        add->next=temp_apartment->flats;
        temp_apartment->flats->prev=add;
        temp_apartment->flats=add;
        return;
    }
    add->next=tempflat;
    add->prev=tempflat->prev;
    tempflat->prev->next=add;
    tempflat->prev=add;



}
void relocate_flats_to_same_apartment(string new_apartment_name, int flat_id_to_shift, vector<int> flat_id_list){
    // //cout << "new_apartment_name: " << new_apartment_name <<  " , " << "flat_id_to_shift: " << flat_id_to_shift << ", flat_id_list: ";
    // _print_vector_values(flat_id_list);
    Flats* tempflat;
    for (int i:flat_id_list) {
        tempflat=getFlat(i);
      //  //cout<<"temp flat id:"<<tempflat->flat_id<<endl;
        if(tempflat!=NULL){
            Add_before_flat(new_apartment_name,flat_id_to_shift,tempflat);
        }
    }
   //
   //
   //
   //
   // //cout << "relocaate " <<endl;
}


void selection_of_command(string command_name, vector<string> functions_arguments){
    ////cout<<command_name<<endl;
    for (int i = 0; i <functions_arguments.size() ; ++i) {
        //cout<<functions_arguments[i]+"\t";
    }
    //cout<<endl;
    if(command_name == "add_apartment"){
        string apartment_name = functions_arguments[0];
        string location = functions_arguments[1];
        int max_bandwidth = stoi(functions_arguments[2]);
        add_apartment(apartment_name, location, max_bandwidth);
    }
    else if(command_name == "add_flat"){
        string apartment_name = functions_arguments[0];
        int index = stoi(functions_arguments[1]);
        int initial_bandwidth = stoi(functions_arguments[2]);
        int flat_id = stoi(functions_arguments[3]);
        add_flat(apartment_name, index, initial_bandwidth, flat_id);
    }
    else if(command_name == "remove_apartment"){
        string apartment_name = functions_arguments[0];
        remove_apartment(apartment_name);
    }
    else if(command_name == "merge_two_apartments"){
        string apartment_name_1 = functions_arguments[0];
        string apartment_name_2 = functions_arguments[1];
        merge_two_apartments(apartment_name_1, apartment_name_2);
    }
    else if(command_name == "find_sum_of_max_bandwidths"){
        printstr+= "sum of bandwidth: " + to_string(find_sum_of_max_bandwidths()) + "\n\n";
        //cout << "sum of bandwidth: " << find_sum_of_max_bandwidths() << endl;
    }
    else if(command_name == "list_apartments"){
        list_apartments();
    }
    else if(command_name == "make_flat_empty"){
        string apartment_name = functions_arguments[0];
        int flat_id = stoi(functions_arguments[1]);
        make_flat_empty(apartment_name, flat_id);
    }
    else if(command_name == "relocate_flats_to_same_apartment"){
        string apartment_name = functions_arguments[0];
        int flat_id_to_shift = stoi(functions_arguments[1]);
        vector<int> flat_id_list = _string_to_vector_list(functions_arguments[2]);
        for (int x:flat_id_list){
            //cout<<x<<" ";
        }
        relocate_flats_to_same_apartment(apartment_name, flat_id_to_shift, flat_id_list);
    }
    else{
        //cout << "Unknown command written. Input file is wrong ! Command_name: " << command_name << endl;
    }
}


int main(int argc, char** argv)
{
    ifstream file(argv[1]);
    string str;
    int word_count = 0;
      ////cout<<"here"<<endl;

        while (getline(file, str)){
            stringstream ss(str);
        string word;
        string command_name = "";
        vector<string> functions_arguments;

        while (ss >> word) {
            if(word_count == 0)
                command_name = word;
            else
                functions_arguments.push_back(word);
            word_count++;
        }

            //cout<<endl;
        word_count = 0;
        try{
        selection_of_command(command_name, functions_arguments);
        }
        catch (exception e){

        }
           // list_apartments();

        }
        file.close();


    ofstream  of;
    of.open(argv[2]);
    if(!of.is_open()){
        //cout<<"Output file was not opened ";
    }
    else{
        of<<printstr;
    }
    of.close();
    return 0;
}