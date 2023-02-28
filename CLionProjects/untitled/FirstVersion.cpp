
//
// Created by Enc on 2.12.2022.
//
#ifndef FirstVersion_cpp
#define FirstVersion_cpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "CostumerQueue.cpp"
#include "cmp.cpp"
#include "cmpforid.cpp"

#include "CashierQueue.cpp"
#include "SecondVersion.cpp"
using std::string;
using std::cout;
using std::endl;
class  FirstVersion
{





public:
    string  printstr;
    int numberofCashier;
    void docommand(string basicString) {

    }
    std::vector<std::string> string_split(const std::string& str) {
        std::vector<std::string> result;
        std::istringstream iss(str);
        for (std::string s; iss >> s; )
            result.push_back(s);
        return result;
    }
    void read_InputFile(CostumerQueue *pQueue, CostumerQueue *pCostumerQueue, const string basicString) {
        std::ifstream read;
        std::vector<string> costvector;
       // read.open(R"(C:\Users\as_as\CLionProjects\untitled\input.txt)");
        read.open(basicString.c_str());

        if(!read.is_open()){
            cout<<"Input file was not found \n";
            return;
        }
        int index=0;
        string str="";
        while (std::getline(read,str)){
            if(index>1){
                costvector= string_split(str);
              //  cout<<"Cost vector element 1:"<<costvector.at(0)<<endl;
                pQueue->enqueue(std::stod(costvector.at(3)),std::stod(costvector.at(0)),std::stod(costvector.at(1)),std::stod(costvector.at(2)));
                pCostumerQueue->enqueue(std::stod(costvector.at(3)),std::stod(costvector.at(0)),std::stod(costvector.at(1)),std::stod(costvector.at(2)));

            }
            else if(index==1){

            }
            else {
                numberofCashier= std::stoi(str);
            }
            index++;
        }
    }

    int maxlengthofQueue=0;

    void secondtype(CostumerQueue *pQueue, int cashier) {
        maxlengthofQueue=0;
        int numberofemployer=pQueue->last->id+1;

        CashierQueue* cashierQueue=new CashierQueue;
        cashierQueue->createCashierQueue(cashier);
        //std::vector<CostumerQueue*> vectorx;
        CostumerQueue* newcostqueue;
        //cout<<"Come hereeeeee 0"<<endl;
        CashierNode* tempcash=cashierQueue->head;
        int x=0;
        while (tempcash!= nullptr){
            if(x%3==0)newcostqueue=new CostumerQueue;
            x++;
            tempcash->selfcostqueue=newcostqueue;
            tempcash=tempcash->next;
        }

      /*  for (int i = 0; i <cashier ; i+=3) {
            newcostqueue=new CostumerQueue;

            vectorx.push_back(newcostqueue);
            vectorx.push_back(newcostqueue);
            vectorx.push_back(newcostqueue);

        }
        */
        Go_to_Cashier(cashierQueue,pQueue);


        tempcash=cashierQueue->head;
         x=0;
         CostumerNode* costumerNode;
        auto* All_costumer_after_barista=new CostumerQueue;;
        auto* printvectorarray=new std::vector<std::vector<double>*>;
        std::vector<double>* printvector;
        while (tempcash!= nullptr){
            if(x%3==0){
                costumerNode=tempcash->selfcostqueue->head;
                sort_Queue(tempcash->selfcostqueue);

                printvector=new  std::vector<double>;
                printvectorarray->push_back(printvector);
                while (costumerNode!= nullptr){
                    //cout<<"Cashier name:"<<tempcash->name<<endl;
                    //cout<<costumerNode->outofcashier<<" Out of cash and id:"<<costumerNode->id<<endl;
                    costumerNode=costumerNode->next;
                }
                SecondVersion secondVersion(tempcash->selfcostqueue, 1, printvector,All_costumer_after_barista);


            }
            x++;
            tempcash=tempcash->next;
        }
        int lengthofemployee=4*cashier/3;
        double  totalrunningtime=0;

        for (auto & i : *printvectorarray) {

            if(i->at(i->size()-2)>totalrunningtime)totalrunningtime=i->at(i->size()-2);

        }
        printstr+= "\n"+Rounddouble(totalrunningtime)+"\n";
        printstr+= std::to_string(maxlengthofQueue)+"\n";
        for (auto & i : *printvectorarray){
            printstr+= std::to_string((int)i->at(i->size()-1))+"\n";
        }

        // Print Cashier queue
         tempcash=cashierQueue->head;
        while (tempcash!= nullptr){
            printstr+= Rounddouble(tempcash->sumofworktime/totalrunningtime)+"\n";
            tempcash=tempcash->next;
        }
        for (auto & i : *printvectorarray){
            printstr+= Rounddouble(i->at(0)/totalrunningtime)+"\n";
        }
        sort_Queueforincreaseid(All_costumer_after_barista);
        costumerNode=All_costumer_after_barista->head;
        while (costumerNode!= nullptr){
            printstr+= Rounddouble(costumerNode->outofbarista-costumerNode->arrivetime)+"\n";
            costumerNode=costumerNode->next;
        }
        // delete proccessing
        delete(&printvectorarray);
        delete(&All_costumer_after_barista);
        delete(&tempcash);
        delete(&cashierQueue);

    }


    void   Go_to_Cashier(CashierQueue* cashierQueue, CostumerQueue* costqueue)  {
    /*    CostumerNode* a=costqueue->head;
        while(a!= nullptr){
            cout<<"a id:"<<a->id<<endl;
            a=a->next;
        }
        */

       // CostumerQueue *All_after;

       // CostumerNode *temp1;
        CashierNode *bNode;
        CashierNode *ansnode;
        CostumerNode* costumerNode;
        CostumerNode* tempcostnode;
        while (!costqueue->isEmpty()) {

            costumerNode = costqueue->dequeue();

            bNode = cashierQueue->head;

            ansnode = bNode;
            double min = -1;

            while (bNode != nullptr) {
            //     cout<<"time of pre cost:"<<bNode->timeofprecostumer<< endl;
            //    cout<<"arrive time of costumerNode:"<<costumerNode->arrivetime<< endl;

                if(bNode->timeofprecostumer>costumerNode->arrivetime){
                if (bNode->timeofprecostumer < min || min == -1) {
                   // cout<<"time:"<<bNode->timeofprecostumer<<" id:"<< bNode->id <<endl;
                    min = bNode->sumofworktime;
                    ansnode = bNode;
                }
                }
                else{
                  //  cout<<"time:"<<bNode->timeofprecostumer<<endl;

                    ansnode = bNode;
                    break;
                }
                bNode = bNode->next;

            }
            bNode = ansnode;

            tempcostnode=costqueue->head;
            int max=0;
            if(costumerNode->arrivetime<bNode->timeofprecostumer)max++;
            while(tempcostnode!= nullptr){
                //   cout<<"Time of pre cost:"<<bNode->timeofprecostumer<<endl;
                //cout<< "temp cost arrive time:"<<tempcostnode->arrivetime<<endl;
                if(tempcostnode->arrivetime<bNode->timeofprecostumer){
                    max++;
                }


                tempcostnode=tempcostnode->next;
            }
            if(max>maxlengthofQueue)maxlengthofQueue=max;

            //cout<<"Heresad 1";
           // bNode.->enqueueNode(costumerNode);
            //  cout<<"costumerNode brew time:"<<costumerNode->brewtime<<endl;
            // cout<<"bNodesumofworktime:"<<bNode->sumofworktime<<endl;
            bNode->selfcostqueue->enqueueNode(costumerNode);
            bNode->sumofworktime += costumerNode->ordertime;
            costumerNode->setoutofCashier(bNode->timeofprecostumer - costumerNode->arrivetime);//find time while waiting in queue
            bNode->timeofprecostumer = costumerNode->outofcashier;

           // cout<<"name of Cashier:"<<bNode->name<<endl;
           // cout<<"***and its timeprocost***:"<<bNode->timeofprecostumer<<endl;

          //  cout<<"costumerNode Out of cashier:"<<costumerNode->outofcashier<<" Cost node id:"<<costumerNode->id<<endl;
           // cout<<"------arrive time------:"<<costumerNode->arrivetime<<" Cost node id:"<<costumerNode->id<<endl;

        }
    }

    void   Go_to_CashierForfirstmodel(CashierQueue* cashierQueue, CostumerQueue* costqueue,CostumerQueue* All_after)  {
        /*    CostumerNode* a=costqueue->head;
            while(a!= nullptr){
                cout<<"a id:"<<a->id<<endl;
                a=a->next;
            }
            */

        // CostumerQueue *All_after;

        // CostumerNode *temp1;
        CashierNode *bNode;
        CashierNode *ansnode;
        CostumerNode* costumerNode;
        CostumerNode* tempcostnode;

        while (!costqueue->isEmpty()) {
            costumerNode = costqueue->dequeue();

            bNode = cashierQueue->head;

            ansnode = bNode;
            double min = -1;


            while (bNode != nullptr) {
             //   cout<<"arrive time of costumerNode:"<<costumerNode->arrivetime<< endl;
                //     cout<<"time of pre cost:"<<bNode->timeofprecostumer<< endl;
                //    cout<<"arrive time of costumerNode:"<<costumerNode->arrivetime<< endl;

                if(bNode->timeofprecostumer>costumerNode->arrivetime){
                    if (bNode->timeofprecostumer < min || min == -1) {
                        // cout<<"time:"<<bNode->timeofprecostumer<<" id:"<< bNode->id <<endl;
                        min = bNode->sumofworktime;
                        ansnode = bNode;
                    }
                }
                else{
                    //  cout<<"time:"<<bNode->timeofprecostumer<<endl;

                    ansnode = bNode;
                    break;
                }
                bNode = bNode->next;

            }
            bNode = ansnode;
            // cout<<"Barista that is free:"<<ansnode->name<<std::endl;
            tempcostnode=costqueue->head;
            int max=0;
            if(costumerNode->arrivetime<bNode->timeofprecostumer)max++;
            while(tempcostnode!= nullptr){
                if(tempcostnode->arrivetime<bNode->timeofprecostumer){
                    max++;}

                tempcostnode=tempcostnode->next;
            }
            if(max>maxlengthofQueue)maxlengthofQueue=max;

            All_after->enqueueNode(costumerNode);
            bNode->sumofworktime += costumerNode->ordertime;
            costumerNode->setoutofCashier(bNode->timeofprecostumer - costumerNode->arrivetime);//find time while waiting in queue
            bNode->timeofprecostumer = costumerNode->outofcashier;

            //cout<<"Heresad 1";
            // bNode.->enqueueNode(costumerNode);
            //  cout<<"costumerNode brew time:"<<costumerNode->brewtime<<endl;
            // cout<<"bNodesumofworktime:"<<bNode->sumofworktime<<endl;
            // cout<<"name of Cashier:"<<bNode->name<<endl;
            // cout<<"***and its timeprocost***:"<<bNode->timeofprecostumer<<endl;

            //  cout<<"costumerNode Out of cashier:"<<costumerNode->outofcashier<<" Cost node id:"<<costumerNode->id<<endl;
            // cout<<"------arrive time------:"<<costumerNode->arrivetime<<" Cost node id:"<<costumerNode->id<<endl;

        }
    }

    void CreateOutputFile(const string& basicString,const string& outputname) {
        std::ofstream of;
      //  of.open(R"(C:\Users\as_as\CLionProjects\untitled\)"+outputname);
          of.open(outputname.c_str());
        if(of.is_open())
        of<<basicString;
        else cout<<"There is a error while opening output file";
        of.close();
    }

    void firsttype(const string& inputname,const string& outputname)
    {
        auto* All_Costumer_AfterCashiers=new CostumerQueue;
        CostumerQueue costumerque;
        CostumerQueue costumerqueforsec;

        read_InputFile(&costumerque, &costumerqueforsec, inputname);
        int numberofBarista=numberofCashier/3;
        auto* cashierQueue=new CashierQueue;
        cashierQueue->createCashierQueue(numberofCashier);


       // cout<<costumerque.toString();




       // cout<<"\nPrint Cashier queue at first:\n"+cashierQueue->toString();

          cout<<""+costumerque .toStringforarrivetime();
      //  cout<<"\nPrint  Costumer queue for order time:\n"+costumerque.toStringforOrderTime()+"\n";



        Go_to_CashierForfirstmodel(cashierQueue,&costumerque,All_Costumer_AfterCashiers);
      //  cout<<"here \n";

        auto* printvector=new std::vector<double>;
       //Print Cashier queue sum of work time
        CashierNode* temp1=cashierQueue->head;
        while(temp1!= nullptr){
            printvector->push_back(temp1->sumofworktime);
            temp1=temp1->next;
        }

        sort_Queue(All_Costumer_AfterCashiers);

       auto* All_costumer_after_barista=new CostumerQueue;
        // Go to second version
      //  cout<<"Here blow out \n";
        SecondVersion secondVersion(All_Costumer_AfterCashiers, numberofBarista, printvector,All_costumer_after_barista);


        printstr+= (Rounddouble(printvector->at(printvector->size()-2)))+"\n";
        printstr+= std::to_string(maxlengthofQueue)+"\n";
        printstr+= std::to_string((int)printvector->at(printvector->size()-1))+"\n";

        double  runingtime=printvector->at(printvector->size()-2);
        for (int i = 0; i <printvector->size()-2 ; ++i) {
            if(i<(4*numberofCashier/3))
            printstr+= (Rounddouble(printvector->at(i)/runingtime))+"\n";

               // printstr+= (Rounddouble(printvector->at(i)))+"\n";
        }
        sort_Queueforincreaseid(All_costumer_after_barista);


         CostumerNode* tempcost=All_costumer_after_barista->head;
          while (tempcost!= nullptr){
              printstr+= (Rounddouble(tempcost->outofbarista-tempcost->arrivetime)+"\n");
              tempcost=tempcost->next;

          }
    //   cout<<printstr<<endl;

         delete(&tempcost);
        delete(&printvector);
        delete(&costumerque);
        delete(&cashierQueue);
        delete(&All_Costumer_AfterCashiers);
        delete(&All_costumer_after_barista);
        secondtype(&costumerqueforsec,numberofCashier);
        cout<<printstr<<endl;
        CreateOutputFile(printstr,outputname);


    }



    std::string result;
    int integerValue;
    int decimal,y,value;
    int factor=1000;

    string Rounddouble ( double a)
    {

       //  y=a*1000;

        value=a*1000;
        integerValue= (value / factor) * factor; //(56890 / 1000) * 1000 = 56000
        decimal = value - integerValue;  // 56890 - 56000=890;
        if(decimal%10>=5)decimal+=10;
        decimal-=decimal%10;

        result = std::to_string((int)(value/factor)) + "." + std::to_string(decimal/10);
        return result;
        // result = "56" + "." + "89"
        // lastly, print result
    }
    static void sort_Queue(CostumerQueue* queue) {//sorting que up to outofCashier

        std::vector<CostumerNode*> vectorofCN;
        CostumerNode* temp=queue->head;


        //   cout<<temp->outofcashier<<endl;

        while (temp!= nullptr){
            // cout<<temp->outofcashier<<endl;
            vectorofCN.push_back(queue->dequeue());
            temp=queue->head;
        }
   //     queue->dequeue();

        sort(vectorofCN.begin(),vectorofCN.end(),cmp());

        for(int i = 0; i < vectorofCN.size(); i++)
        {  queue->enqueueNode(vectorofCN[i]);
          //  cout<<vectorofCN[i]->outofcashier<<" id: "<<vectorofCN[i]->id <<endl;
        }

       // cout<<"\ntry place \n";

    }
    static void sort_Queueforincreaseid(CostumerQueue* queue) {//sorting que up to outofCashier

        std::vector<CostumerNode*> vectorofCN;
        CostumerNode* temp=queue->head;


        //   cout<<temp->outofcashier<<endl;

        while (temp!= nullptr){
            // cout<<temp->outofcashier<<endl;
            vectorofCN.push_back(queue->dequeue());
            temp=queue->head;
        }
       // queue->dequeue();

        sort(vectorofCN.begin(),vectorofCN.end(),cmpforid());

        for(int i = 0; i < vectorofCN.size(); i++)
        {  queue->enqueueNode(vectorofCN[i]);
            //  cout<<vectorofCN[i]->outofcashier<<" id: "<<vectorofCN[i]->id <<endl;
        }

        // cout<<"\ntry place \n";


    }


};
#endif
// Full_FillCashiersNodes( cashierQueue,costumerque);
// recursive fullfill

//  CostumerQueue All_Costumer_AfterCashiers;
// recursive_fullfill(cashierQueue,&costumerque,All_Costumer_AfterCashiers);

//cout<<"cashierQueue get node"<<cashierQueue.getNode()->name<<endl;

/*
 *
 *
 *  void recursive_fullfill(CashierQueue* queue, CostumerQueue* costumerQueue, CostumerQueue* All_after) {

        node* n=queue->getNode();
        if(n== nullptr)return;
        CostumerNode* costumerNode=costumerQueue->dequeue();
        if(costumerNode== nullptr) return ;
         cout<<"Cost node : "<<costumerNode->id<< endl;

        //cout<<"Recursive fullfill is working \n";

        queue->skiptimeforinitial(costumerNode->arrivetime-queue->prevnodearrivetime);
        queue->prevnodearrivetime=costumerNode->arrivetime;
        costumerNode->setoutofCashier(n->timeofprecostumer- costumerNode->arrivetime);

        All_after->enqueueNode(costumerNode);

        n->timeofprecostumer=costumerNode->outofcashier;
        n->isworking= true;
        n->setwork(costumerNode->ordertime);

        recursive_fullfill(queue,costumerQueue,All_after);

    }
    void recursive_Continious(CashierQueue queue, CostumerQueue costumerQueue, CostumerQueue All_after){


    }
    double mintimeofcashier;
    node* cnode;
    CostumerNode* costnode;
 *     void processingCashierQueue( CostumerQueue* queue, CashierQueue* cashierQueue, CostumerQueue* all_aftercash) {

        mintimeofcashier=cashierQueue->findmintime();

     //   cout<<"Cost node : "<<costnode->id<< endl;
        //cout<<"\nMin time of Cashier:"+ to_string(mintimeofcashier)<<endl;

        if(queue->isEmpty())return;

        cnode=cashierQueue->skiptime(mintimeofcashier);
        int max=0;
        CostumerNode* temp=queue->head;
        while (temp!= nullptr){
            if(temp->arrivetime<=cnode->timeofprecostumer){
                max++;
                temp=temp->next;

            }
            else break;
        }
        costnode=queue->dequeue();
        if(max>maxlengthofQueue)maxlengthofQueue=max;
        //  cout<<"\nProcc while 2\n";

        all_aftercash->enqueueNode(costnode);
        // cout<<"\nProcc while 2\n";
        //cout<<"\nCostnode order time "+ to_string(costnode->ordertime) +"\n";
       // cout<<"\ncnode->timeofprecostumer time of Cashier "+ std::to_string(cnode->timeofprecostumer) +"\n";
        // if(cnode== nullptr)cout<<"cNode Nullptr\n";
        cnode->setwork(costnode->ordertime);
        //cout<<"\nProcc while 2\n";

        costnode->setoutofCashier(cnode->timeofprecostumer-costnode->arrivetime);
        cnode->timeofprecostumer=costnode->outofcashier;

        processingCashierQueue(queue,cashierQueue,all_aftercash);
        //sort_Queue(all_aftercash);

    }
    void Full_FillCashiersNodes(CashierQueue queue,CostumerQueue costumerQueue ){
        //typedef node CashierNode;
        node* Chead=queue.head;
        CostumerNode* costumerNode;
        CostumerQueue All_Costumer_AfterCashiers;
        int arrivetime;
        while(Chead!= nullptr&&!costumerQueue.isEmpty()){
            //cout<<"\nCounting while\n";
            costumerNode=costumerQueue.dequeue();

            Chead->isworking= true;
            Chead->setwork(costumerNode->ordertime);

            costumerNode->setoutofCashier(0);
            Chead->timeofprecostumer=costumerNode->outofcashier;

            All_Costumer_AfterCashiers.enqueueNode(costumerNode);
            // arrivetime=costumerNode->arrivetime;
            Chead=Chead->next;
        }
        //  recursive_fullfill(queue,costumerQueue,All_Costumer_AfterCashiers);
        // cout<<"Chead node:"<<Chead->isworking<<endl;
        if(Chead== nullptr&&!costumerQueue.isEmpty()){
            //     cout<<"\nCounting while 2\n";

            processingCashierQueue( &costumerQueue, &queue, &All_Costumer_AfterCashiers);
            //cout<<"\nCounting while 2\n";

        }
        //  cout<<"\ntry place size of All_Costumer_AfterCashiers:"<<All_Costumer_AfterCashiers.dequeue()->outofcashier<<endl;

        sort_Queue(&All_Costumer_AfterCashiers);

    }
 *
 *
 * if(cashierQueue->getNode()== nullptr&&!costumerque.isEmpty()){
       //     cout<<"\nCounting while 2\n";

       processingCashierQueue( &costumerque, cashierQueue, All_Costumer_AfterCashiers);
       //cout<<"\nCounting while 2\n";

   }

       double Rounddoublea(double x){
       // double y=0.48545;
        int z= int(double(x*100+0.5));
        return (double( z)/100);
    }




   */
//  cout<<"\nCounting while 2\n"<<All_Costumer_AfterCashiers;
